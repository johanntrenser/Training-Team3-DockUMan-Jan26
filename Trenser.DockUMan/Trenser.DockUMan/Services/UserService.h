/*
 * File: UserService.h
 * Description: Handles user-related business logic including registration, 
				authentication, validation, and user management operations
 * Author: Entire Team
 * Created: 02-Apr-2026
 */
#pragma once
#include<iostream>
#include<vector>
#include "Enums.h"
#include "Factory.h"
#include "ShippingAgent.h"
#include "CustomsOfficer.h"
//#include "FinanceManager.h"
#include "TerminalOperator.h"
#include "PickupAgent.h"
#include "PortAuthorityAdmin.h"
#include "ShipManager.h"
#include "DataStore.h"

class UserService
{
private:
	DataStore& m_dataStore;
public:
	UserService() :m_dataStore(DataStore::getInstance()) {};
	Enums::ProcessStatus addUser(std::vector<std::string>&, Enums::UserTypes type, Enums::UserStatus status);
	Enums::ProcessStatus registerUser(std::vector<std::string>&, Enums::UserTypes, Enums::UserStatus);
	Enums::ProcessStatus authenticateUser(std::string& email, std::string& password, std::string& username);
	Enums::UserTypes getUserType(std::string&);
	std::vector<std::string> getUserDetailByIdAndType(std::string&, Enums::UserTypes);
	bool IsPhoneNumberUnique(const std::string&);
	bool IsEmailIdUnique(const std::string&);
	bool IsLicenseNumberUnique(const std::string&);
	bool IsBadgeNumberUnique(const std::string&);
	void logoutUser();
	std::vector<std::string> getUserList();
	std::vector<std::string> getUserListByRole(Enums::UserTypes);
	Enums::ProcessStatus updatedUserPhoneNumber(std::string&, std::string&);
	Enums::ProcessStatus updatedUserEmailId(std::string&, std::string&);
	Enums::ProcessStatus changeCurrentUserPassword(std::string& password);
	Enums::ProcessStatus changeUserStatus(std::string&, Enums::UserStatus);
};


