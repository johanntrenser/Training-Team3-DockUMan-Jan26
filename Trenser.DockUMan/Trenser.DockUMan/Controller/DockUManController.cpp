#include "DockUManController.h"

Enums::ProcessStatus DockUManController::registerShippingAgent(std::vector<std::string>& userInformation, Enums::UserTypes& type, Enums::UserStatus& status)
{
	Enums::ProcessStatus processStatus=m_userService->registerShippingAgent(userInformation, type, status);
	return processStatus;
}
