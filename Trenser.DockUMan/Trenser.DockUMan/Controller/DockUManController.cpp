#include "DockUManController.h"

Enums::ProcessStatus DockUManController::registerShippingAgent(std::vector<std::string>& userInformation, Enums::UserTypes& type, Enums::UserStatus& status)
{
	Enums::ProcessStatus processStatus=m_userService->registerUser(userInformation, type, status);
	return processStatus;
}

Enums::ProcessStatus DockUManController::handleAuthentication(std::string& username, std::string& password)
{
	Enums::ProcessStatus processStatus = m_userService->authenticateUser(username, password);
	return processStatus;
}

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
