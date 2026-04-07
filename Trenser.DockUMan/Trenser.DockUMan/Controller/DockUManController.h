#pragma once
#include <vector>
#include<iostream>
#include "UserService.h"
#include "ShipService.h"
#include "Enums.h"
class DockUManController
{
private:
	std::shared_ptr<UserService> m_userService;
	std::shared_ptr<ShipService> m_shipService;
public:
	DockUManController():m_userService(std::make_shared<UserService>()),m_shipService(std::make_shared<ShipService>()){};
	Enums::ProcessStatus registerShippingAgent(std::vector<std::string>&, Enums::UserTypes&, Enums::UserStatus&);
	Enums::ProcessStatus handleAuthentication(std::string&,std::string&);
	Enums::UserTypes getUserType(std::string&);
	void logoutUser();
	std::vector<std::string> getUserList();
	Enums::ProcessStatus deactivateUser(std::string&);
	Enums::ProcessStatus registerShip(std::vector<std::string>& userInformation, std::vector<std::string>& shipInformation, Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status);
	std::vector<std::string> getShipList();
};

