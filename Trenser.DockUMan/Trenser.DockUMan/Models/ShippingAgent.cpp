/*
 * File: ShippingAgenr.cpp
 * Description: Implements getter and setter functions for the ShippingAgent model class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "ShippingAgent.h"

std::string ShippingAgent::getLicenseNumber() const
{
	return m_licenseNumber;
}

void ShippingAgent::setLicenseNumber(const std::string& licenseNumber)
{
	m_licenseNumber = licenseNumber;
}

std::string ShippingAgent::serialize() const
{
	std::ostringstream serializedUser;
	serializedUser << User::getId() << ","
		<< User::getName() << ","
		<< User::getPassword() << ","
		<< User::getEmail() << ","
		<< User::getPhoneNumber() << ","
		<< Enums::getUserTypeInString(User::getRole()) << ","
		<< Enums::getUserStatusInString(User::getStatus()) << ","
		<< m_licenseNumber;
	return serializedUser.str();
}

ShippingAgent* ShippingAgent::deserialize(const std::string& record)
{
	std::string id, name, password, email, phoneNumber;
	std::string userType, userStatus, licenseNumber;
	std::istringstream serializedUser(record);
	getline(serializedUser, id, ',');
	getline(serializedUser, name, ',');
	getline(serializedUser, password, ',');
	getline(serializedUser, email, ',');
	getline(serializedUser, phoneNumber, ',');
	getline(serializedUser, userType, ',');
	getline(serializedUser, userStatus, ',');
	getline(serializedUser, licenseNumber, ',');
	Enums::UserTypes type = Enums::getUserType(userType);
	Enums::UserStatus status = Enums::getUserStatus(userStatus);
	return Factory::getObject<ShippingAgent>(licenseNumber, id, name, password, email, phoneNumber, type, status);
}

std::string ShippingAgent::getHeaders()
{
	return "Id,Name,Password,Email,PhoneNumber,Type,Status,License Number";
}