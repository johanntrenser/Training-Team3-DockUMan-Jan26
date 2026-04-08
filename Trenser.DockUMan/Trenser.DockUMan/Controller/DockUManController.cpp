#include "DockUManController.h"

Enums::ProcessStatus DockUManController::registerShippingAgent(std::vector<std::string>& userInformation, Enums::UserTypes type, Enums::UserStatus status)
{
	Enums::ProcessStatus processStatus = m_userService->registerUser(userInformation, type, status); 
	return processStatus;
}

Enums::ProcessStatus DockUManController::handleAuthentication(std::string& email, std::string& password, std::string& username)
{
	Enums::ProcessStatus processStatus = m_userService->authenticateUser(email, password, username);
	return processStatus;
}

Enums::UserTypes DockUManController::getUserType(std::string& username)
{
	return m_userService->getUserType(username);
}

std::vector<std::string> DockUManController::getUserDetailByIdAndType(std::string& userId, Enums::UserTypes role)
{
	return m_userService->getUserDetailByIdAndType(userId, role);
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

Enums::ProcessStatus DockUManController::addUser(std::vector<std::string>& userInformation, Enums::UserTypes type, Enums::UserStatus status)
{
	return m_userService->addUser(userInformation, type, status);
}

Enums::ProcessStatus DockUManController::IsEmailIdUnique(std::string& email)
{
	if (m_userService->IsEmailIdUnique(email))
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}

Enums::ProcessStatus DockUManController::IsPhoneNumberUnique(std::string& phoneNumber)
{
	if (m_userService->IsPhoneNumberUnique(phoneNumber))
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}

Enums::ProcessStatus DockUManController::IsLicenseNumberUnique(std::string& licenseNumber)
{
	if (m_userService->IsLicenseNumberUnique(licenseNumber))
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}

std::vector<std::string> DockUManController::getUserListByRole(Enums::UserTypes role)
{
	return m_userService->getUserListByRole(role);
}

Enums::ProcessStatus DockUManController::updatedUserPhoneNumber(std::string& userId, std::string& updatedPhoneNumber)
{
	return m_userService->updatedUserPhoneNumber(userId, updatedPhoneNumber);
}

Enums::ProcessStatus DockUManController::updatedUserEmailId(std::string& userId, std::string& updatedEmailId)
{
	return m_userService->updatedUserEmailId(userId, updatedEmailId);
}

Enums::ProcessStatus DockUManController::deactivateUser(std::string& userId)
{
	return m_userService->changeUserStatus(userId, Enums::UserStatus::INACTIVE);
}

Enums::ProcessStatus DockUManController::changeCurrentUserPassword(std::string& password)
{
	return m_userService->changeCurrentUserPassword(password);
}

Enums::ProcessStatus DockUManController::approveUser(std::string& userId)
{
	return m_userService->changeUserStatus(userId, Enums::UserStatus::ACTIVE);
}
Enums::ProcessStatus DockUManController::IsBadgeNumberUnique(std::string& badgeNumber)
{
	if (m_userService->IsBadgeNumberUnique(badgeNumber))
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}