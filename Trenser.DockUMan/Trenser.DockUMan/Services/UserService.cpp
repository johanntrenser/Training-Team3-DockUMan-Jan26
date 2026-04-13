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
		User* agent = Factory::getObject<ShippingAgent>(licenseNumber, id, name, password, email, phoneNumber, type, status);
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
	User* user;
	if (user = m_dataStore.getUserByEmail(email))
	{
		/*if (user->getPassword() == password && user->getStatus() == Enums::UserStatus::ACTIVE)*/ //commented now as shipping agent has status
		//pending. change the below later to the above
		if (user->getPassword() == password)
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
	User* user;
	user = m_dataStore.getUserByEmail(email);
	if (user != nullptr)
	{
		return user->getRole();
	}
	return Enums::UserTypes::NOT_ASSIGNED;    //check later if other error to be replaced with
}

/*
 * Function: IsPhoneNumberUnique
 * Description: Checks if the given phone number is unique
 * Parameters:
 *    phoneNumber - phone number to validate
 * Returns:
 *    True if unique, otherwise false
 */
bool UserService::IsPhoneNumberUnique(const std::string& phoneNumber)
{
	const std::vector<User*>& users = m_dataStore.getUsers();
	for (std::vector<User*>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
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
bool UserService::IsEmailIdUnique(const std::string& email)
{
	const std::vector<User*>& users = m_dataStore.getUsers();
	for (std::vector<User*>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
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
bool UserService::IsLicenseNumberUnique(const std::string& licenseNumber)
{
	const std::vector<User*>& users = m_dataStore.getUsers();
	for (std::vector<User*>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
	{
		if ((*iterator)->getRole() == Enums::UserTypes::SHIPPING_AGENT)
		{
			ShippingAgent* agent = dynamic_cast<ShippingAgent*>(*iterator);
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
bool UserService::IsBadgeNumberUnique(const std::string& badgeNumber)
{
	const std::vector<User*>& users = m_dataStore.getUsers();
	for (std::vector<User*>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
	{
		if ((*iterator)->getRole() == Enums::UserTypes::CUSTOMS_OFFICER)
		{
			CustomsOfficer* officer = dynamic_cast<CustomsOfficer*>(*iterator);
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
	const std::vector<User*>& users = m_dataStore.getUsers();
	for (std::vector<User*>::const_iterator iterator = users.begin(); iterator != users.end(); ++iterator)
	{
		userList.push_back((*iterator)->toString());
	}
	return userList;
}

Enums::ProcessStatus UserService::deactivateUser(std::string& userId)
{
	User* user = m_dataStore.getUserById(userId); // could be a problem later because of function renaming. check function calls
	if (user != nullptr)
	{
		user->setStatus(Enums::UserStatus::INACTIVE);
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}

User* UserService::registerShipManger(std::vector<std::string>& userInformation)
{
	std::string  id, name, password, email, phoneNumber;
	Enums::UserTypes type = Enums::UserTypes::SHIP_MANAGER;
	Enums::UserStatus userStatus = Enums::UserStatus::ACTIVE;
	std::vector<std::string>::iterator iterator = userInformation.begin();
	id = *iterator++;
	name = *iterator++;
	password = *iterator++;
	email = *iterator++;
	phoneNumber = *iterator;
	User* agent = Factory::getObject<ShipManager>(id, name, password, email, phoneNumber, type, userStatus);
	if (m_dataStore.addUser(agent))
	{
		return agent;
	}
	else
	{
		return nullptr;
	}
}


