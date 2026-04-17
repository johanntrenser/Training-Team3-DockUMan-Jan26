/*
 * File: ShipService.cpp
 * Description: Implements ship-related business logic including registration,
 *              status tracking, arrival/departure recording, and ship detail updates.
 * Author: Entire Team
 * Created: 02-Apr-2026
 */

#include "ShipService.h"
/*
 * Function: getShipID
 * Description: Retrieves the ship associated with the current ship manager from the datastore.
 * Parameters:
 *    None
 * Returns:
 *    Pointer to the current Ship object
 */
Ship* ShipService::getShipID()
{
	Ship* currentShip = m_dataStore.getshipByShipManager();
	return currentShip;
}
/*
 * Function: registerShip
 * Description: Registers a new ship using provided information and agent details.
 * Parameters:
 *    shipInformation - vector containing ship details
 *    isAvailable - initial availability status of the ship
 *    status - initial ship status
 *    agent - pointer to the user acting as ship manager
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
Enums::ProcessStatus ShipService::registerShip(std::vector<std::string>& shipInformation, Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status, User* agent)
{
	Enums::ProcessStatus shipRegisterProcessStatus = registerShipObject(shipInformation, agent, isAvailable, status);
	if ((agent != nullptr) && (shipRegisterProcessStatus == Enums::ProcessStatus::SUCCESS))
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}
/*
 * Function: registerShipObject
 * Description: Creates a new Ship object using provided details and adds it to the datastore.
 * Parameters:
 *    shipInformation - vector containing ship details
 *    agent - pointer to the user acting as ship manager
 *    isAvailable - initial availability status of the ship
 *    status - initial ship status
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
Enums::ProcessStatus ShipService::registerShipObject(std::vector<std::string>& shipInformation,User* agent,Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status)
{
	std::string  id, name, ETA, ETD;
	Dock* assignedDock;
	std::vector<Container*> containers;
	std::vector<std::string>::iterator iterator = shipInformation.begin();
	id = *iterator++;
	name = *iterator;
	Ship* ship = Factory::getObject<Ship>(id, name, containers, agent, ETA, ETD, assignedDock, status, isAvailable);
	if ((m_dataStore.addShip(ship)))
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}
/*
 * Function: getShipList
 * Description: Retrieves a list of active ships from the datastore.
 * Parameters:
 *    None
 * Returns:
 *    Vector of ship details as strings
 */
