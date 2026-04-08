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

Enums::ProcessStatus ShipService::trackShipStatus(std::string& shipId,std::string& shipStatus)
{
	std::shared_ptr<Ship>ship=m_dataStore.getShipById(shipId);
	if (ship == nullptr)
	{
		return Enums::ProcessStatus::FAILED;
	}
	shipStatus = Enums::trackShipStatus(ship->getAvailabilityStatus());
	if (shipStatus == "Not Available")
	{
		return Enums::ProcessStatus::FAILED;
	}
	else
	{
		return Enums::ProcessStatus::SUCCESS;
	}
}

Enums::ProcessStatus ShipService::recordShipArrival(std::string& shipId)
{
	std::string timestampString;
	std::shared_ptr<Ship>ship = m_dataStore.getShipById(shipId);
	if (ship == nullptr)
	{
		return Enums::ProcessStatus::FAILED;
	}
	util::Timestamp timestamp;
	timestampString = timestamp.toString();
	ship->setETA(timestampString);
	ship->setAvailabilityStatus(Enums::AvailabilityStatus::ARRIVED);
	return Enums::ProcessStatus::SUCCESS;
}

Enums::ProcessStatus ShipService::recordShipDeparture(std::string& shipId)
{
	std::string timestampString;
	std::shared_ptr<Ship>ship = m_dataStore.getShipById(shipId);
	if (ship == nullptr)
	{
		return Enums::ProcessStatus::FAILED;
	}
	util::Timestamp timestamp;
	timestampString = timestamp.toString();
	ship->setETD(timestampString);
	ship->setAvailabilityStatus(Enums::AvailabilityStatus::DEPARTED);
	return Enums::ProcessStatus::SUCCESS;
}
