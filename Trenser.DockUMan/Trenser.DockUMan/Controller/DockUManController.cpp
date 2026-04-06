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
