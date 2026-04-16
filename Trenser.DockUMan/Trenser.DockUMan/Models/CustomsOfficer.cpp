/*
 * File: CustomsOfficer.cpp
 * Description: Contains getters and setters for CustomsOfficer model class representing customs officer-related data
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "CustomsOfficer.h"
std::string CustomsOfficer::getBadgeNumber() const
{
	return m_badgeNumber;
}
void CustomsOfficer::setBadgeNumber(const std::string& badgeNumber)
{
	m_badgeNumber = badgeNumber;
}

std::string CustomsOfficer::seralize() const
{
	std::ostringstream serializedUser;
	serializedUser << User::getId() << ","
		<< User::getName() << ","
		<< User::getPassword() << ","
		<< User::getEmail() << ","
		<< User::getPhoneNumber() << ","
		<< Enums::getUserTypeInString(User::getRole()) << ","
		<< Enums::getUserStatusInString(User::getStatus()) << ","
		<< m_badgeNumber;
	return serializedUser.str();
}

User* CustomsOfficer::deserialize(const std::string& record)
{
	std::string id, name, password, email, phoneNumber;
	std::string userType, userStatus, badgeNumber;
	std::istringstream serializedUser(record);
	getline(serializedUser, id, ',');
	getline(serializedUser, name, ',');
	getline(serializedUser, password, ',');
	getline(serializedUser, email, ',');
	getline(serializedUser, phoneNumber, ',');
	getline(serializedUser, userType, ',');
	getline(serializedUser, userStatus, ',');
	getline(serializedUser, badgeNumber, ',');
	Enums::UserTypes type = Enums::getUserType(userType);
	Enums::UserStatus status = Enums::getUserStatus(userStatus);
	return Factory::getObject<CustomsOfficer>(badgeNumber, id, name, password, email, phoneNumber, type, status);
}

std::string CustomsOfficer::getHeaders()
{
	return "Id,Name,Password,Email,PhoneNumber,Type,Status,Badge Number";
}