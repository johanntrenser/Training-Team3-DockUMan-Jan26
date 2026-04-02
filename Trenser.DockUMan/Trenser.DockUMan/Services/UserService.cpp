#include "UserService.h"

Enums::ProcessStatus UserService::registerShippingAgent(std::vector<std::string>& userInformation, Enums::UserTypes& type, Enums::UserStatus& status)
{

	if (type == Enums::UserTypes::SHIPPING_AGENT)
	{
		std::string licenseNumber, id, name, password, email, phoneNumber;
		auto iterator = userInformation.begin();
		id = *iterator++;
		name = *iterator++;
		password = *iterator++;
		email = *iterator++;
		phoneNumber = *iterator++;
		licenseNumber = *iterator;
		auto agent = Factory::getObject<ShippingAgent>(licenseNumber, id, name, password, email, phoneNumber,type,status);
		if ((m_dataStore.addUser(agent)))
		{
			return Enums::ProcessStatus::SUCCESS;
		}
		else
		{
			return Enums::ProcessStatus::FAILED;
		}
	}
}
