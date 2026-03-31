#include "User.h"

User::User()
{
	m_id = "";
	m_name = "";
	m_password = "";
	m_email = "";
	m_phoneNumber = "";
}

User::User(std::string id, std::string name, std::string password, std::string email, std::string phoneNumber)
{
	m_id = id;
	m_name = name;
	m_password = password;
	m_email = email;
	m_phoneNumber = phoneNumber;
}

std::string User::getId()
{
	return m_id;
}

std::string User::getName()
{
	return m_name;
}

std::string User::getPassword()
{
	return m_password;
}

std::string User::getEmail()
{
	return m_email;
}

std::string User::getPhoneNumber()
{
	return m_phoneNumber;
}

void User::setId(std::string id)
{
	m_id = id;
}

void User::setName(std::string name)
{
	m_name = name;
}

void User::setPassword(std::string password)
{
	m_password = password;
}
void User::setEmail(std::string email)
{
	m_email = email;
}
void User::setPhoneNumber(std::string phoneNumber)
{
	m_phoneNumber = phoneNumber;
}