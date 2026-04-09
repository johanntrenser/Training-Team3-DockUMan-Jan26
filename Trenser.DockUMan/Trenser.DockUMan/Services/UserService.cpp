/*
 * File: UserService.cpp
 * Description: Handles user-related business logic including registration, 
				authentication, validation, and user management operations
 * Author: Entire Team
 * Created: 02-Apr-2026
 */
#include "UserService.h"

 /*
  * Function: registerUser
  * Description: Registers a new user based on user type and provided information
  * Parameters:
  *    userInformation - vector containing user details
  *    type - user type
  *    status - user status
  * Returns:
  *    Process status indicating success or failure
  */
Enums::ProcessStatus UserService::registerUser(std::vector<std::string>& userInformation, Enums::UserTypes type, Enums::UserStatus status)
{
	if (type == Enums::UserTypes::SHIPPING_AGENT)
	{
		std::string licenseNumber, id, name, password, email, phoneNumber;
		std::vector<std::string>::iterator iterator = userInformation.begin();
		id = *iterator++;
		name = *iterator++;
		password = *iterator++;
		email = *iterator++;
		phoneNumber = *iterator++;
		licenseNumber = *iterator;
		std::shared_ptr<User> agent = Factory::getObject<ShippingAgent>(licenseNumber, id, name, password, email, phoneNumber,type,status);
		if ((m_dataStore.addUser(agent)))
		{
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
	//can add further users if needed in the future
}

/*
 * Function: authenticateUser
 * Description: Authenticates user based on email and password
 * Parameters:
 *    email - user email
 *    password - user password
 *    username - stores authenticated user's name
 * Returns:
 *    Process status
 */
Enums::ProcessStatus UserService::authenticateUser(std::string& email, std::string& password, std::string& username)
{
	std::shared_ptr<User> user;
	if (user = m_dataStore.getUserByEmail(email))
	{
		if(user->getPassword() == password && user->getStatus() == Enums::UserStatus::ACTIVE)
		{
			m_dataStore.setCurrentUser(user);
			username = user->getName();
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
 * Function: getUserType
 * Description: Retrieves user type based on email
 * Parameters:
 *    email - user email
 * Returns:
 *    User type
 */
Enums::UserTypes UserService::getUserType(std::string& email)
{
	std::shared_ptr<User> user;
	user = m_dataStore.getUserByEmail(email);
	return user->getRole();
}

/*
 * Function: getUserDetailByIdAndType
 * Description: Retrieves user details by user ID and role
 * Parameters:
 *    userId - ID of the user
 *    role - user role
 * Returns:
 *    Vector containing user details
 */
std::vector<std::string> UserService::getUserDetailByIdAndType(std::string& userId, Enums::UserTypes role)
{
	std::vector<std::string> userDetails;
	std::shared_ptr<User> user = m_dataStore.getUserById(userId);
	if (user != nullptr && user->getRole() == role)
	{
		userDetails.push_back("Name: " + user->getName());
		userDetails.push_back("Email: " + user->getEmail());
		userDetails.push_back("Phone: " + user->getPhoneNumber());
		return userDetails;
	}
	userDetails.clear();
	return userDetails;
}

/*
 * Function: IsPhoneNumberUnique
 * Description: Checks if the given phone number is unique
 * Parameters:
 *    phoneNumber - phone number to validate
 * Returns:
 *    True if unique, otherwise false
 */
bool UserService::IsPhoneNumberUnique(std::string& phoneNumber)
{
	const std::vector<std::shared_ptr<User>>& users = m_dataStore.getUsers();
	for (std::vector<std::shared_ptr<User>>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
	{
		if ((*iterator)->getPhoneNumber() == phoneNumber)
		{
			return false;
		}
	}
	return true;
}

/*
 * Function: IsEmailIdUnique
 * Description: Checks if the given email ID is unique
 * Parameters:
 *    email - email to validate
 * Returns:
 *    True if unique, otherwise false
 */
bool UserService::IsEmailIdUnique(std::string& email)
{
	const std::vector<std::shared_ptr<User>>& users = m_dataStore.getUsers();
	for (std::vector<std::shared_ptr<User>>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
	{
		if ((*iterator)->getEmail() == email)
		{
			return false;
		}
	}
	return true;
}

/*
 * Function: IsLicenseNumberUnique
 * Description: Checks if the given license number is unique among shipping agents
 * Parameters:
 *    licenseNumber - license number to validate
 * Returns:
 *    True if unique, otherwise false
 */
bool UserService::IsLicenseNumberUnique(std::string& licenseNumber)
{
	const std::vector<std::shared_ptr<User>>& users = m_dataStore.getUsers();
	for (std::vector<std::shared_ptr<User>>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
	{
		if ((*iterator)->getRole() == Enums::UserTypes::SHIP_MANAGER)
		{
			ShippingAgent* agent = dynamic_cast<ShippingAgent*>(iterator->get());
			if (agent != nullptr)
			{
				if (agent->getLicenseNumber() == licenseNumber)
				{
					return false;
				}
			}
		}
	}
	return true;
}

/*
 * Function: IsBadgeNumberUnique
 * Description: Checks if the given badge number is unique among customs officers
 * Parameters:
 *    badgeNumber - badge number to validate
 * Returns:
 *    True if unique, otherwise false
 */
bool UserService::IsBadgeNumberUnique(std::string& badgeNumber)
{
	const std::vector<std::shared_ptr<User>>& users = m_dataStore.getUsers();
	for (std::vector<std::shared_ptr<User>>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
	{
		if ((*iterator)->getRole() == Enums::UserTypes::CUSTOMS_OFFICER)
		{
			CustomsOfficer* officer = dynamic_cast<CustomsOfficer*>(iterator->get());
			if (officer != nullptr)
			{
				if (officer->getBadgeNumber() == badgeNumber)
				{
					return false;
				}
			}
		}
	}
	return true;
}

/*
 * Function: logoutUser
 * Description: Logs out the currently active user
 */
void UserService::logoutUser()
{
	m_dataStore.setCurrentUser(nullptr);
}

/*
 * Function: getUserList
 * Description: Retrieves list of all users
 * Returns:
 *    Vector containing user details as strings
 */
std::vector<std::string> UserService::getUserList()
{
	std::vector<std::string> userList;
	const std::vector<std::shared_ptr<User>>& users = m_dataStore.getUsers();
	for (std::vector<std::shared_ptr<User>>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
	{
		userList.push_back((*iterator)->toString());
	}
	return userList;
}

/*
 * Function: addUser
 * Description: Adds a new user of specified type
 * Parameters:
 *    userInformation - vector containing user details
 *    type - user type
 *    status - user status
 * Returns:
 *    Process status
 */
Enums::ProcessStatus UserService::addUser(std::vector<std::string>& userInformation, Enums::UserTypes type, Enums::UserStatus status)
{
	std::string id, name, password, email, phoneNumber;
	std::vector<std::string>::iterator iterator = userInformation.begin();
	id = *iterator++;
	name = *iterator++;
	password = *iterator++;
	email = *iterator++;
	phoneNumber = *iterator++;
	std::shared_ptr<User> user;
	switch (type)
	{
	case Enums::UserTypes::PICKUP_AGENT:
		user = Factory::getObject<PickupAgent>(id, name, password, email, phoneNumber, type, status);
		break;
	case Enums::UserTypes::PORT_AUTHORITY_ADMINISTRATOR:
		user = Factory::getObject<PortAuthorityAdmin>(id, name, password, email, phoneNumber, type, status);
		break;
	case Enums::UserTypes::SHIP_MANAGER:
		user = Factory::getObject<ShipManager>(id, name, password, email, phoneNumber, type, status);
		break;
	case Enums::UserTypes::TERMINAL_OPERATOR:
		user = Factory::getObject<TerminalOperator>(id, name, password, email, phoneNumber, type, status);
		break;
	/*case Enums::UserTypes::FINANCE_MANAGER:
		user = Factory::getObject<FinanceManager>(id, name, password, email, phoneNumber, type, status);
		break;*/
	case Enums::UserTypes::CUSTOMS_OFFICER:
	{
		std::string badgeNumber = *iterator;
		user = Factory::getObject<CustomsOfficer>(badgeNumber, id, name, password, email, phoneNumber, type, status);
		break;
	}
	default:
		return Enums::ProcessStatus::FAILED;
	}
	if (m_dataStore.addUser(user))
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}

/*
 * Function: changeCurrentUserPassword
 * Description: Changes password of the currently logged-in user
 * Parameters:
 *    password - new password
 * Returns:
 *    Process status
 */
Enums::ProcessStatus UserService::changeCurrentUserPassword(std::string& password)
{
	std::shared_ptr<User>& currentUser = m_dataStore.getCurrentUser();
	if (currentUser == nullptr)
	{
		return Enums::ProcessStatus::FAILED;
	}
	else
	{
		currentUser->setPassword(password);
		return Enums::ProcessStatus::SUCCESS;
	}
}

/*
 * Function: getUserListByRole
 * Description: Retrieves list of users filtered by role
 * Parameters:
 *    role - user role
 * Returns:
 *    Vector containing filtered user list
 */
std::vector<std::string> UserService::getUserListByRole(Enums::UserTypes role)
{
	std::vector<std::string> userList;
	const std::vector<std::shared_ptr<User>>& users = m_dataStore.getUsers();
	for (std::vector<std::shared_ptr<User>>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
	{
		if ((*iterator)->getRole() == role)
		{
			userList.push_back((*iterator)->toString());
		}
	}
	return userList;
}

/*
 * Function: updatedUserPhoneNumber
 * Description: Updates phone number of a user
 * Parameters:
 *    userId - ID of the user
 *    updatedPhoneNumber - new phone number
 * Returns:
 *    Process status
 */
Enums::ProcessStatus UserService::updatedUserPhoneNumber(std::string& userId, std::string& updatedPhoneNumber)
{
	m_dataStore.getUserById(userId)->setPhoneNumber(updatedPhoneNumber);
	if (m_dataStore.getUserById(userId)->getPhoneNumber() == updatedPhoneNumber)
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	return Enums::ProcessStatus::FAILED;
}

/*
 * Function: updatedUserEmailId
 * Description: Updates email ID of a user
 * Parameters:
 *    userId - ID of the user
 *    updatedEmailId - new email ID
 * Returns:
 *    Process status
 */
Enums::ProcessStatus UserService::updatedUserEmailId(std::string& userId, std::string& updatedEmailId)
{
	m_dataStore.getUserById(userId)->setEmail(updatedEmailId);
	if (m_dataStore.getUserById(userId)->getEmail() == updatedEmailId)
	{
		return Enums::ProcessStatus::SUCCESS;
	}
	return Enums::ProcessStatus::FAILED;
}

/*
 * Function: changeUserStatus
 * Description: Changes the status of a user
 * Parameters:
 *    userId - ID of the user
 *    userStatus - new status to be assigned
 * Returns:
 *    Process status
 */
Enums::ProcessStatus UserService::changeUserStatus(std::string& userId, Enums::UserStatus userStatus)
{
	if (std::shared_ptr<User> user = m_dataStore.getUserById(userId))
	{
		user->setStatus(userStatus);
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}
