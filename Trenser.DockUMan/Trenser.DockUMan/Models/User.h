#pragma once
#include <iostream>
class User
{
private:
	std::string m_id;
	std::string m_name;
	std::string m_password;
	std::string m_email;
	std::string m_phoneNumber;
public:
	User();
	User(std::string id, std::string name, std::string password, std::string email, std::string phoneNumber);
	std::string getId();
	std::string getName();
	std::string getPassword();
	std::string getEmail();
	std::string getPhoneNumber();
	/*getRole();
	getStatus();*/
	void setId(std::string);
	void setPassword(std::string);
	void setName(std::string);
	void setEmail(std::string);
	void setPhoneNumber(std::string);
	/*setRole();
	setStatus();*/

};

