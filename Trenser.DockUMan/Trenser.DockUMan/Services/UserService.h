#pragma once
#include<iostream>
#include<vector>
#include "Enums.h"
#include "Factory.h"
#include "ShippingAgent.h"
#include "CustomsOfficer.h"
#include "DataStore.h"
class UserService
{
private:
	DataStore& m_dataStore;
public:
	UserService() :m_dataStore(DataStore::getInstance()) {};
	Enums::ProcessStatus registerUser(std::vector<std::string>&, Enums::UserTypes&, Enums::UserStatus&);
	Enums::ProcessStatus authenticateUser(std::string&, std::string&);
	Enums::UserTypes getUserType(std::string&);
	bool IsPhoneNumberUnique(std::string&);
	bool IsEmailIdUnique(std::string&);
	bool IsLicenseNumberUnique(std::string&);
	bool IsBadgeNumberUnique(std::string&);
	void logoutUser();
	std::vector<std::string> getUserList();
	Enums::ProcessStatus deactivateUser(std::string&, std::string&);
};


