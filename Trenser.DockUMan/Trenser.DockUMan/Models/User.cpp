/*
 * File: User.cpp
 * Description: Implements getter and setter functions for the User model class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "User.h"
#include "PickupAgent.h"
#include "PortAuthorityAdmin.h"
#include "CustomsOfficer.h"
#include "TerminalOperator.h"
#include "ShipManager.h"
 //#include "FinanaceManager.h"

std::string User::getId() const
{
	return m_id;
}

std::string User::getName() const
{
	return m_name;
}

std::string User::getPassword() const
{
	return m_password;
}

std::string User::getEmail() const
{
	return m_email;
}

std::string User::getPhoneNumber() const
{
	return m_phoneNumber;
}

Enums::UserTypes User::getRole() const
{
	return m_type;
}

Enums::UserStatus User::getStatus() const
{
	return m_status;
}

void User::setId(const std::string& id)
{
	m_id = id;
}

void User::setName(const std::string& name)
{
	m_name = name;
}

void User::setPassword(const std::string& password)
{
	m_password = password;
}
void User::setEmail(const std::string& email)
{
	m_email = email;
}
void User::setPhoneNumber(const std::string& phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

void User::setRole(const Enums::UserTypes& type)
{
	m_type = type;
}

void User::setStatus(const Enums::UserStatus& status)
{
	m_status = status;
}

std::string User::toString()
{
	return m_id + " : " + m_name;
}

std::string User::serialize() const
{
	std::ostringstream serializedUser;
	serializedUser << m_id << ","
		<< m_name << ","
		<< m_password << ","
		<< m_email << ","
		<< m_phoneNumber << ","
		<< Enums::getUserTypeInString(m_type) << ","
		<< Enums::getUserStatusInString(m_status);
	return serializedUser.str();
}

User* User::deserialize(const std::string& record)
{
	std::string id, name, password, email, phoneNumber;
	std::string userType, userStatus;
	std::istringstream serializedUser(record);
	getline(serializedUser, id, ',');
	getline(serializedUser, name, ',');
	getline(serializedUser, password, ',');
	getline(serializedUser, email, ',');
	getline(serializedUser, phoneNumber, ',');
	getline(serializedUser, userType, ',');
	getline(serializedUser, userStatus, ',');
	Enums::UserTypes type = Enums::getUserType(userType);
	Enums::UserStatus status = Enums::getUserStatus(userStatus);
	switch (type)
	{
	case Enums::UserTypes::NOT_ASSIGNED:
		return Factory::getObject<User>(
			id, name, password, email, phoneNumber, type, status);
	case Enums::UserTypes::PICKUP_AGENT:
		return Factory::getObject<PickupAgent>(
			id, name, password, email, phoneNumber, type, status);
	case Enums::UserTypes::PORT_AUTHORITY_ADMINISTRATOR:
		return Factory::getObject<PortAuthorityAdmin>(
			id, name, password, email, phoneNumber, type, status);
	/*case Enums::UserTypes::FINANCE_MANAGER:
		return Factory::getObject<FinanceManager>(
			id, name, password, email, phoneNumber);*/
	case Enums::UserTypes::TERMINAL_OPERATOR:
		return Factory::getObject<TerminalOperator>(
			id, name, password, email, phoneNumber, type, status);
	case Enums::UserTypes::SHIP_MANAGER:
		return Factory::getObject<ShipManager>(
			id, name, password, email, phoneNumber, type, status);
	default:
		return nullptr;
	}
}

std::string User::getHeaders()
{
	return "Id,Name,Password,Email,PhoneNumber,Type,Status";
}