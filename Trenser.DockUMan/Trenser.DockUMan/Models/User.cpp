#include "User.h"

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
