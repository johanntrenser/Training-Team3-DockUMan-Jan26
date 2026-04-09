/*
 * File: DockUManController.h
 * Description: Acts as an intermediary between the UI and service layers
 * Author: Entire Team
 * Created: 30-Mar-2026
 */
#pragma once
#include <vector>
#include<iostream>
#include "UserService.h"
#include "Enums.h"

class DockUManController
{
private:
	std::shared_ptr<UserService> m_userService;
public:
	DockUManController():m_userService(std::make_shared<UserService>()){};
	Enums::ProcessStatus registerShippingAgent(std::vector<std::string>&, Enums::UserTypes, Enums::UserStatus);
	Enums::ProcessStatus addUser(std::vector<std::string>&, Enums::UserTypes type, Enums::UserStatus status);
	Enums::ProcessStatus handleAuthentication(std::string& email,std::string& password, std::string& username);
	Enums::UserTypes getUserType(std::string&);
	std::vector<std::string> getUserDetailByIdAndType(std::string&, Enums::UserTypes);
	void logoutUser();
	std::vector<std::string> getUserList();
	std::vector<std::string> getUserListByRole(Enums::UserTypes);
	Enums::ProcessStatus updatedUserPhoneNumber(std::string&, std::string&);
	Enums::ProcessStatus updatedUserEmailId(std::string&, std::string&);
	Enums::ProcessStatus IsEmailIdUnique(std::string& email);
	Enums::ProcessStatus IsPhoneNumberUnique(std::string& phoneNumber);
	Enums::ProcessStatus IsLicenseNumberUnique(std::string& licenseNumber);
	Enums::ProcessStatus IsBadgeNumberUnique(std::string& badgeNumber);
	Enums::ProcessStatus changeCurrentUserPassword(std::string& password);
	Enums::ProcessStatus deactivateUser(std::string&);
	Enums::ProcessStatus approveUser(std::string&);
};

