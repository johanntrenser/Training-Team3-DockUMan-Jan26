/*
 * File: Menu.h
 * Description: Defines the Menu Class
 * Author: Entire Team
 * Created: 02-Apr-2026
 */
#pragma once
#include<iostream>
class Menu
{
public:
	Menu() {};
	void getAuthenticationMenu();
	void getAdminMenu();
	void getTerminalOperatorMenu();
	void getTruckOperationsMenu();
	void getCraneOperationsMenu();
	void getUserRolesMenu();
	void getUpdateDetailsMenu();
	void getAddUserMenu();
};
