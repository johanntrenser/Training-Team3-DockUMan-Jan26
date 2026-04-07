#include "ShipService.h"

Enums::ProcessStatus ShipService::registerShip(std::vector<std::string>& shipInformation, Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status, std::shared_ptr<User> agent)
{
	Enums::ProcessStatus shipRegisterProcessStatus = registerShipObject(shipInformation, agent, isAvailable, status);
	if ((m_dataStore.addUser(agent)) && (shipRegisterProcessStatus == Enums::ProcessStatus::SUCCESS))
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}

Enums::ProcessStatus ShipService::registerShipObject(std::vector<std::string>& shipInformation,std::shared_ptr<User> agent,Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status)
{
	std::string  id, name, ETA, ETD;
	std::shared_ptr<Dock> assignedDock;
	std::vector<std::shared_ptr<Container>> containers;
	std::vector<std::string>::iterator iterator = shipInformation.begin();
	id = *iterator++;
	name = *iterator;
	std::shared_ptr<Ship> ship = Factory::getObject<Ship>(id, name, containers, agent, ETA, ETD, assignedDock, status, isAvailable);
	if ((m_dataStore.addShip(ship)))
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}

std::vector<std::string> ShipService::getShipList()
{
	std::vector<std::string> shipList;
	const std::vector<std::shared_ptr<Ship>>& ships = m_dataStore.getShips();
	for (std::vector<std::shared_ptr<Ship>>::const_iterator iterator = ships.begin(); iterator != ships.end(); ++iterator)
	{
		if ((*iterator)->getShipStatus() == Enums::ShipStatus::ACTIVE)
		{
			shipList.push_back((*iterator)->toString());
		}
	}
	return shipList;
}