#pragma once
#include <iostream>
#include "Enums.h"
class User
{
private:
	std::string m_id;
	std::string m_name;
	std::string m_password;
	std::string m_email;
	std::string m_phoneNumber;
	Enums::UserTypes m_type;
	Enums::UserStatus m_status;
public:
	User() :m_id(""), m_name(""), m_password(""), m_email(""), m_phoneNumber(""),m_type(Enums::UserTypes::NOT_ASSIGNED), m_status(Enums::UserStatus::ACTIVE) {};
	User(std::string id, std::string name, std::string password, std::string email, std::string phoneNumber, Enums::UserTypes type, Enums::UserStatus status) :
		m_id(id), m_name(name), m_password(password), m_email(email), m_phoneNumber(phoneNumber),m_type(type),m_status(status) {};
	std::string getId() const;
	std::string getName() const;
	std::string getPassword() const;
	std::string getEmail() const;
	std::string getPhoneNumber() const;
	Enums::UserTypes getRole() const;
	Enums::UserStatus getStatus() const;
	void setId(const std::string&);
	void setPassword(const std::string&);
	void setName(const std::string&);
	void setEmail(const std::string&);
	void setPhoneNumber(const std::string&);
	void setRole(const Enums::UserTypes&);
	void setStatus(const Enums::UserStatus&);
	std::string toString();
};

