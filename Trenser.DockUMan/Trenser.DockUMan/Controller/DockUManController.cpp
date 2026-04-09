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

/*
 * Function: getUserDetailByIdAndType
 * Description: Retrieves user details by ID and role
 * Parameters:
 *    userId - ID of the user
 *    role - user role
 * Returns:
 *    Vector of user details
 */
std::vector<std::string> DockUManController::getUserDetailByIdAndType(std::string& userId, Enums::UserTypes role)
{
	return m_userService->getUserDetailByIdAndType(userId, role);
}

/*
 * Function: logoutUser
 * Description: Logs out the current user
 */
void DockUManController::logoutUser()
{
	m_userService->logoutUser();
}

/*
 * Function: getUserList
 * Description: Retrieves list of all users
 * Returns:
 *    Vector of user details
 */
std::vector<std::string> DockUManController::getUserList()
{
	std::vector<std::string> userList;
	userList = m_userService->getUserList();
	return userList;
}

/*
 * Function: addUser
 * Description: Adds a new user
 * Parameters:
 *    userInformation - vector containing user details
 *    type - user type
 *    status - user status
 * Returns:
 *    Process status
 */
Enums::ProcessStatus DockUManController::addUser(std::vector<std::string>& userInformation, Enums::UserTypes type, Enums::UserStatus status)
{
	return m_userService->addUser(userInformation, type, status);
}

/*
 * Function: IsEmailIdUnique
 * Description: Checks if email ID is unique
 * Parameters:
 *    email - email to validate
 * Returns:
 *    Process status
 */
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

/*
 * Function: IsPhoneNumberUnique
 * Description: Checks if phone number is unique
 * Parameters:
 *    phoneNumber - phone number to validate
 * Returns:
 *    Process status
 */
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

/*
 * Function: IsLicenseNumberUnique
 * Description: Checks if license number is unique
 * Parameters:
 *    licenseNumber - license number to validate
 * Returns:
 *    Process status
 */
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

/*
 * Function: getUserListByRole
 * Description: Retrieves users filtered by role
 * Parameters:
 *    role - user role
 * Returns:
 *    Vector of users
 */
std::vector<std::string> DockUManController::getUserListByRole(Enums::UserTypes role)
{
	return m_userService->getUserListByRole(role);
}

/*
 * Function: updatedUserPhoneNumber
 * Description: Updates user's phone number
 * Parameters:
 *    userId - ID of the user
 *    updatedPhoneNumber - new phone number
 * Returns:
 *    Process status
 */
Enums::ProcessStatus DockUManController::updatedUserPhoneNumber(std::string& userId, std::string& updatedPhoneNumber)
{
	return m_userService->updatedUserPhoneNumber(userId, updatedPhoneNumber);
}

/*
 * Function: updatedUserEmailId
 * Description: Updates user's email ID
 * Parameters:
 *    userId - ID of the user
 *    updatedEmailId - new email ID
 * Returns:
 *    Process status
 */
Enums::ProcessStatus DockUManController::updatedUserEmailId(std::string& userId, std::string& updatedEmailId)
{
	return m_userService->updatedUserEmailId(userId, updatedEmailId);
}

/*
 * Function: deactivateUser
 * Description: Deactivates a user account
 * Parameters:
 *    userId - ID of the user
 * Returns:
 *    Process status
 */
Enums::ProcessStatus DockUManController::deactivateUser(std::string& userId)
{
	return m_userService->changeUserStatus(userId, Enums::UserStatus::INACTIVE);
}

/*
 * Function: changeCurrentUserPassword
 * Description: Changes password of the currently logged-in user
 * Parameters:
 *    password - new password
 * Returns:
 *    Process status
 */
Enums::ProcessStatus DockUManController::changeCurrentUserPassword(std::string& password)
{
	return m_userService->changeCurrentUserPassword(password);
}

/*
 * Function: approveUser
 * Description: Approves a user account
 * Parameters:
 *    userId - ID of the user
 * Returns:
 *    Process status
 */
Enums::ProcessStatus DockUManController::approveUser(std::string& userId)
{
	return m_userService->changeUserStatus(userId, Enums::UserStatus::ACTIVE);
}

/*
 * Function: IsBadgeNumberUnique
 * Description: Checks if badge number is unique
 * Parameters:
 *    badgeNumber - badge number to validate
 * Returns:
 *    Process status
 */
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
