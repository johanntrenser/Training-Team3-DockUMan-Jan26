#pragma once
#include<iostream>
#include<vector>
#include "Menu.h"
#include "DockUManController.h"
#include "InputHelper.h"
#include "Enums.h"

class UserInterface
{
private:
	std::shared_ptr<Menu> m_menu;
	std::shared_ptr<DockUManController> m_DockUManController;
public:
	UserInterface():m_menu(std::make_shared<Menu>()),
		m_DockUManController(std::make_shared<DockUManController>()){};
	void start();
	void handleAuthenticationOperation(const int&,bool&);
	void registerShippingAgentUI();
	void handleShippingAgentUserInput(std::vector<std::string>&);
};

