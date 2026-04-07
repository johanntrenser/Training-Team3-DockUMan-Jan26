#include "Menu.h"

void Menu::getAuthenticationMenu()
{
	std::cout << "-------------------Authentication Menu-------------------" << std::endl;
	std::cout << "1.Register as a Shipping Agent" << std::endl;
	std::cout << "2.Login" << std::endl;
	std::cout << "3.Exit" << std::endl;
}

void Menu::getAdminMenu()
{
	std::cout << "-------------------Admin Menu-------------------" << std::endl;
	std::cout << "Add Users" << std::endl;
	std::cout << "View User List" << std::endl;
	std::cout << "Update User Profile" << std::endl;
	std::cout << "Approve User" << std::endl;
	std::cout << "Deactivate User" << std::endl;
	std::cout << "Change Password" << std::endl;
	std::cout << "Logout" << std::endl;
}

void Menu::getTerminalOperatorMenu()
{
    std::cout << "-------------------Terminal Operator Menu-------------------" << std::endl;
    std::cout << "1. Truck Operations" << std::endl;
    std::cout << "2. Crane Operations" << std::endl;
    std::cout << "3. Logout" << std::endl;
}

void Menu::getTruckOperationsMenu()
{
    std::cout << "-------------------Truck Operations Menu-------------------" << std::endl;
    std::cout << "1. Add Truck" << std::endl;
    std::cout << "2. View Truck Details" << std::endl;
    std::cout << "3. Assign Container to Truck" << std::endl;
    std::cout << "4. Move Container to Yard" << std::endl;
    std::cout << "5. Update Truck Status" << std::endl;
    std::cout << "6. List Available Trucks" << std::endl;
    std::cout << "7. List All Trucks" << std::endl;
    std::cout << "8. Back to Terminal Operator Menu" << std::endl;
}

void Menu::getCraneOperationsMenu()
{
    std::cout << "-------------------Crane Operations Menu-------------------" << std::endl;
    std::cout << "1. Add Crane" << std::endl;
    std::cout << "2. View Crane Details" << std::endl;
    std::cout << "3. Assign Container to Crane" << std::endl;
    std::cout << "4. Load Container to Ship" << std::endl;
    std::cout << "5. Unload Container from Ship" << std::endl;
    std::cout << "6. Update Crane Status" << std::endl;
    std::cout << "7. List Available Cranes" << std::endl;
    std::cout << "8. List All Cranes" << std::endl;
    std::cout << "9. Back to Terminal Operator Menu" << std::endl;
}

void Menu::getUserRolesMenu()
{
    std::cout << "-------------------User Roles Menu------------------" << std::endl;
    std::cout << "1. Finance Manager\n";
    std::cout << "2. Port Authority Administrator\n";
    std::cout << "3. Customs Officer\n";
    std::cout << "4. Terminal Operator\n";
    std::cout << "5. Ship Manager\n";
    std::cout << "Select User Role: " << std::endl;
}

void Menu::getUpdateDetailsMenu()
{
    std::cout << "-------------------Update Details Menu------------------" << std::endl;
    std::cout << "1. Email Address\n";
    std::cout << "2. Phone Number\n";
    std::cout << "Select Detail to Update: " << std::endl;
}
