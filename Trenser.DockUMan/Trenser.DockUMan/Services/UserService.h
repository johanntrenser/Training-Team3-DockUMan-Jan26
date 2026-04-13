#pragma once
#include<iostream>
#include<vector>
#include "Enums.h"
#include "Factory.h"
#include "ShippingAgent.h"
#include "ShipManager.h"
#include "CustomsOfficer.h"
#include "DataStore.h"
class UserService
{
private:
	DataStore& m_dataStore;
public:
	UserService() :m_dataStore(DataStore::getInstance()) {};
	Enums::ProcessStatus registerUser(std::vector<std::string>&, Enums::UserTypes, Enums::UserStatus);
	Enums::ProcessStatus authenticateUser(std::string& email, std::string& password, std::string& username);
	Enums::UserTypes getUserType(std::string&);
	bool IsPhoneNumberUnique(const std::string&);
	bool IsEmailIdUnique(const std::string&);
	bool IsLicenseNumberUnique(const std::string&);
	bool IsBadgeNumberUnique(const std::string&);
	void logoutUser();
	std::vector<std::string> getUserList();
	Enums::ProcessStatus deactivateUser(std::string&);
	User* registerShipManger(std::vector<std::string>&);
};


