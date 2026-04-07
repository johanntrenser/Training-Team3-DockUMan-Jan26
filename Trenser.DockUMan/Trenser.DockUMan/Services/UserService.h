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
	Enums::ProcessStatus addUser(std::vector<std::string>&, Enums::UserTypes&, Enums::UserStatus&);
	Enums::ProcessStatus registerUser(std::vector<std::string>&, Enums::UserTypes&, Enums::UserStatus&);
	Enums::ProcessStatus authenticateUser(std::string&, std::string&);
	Enums::UserTypes getUserType(std::string&);
	std::vector<std::string> getUserDetailByIdAndType(std::string&, Enums::UserTypes);
	bool IsPhoneNumberUnique(std::string&);
	bool IsEmailIdUnique(std::string&);
	bool IsLicenseNumberUnique(std::string&);
	bool IsBadgeNumberUnique(std::string&);
	void logoutUser();
	std::vector<std::string> getUserList();
	std::vector<std::string> getUserListByRole(Enums::UserTypes);
	Enums::ProcessStatus updatedUserPhoneNumber(std::string&, std::string&);
	Enums::ProcessStatus updatedUserEmailId(std::string&, std::string&);
	Enums::ProcessStatus changeCurrentUserPassword(std::string& password);
	Enums::ProcessStatus changeUserStatus(std::string&, Enums::UserStatus);
};


