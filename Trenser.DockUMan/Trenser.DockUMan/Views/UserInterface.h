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
	std::shared_ptr<Menu> m_menu;
	std::shared_ptr<DockUManController> m_dockUManController;
public:
	UserInterface():m_menu(std::make_shared<Menu>()),
		m_dockUManController(std::make_shared<DockUManController>()){};
	void start();
	void handleAuthenticationOperation(const int&,bool&);
	void authenticateUser();
	void registerShippingAgentUI();
	void handleCommonUserInput(std::vector<std::string>& , std::string&, std::string&, std::string&, std::string&);
	void handleCustomsOfficerUserInput(std::vector<std::string>& );
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
	void displayUserList(std::vector<std::string>&);
	void addUserUI();
	void handlePickupAgentUserInput(std::vector<std::string>& userInformation);
	void handlePortAuthorityAdminUserInput(std::vector<std::string>& userInformation);
	void handleShipManagerUserInput(std::vector<std::string>& userInformation);
	void handleTerminalOperatorUserInput(std::vector<std::string>& userInformation);
	void handleFinanceManagerUserInput(std::vector<std::string>& userInformation);
	Enums::ProcessStatus changeCurrentUserPassword();
	Enums::ProcessStatus deactivateUser(std::string&);
	Enums::ProcessStatus approveUser(std::string&);
};

