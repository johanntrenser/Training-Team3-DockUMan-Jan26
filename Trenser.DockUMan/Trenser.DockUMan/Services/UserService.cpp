#include "UserService.h"

Enums::ProcessStatus UserService::registerUser(std::vector<std::string>& userInformation, Enums::UserTypes& type, Enums::UserStatus& status)
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
}

Enums::ProcessStatus UserService::authenticateUser(std::string& username, std::string& password)
{
	bool isUserActive=false;
	std::shared_ptr<User> user;
	if (user=m_dataStore.getUser(username))
	{
		if((*user).getPassword() == password)
		{
			m_dataStore.setCurrentUser(user);
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

Enums::UserTypes UserService::getUserType(std::string& username)
{
	std::shared_ptr<User> user;
	user = m_dataStore.getUser(username);
	return user->getRole();
}

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

void UserService::logoutUser()
{
	m_dataStore.setCurrentUser(nullptr);
}

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

Enums::ProcessStatus UserService::deactivateUser(std::string& userId)
{
	if (std::shared_ptr<User> user = m_dataStore.getUser(userId))
	{
		user->setStatus(Enums::UserStatus::INACTIVE);
		return Enums::ProcessStatus::SUCCESS;
	}
	else
	{
		return Enums::ProcessStatus::FAILED;
	}
}
std::shared_ptr<User> UserService::registerShipManger(std::vector<std::string>& userInformation)
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
	std::shared_ptr<User> agent = Factory::getObject<ShipManager>(id, name, password, email, phoneNumber, type, userStatus);
	if (m_dataStore.addUser(agent))
	{
		return agent;
	}
	else
	{
		return nullptr;
	}
}


