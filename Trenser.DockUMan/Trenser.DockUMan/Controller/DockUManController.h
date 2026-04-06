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
	Enums::ProcessStatus registerShippingAgent(std::vector<std::string>&, Enums::UserTypes&, Enums::UserStatus&);
	Enums::ProcessStatus handleAuthentication(std::string&,std::string&);
	Enums::UserTypes getUserType(std::string&);
	void logoutUser();
};

