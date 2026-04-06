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