#pragma once
#include<iostream>
#include<vector>
#include "Menu.h"
#include "DockUManController.h"
#include "InputHelper.h"
#include "Validator.h"
#include "Enums.h"

class UserInterface
{
private:
	Menu* m_menu;
	DockUManController* m_dockUManController;
public:
	UserInterface() : m_menu(new Menu()), m_dockUManController(new DockUManController()){};
	void start();
	void handleAuthenticationOperation(const int&,bool&);
	void authenticateUser();
	void registerShippingAgentUI();
	void handlCommonUserInput(std::vector<std::string>& , std::string&, std::string&, std::string&, std::string&);
	void handleMenus(Enums::UserTypes);
	Enums::UserTypes getUserType(std::string&);
	void showUserMenu(Enums::UserTypes);
	void handleShippingAgentUserInput(std::vector<std::string>&);
	void logoutUser();
	void handleAdminMenu();
	void handleTerminalOperatorMenu();
	void handleTruckOperations();
	void handleCraneOperations();
	void getUserList();
	void displayList(std::vector<std::string>&);
	Enums::ProcessStatus deactivateUser(std::string&);
	void registerShipUI();
	void handleRegisterShipInput(std::vector<std::string>&);
	void handleRegisterShipManager(std::vector<std::string>&);
	bool getShipList();
	void trackShipStatus();
	void recordShipArrival();
	void recordShipDeparture();
	~UserInterface()
	{
		delete m_menu;
		delete m_dockUManController;
	}
};

