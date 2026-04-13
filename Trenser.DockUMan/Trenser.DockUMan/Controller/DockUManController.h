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
	Enums::UserTypes getUserType(std::string&);
	void logoutUser();
	std::vector<std::string> getUserList();
	Enums::ProcessStatus deactivateUser(std::string&);
	Enums::ProcessStatus registerShip(std::vector<std::string>& userInformation, std::vector<std::string>& shipInformation, Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status);
	std::vector<std::string> getShipList();
	Enums::ProcessStatus trackShipStatus(std::string&,std::string&);
	Enums::ProcessStatus recordShipArrival(std::string&);
	Enums::ProcessStatus recordShipDeparture(std::string&);
	~DockUManController()
	{
		delete m_userService;
		delete m_shipService;
	}
};