std::vector<std::string> ShipService::getShipList()
{
	std::vector<std::string> shipList;
	const std::vector<Ship*>& ships = m_dataStore.getShips();
	for (std::vector<Ship*>::const_iterator iterator = ships.begin(); iterator != ships.end(); ++iterator)
	{
		if ((*iterator)->getShipStatus() == Enums::ShipStatus::ACTIVE)
		{
			shipList.push_back((*iterator)->toString());
		}
	}
	return shipList;
}
/*
 * Function: trackShipStatus
 * Description: Retrieves the availability status of a ship by its ID.
 * Parameters:
 *    shipId - ID of the ship
 *    shipStatus - output string containing the ship's status
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
Enums::ProcessStatus ShipService::trackShipStatus(std::string& shipId,std::string& shipStatus)
{
	Ship* ship = m_dataStore.getShipById(shipId);
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
/*
 * Function: sendShipArrivalRequest
 * Description: Sends an arrival request for the current ship, records its arrival,
 *              marks it as waiting, and adds it to the waiting queue.
 * Parameters:
 *    None
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
Enums::ProcessStatus ShipService::sendShipArrivalRequest()
{
	Ship* currentShip = m_dataStore.getshipByShipManager();
	if (recordShipArrival(currentShip) == Enums::ProcessStatus::SUCCESS)
	{
		//if(!checkDockAvailability) dock next ship in waiting queue
		currentShip->setAvailabilityStatus(Enums::AvailabilityStatus::WAITING);
		m_dataStore.addShipToWaitingQueue(currentShip);
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}
/*
 * Function: sendShipDepartureRequest
 * Description: Sends a departure request for the current ship if docked, records its departure,
 *              removes it from the waiting queue, and clears dock assignment.
 * Parameters:
 *    None
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
Enums::ProcessStatus ShipService::sendShipDepartureRequest()
{
	Ship* currentShip = getShipID();
	if (currentShip->getAvailabilityStatus() == Enums::AvailabilityStatus::DOCKED)
	{
		if (recordShipDeparture(currentShip) == Enums::ProcessStatus::SUCCESS)
		{
			m_dataStore.removeShipFromWaitingQueue();
			currentShip->setAssignedDock(nullptr);
			//dock next ship in waiting queue
			return Enums::ProcessStatus::SUCCESS;
		}
		else
		{
			return Enums::ProcessStatus::FAILED;
		}
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}
/*
 * Function: recordShipArrival
 * Description: Records the arrival time (ETA) of the current ship and updates its availability status to WAITING.
 * Parameters:
 *    currentShip - pointer to the ship object
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
Enums::ProcessStatus ShipService::recordShipArrival(Ship* currentShip)
{
	std::string timestampString;
	if (currentShip == nullptr)
	{
		return Enums::ProcessStatus::FAILED;
	}
	util::Timestamp timestamp;
	timestampString = timestamp.toString();
	currentShip->setETA(timestampString);
	currentShip->setAvailabilityStatus(Enums::AvailabilityStatus::WAITING);
	return Enums::ProcessStatus::SUCCESS;
}
/*
 * Function: recordShipDeparture
 * Description: Records the departure time (ETD) of the current ship and updates its availability status to DEPARTED.
 * Parameters:
 *    currentShip - pointer to the ship object
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
Enums::ProcessStatus ShipService::recordShipDeparture(Ship* currentShip)
{
	std::string timestampString;
	if (currentShip == nullptr)
	{
		return Enums::ProcessStatus::FAILED;
	}
	util::Timestamp timestamp;
	timestampString = timestamp.toString();
	currentShip->setETD(timestampString);
	currentShip->setAvailabilityStatus(Enums::AvailabilityStatus::DEPARTED);
	return Enums::ProcessStatus::SUCCESS;
}
/*
 * Function: updateShipAvailabilityStatus
 * Description: Updates the availability status of a ship.
 * Parameters:
 *    shipId - ID of the ship
 *    newStatus - new availability status
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
Enums::ProcessStatus ShipService::updateShipAvailabilityStatus(std::string& shipId, Enums::AvailabilityStatus newStatus)
{
	Ship* ship = m_dataStore.getShipById(shipId);
	if (ship == nullptr)
	{
		return Enums::ProcessStatus::FAILED;
	}
	ship->setAvailabilityStatus(newStatus);
	return Enums::ProcessStatus::SUCCESS;
}
/*
 * Function: updateShipName
 * Description: Updates the name of a ship.
 * Parameters:
 *    shipId - ID of the ship
 *    newShipName - new name for the ship
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
Enums::ProcessStatus ShipService::updateShipName(std::string& shipId, const std::string& newShipName)
{
	Ship* ship = m_dataStore.getShipById(shipId);
	if (!ship)
	{
		return Enums::ProcessStatus::FAILED;
	}
	ship->setShipName(newShipName);
	return Enums::ProcessStatus::SUCCESS;
}

<<<<<<< HEAD
/*
 * Function: updateShipDock
 * Description: Updates the dock assignment of a ship.
 * Parameters:
 *    shipId - ID of the ship
 *    newDock - ID of the new dock
 * Returns:
 *    Process status (SUCCESS or FAILED)
 */
=======
>>>>>>> 938ec602b4610bd3cf0e3c07be5a4021d9d4444d
Enums::ProcessStatus ShipService::updateShipDock(std::string& shipId, const std::string& newDock)
{
	Ship* ship = m_dataStore.getShipById(shipId);
	Dock* dock = m_dataStore.getDockById(newDock);
	if (!ship)
	{
		return Enums::ProcessStatus::FAILED;
	}
	if (!dock)
	{
		return Enums::ProcessStatus::FAILED;
	}
	ship->setAssignedDock(dock);
	return Enums::ProcessStatus::SUCCESS;
}
