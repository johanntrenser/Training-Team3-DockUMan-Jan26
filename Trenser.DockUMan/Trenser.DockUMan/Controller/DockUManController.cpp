/*
 * File: DockUManController.cpp
 * Description: Acts as an intermediary between the UI and service layers
 * Author: Entire Team
 * Created: 30-Mar-2026
 */
#include "DockUManController.h"

/*
  * Function: registerShippingAgent
  * Description: Registers a new shipping agent
  * Parameters:
  *    userInformation - vector containing user details
  *    type - user type
  *    status - user status
  * Returns:
  *    Process status
  */
Enums::ProcessStatus DockUManController::registerShippingAgent(std::vector<std::string>& userInformation, Enums::UserTypes type, Enums::UserStatus status)
{
	Enums::ProcessStatus processStatus = m_userService->registerUser(userInformation, type, status);
	return processStatus;
}

/*
 * Function: handleAuthentication
 * Description: Authenticates a user using email and password
 * Parameters:
 *    email - user email
 *    password - user password
 *    username - stores authenticated username
 * Returns:
 *    Process status
 */
Enums::ProcessStatus DockUManController::handleAuthentication(std::string& email, std::string& password, std::string& username)
{
	Enums::ProcessStatus processStatus = m_userService->authenticateUser(email, password, username);
	return processStatus;
}

/*
 * Function: getUserType
 * Description: Retrieves user type based on username
 * Parameters:
 *    username - user identifier
 * Returns:
 *    User type
 */
Enums::UserTypes DockUManController::getUserType(std::string& username)
{
	return m_userService->getUserType(username);
}

void DockUManController::logoutUser()
{
	m_userService->logoutUser();
}

std::vector<std::string> DockUManController::getUserList()
{
	std::vector<std::string> userList;
	userList = m_userService->getUserList();
	return userList;
}

std::vector<std::string> DockUManController::getShipList()
{
	std::vector<std::string> shipList;
	shipList=m_shipService->getShipList();
	return shipList;
}

Enums::ProcessStatus DockUManController::deactivateUser(std::string& userID)
{
	return m_userService->deactivateUser(userID);
}

Enums::ProcessStatus DockUManController::changeCurrentUserPassword(std::string& password)
{
	return m_userService->changeCurrentUserPassword(password);
}


Enums::ProcessStatus DockUManController::registerShip(std::vector<std::string>& userInformation, std::vector<std::string>& shipInformation, Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status)
{
	Enums::ProcessStatus processStatus = m_shipService->registerShip(shipInformation, isAvailable, status, m_userService->registerShipManger(userInformation));
	return processStatus;
}

Enums::ProcessStatus DockUManController::trackShipStatus(std::string& shipId,std::string& shipStatus)
{
	Enums::ProcessStatus status = m_shipService->trackShipStatus(shipId, shipStatus);
	return status;
}

Enums::ProcessStatus DockUManController::recordShipArrival(std::string& shipId)
{
	Enums::ProcessStatus status = m_shipService->recordShipArrival(shipId);
	return status;
}

Enums::ProcessStatus DockUManController::recordShipDeparture(std::string& shipId)
{
	Enums::ProcessStatus status = m_shipService->recordShipDeparture(shipId);
	return status;
}
