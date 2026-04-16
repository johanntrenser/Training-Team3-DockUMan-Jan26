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
#include "ShipService.h"
#include "Enums.h"

class DockUManController
{
private:
	UserService* m_userService;
	ShipService* m_shipService;
public:
	DockUManController() : m_userService(new UserService()), m_shipService(new ShipService()){};
	Enums::ProcessStatus registerShippingAgent(std::vector<std::string>&, Enums::UserTypes, Enums::UserStatus);
	Enums::ProcessStatus handleAuthentication(std::string& email, std::string& password, std::string& username);
	Enums::ProcessStatus addUser(std::vector<std::string>&, Enums::UserTypes type, Enums::UserStatus status);
	Enums::UserTypes getUserType(std::string&);
	std::vector<std::string> getUserDetailByIdAndType(std::string&, Enums::UserTypes);
	void logoutUser();
	std::vector<std::string> getUserList();
	std::vector<std::string> getUserListByRole(Enums::UserTypes);
	Enums::ProcessStatus sendShipArrivalRequest();
	Enums::ProcessStatus updatedUserPhoneNumber(std::string&, std::string&);
	Enums::ProcessStatus updatedUserEmailId(std::string&, std::string&);
	Enums::ProcessStatus IsEmailIdUnique(std::string& email);
	Enums::ProcessStatus IsPhoneNumberUnique(std::string& phoneNumber);
	Enums::ProcessStatus IsLicenseNumberUnique(std::string& licenseNumber);
	Enums::ProcessStatus IsBadgeNumberUnique(std::string& badgeNumber);
	Enums::ProcessStatus changeCurrentUserPassword(std::string& password);
	Enums::ProcessStatus deactivateUser(std::string&);
	Enums::ProcessStatus registerShip(std::vector<std::string>& userInformation, std::vector<std::string>& shipInformation, Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status);
	std::vector<std::string> getShipList();
	Enums::ProcessStatus trackShipStatus(std::string&,std::string&);
	Enums::ProcessStatus recordShipArrival(std::string&);
	Enums::ProcessStatus recordShipDeparture(std::string&);
	Enums::ProcessStatus approveUser(std::string&);
	Enums::ProcessStatus updateShipAvailabilityStatus(std::string&, Enums::AvailabilityStatus);
	~DockUManController()
	{
		delete m_userService;
		delete m_shipService;
	}
};

