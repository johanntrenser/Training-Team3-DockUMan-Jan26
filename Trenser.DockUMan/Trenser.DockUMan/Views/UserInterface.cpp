#include "UserInterface.h"

void UserInterface::start()
{
	bool isMenuActive = true;
	m_menu->getAuthenticationMenu();
	while (isMenuActive)
	{
		try
		{
			int choice;
			std::cout << "\nEnter Choice : ";
			util::read<int>(choice);
			handleAuthenticationOperation(choice,isMenuActive);
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}
	}
}

void UserInterface::handleAuthenticationOperation(const int& choice,bool& isMenuActive)
{
	switch (choice)
	{
	case 1:
		registerShippingAgentUI();
		break;
	case 2:
		authenticateUser();
		break;
	case 3:
		isMenuActive = false;
		std::cout << "DockUMan Exiting ......" << std::endl;
		break;
	default:
		std::cout << "Invalid Input!" << std::endl;
		break;
	}
}

void UserInterface::authenticateUser()
{
	bool isMenuActive = true;
	while (isMenuActive)
	{
		try
		{
			std::string username,password;
			std::cout << "\nEnter UserName : ";
			util::read<std::string>(username);
			std::cout << "\nEnter Password : ";
			util::read<std::string>(password);
			if (m_dockUManController->handleAuthentication(username, password) == Enums::ProcessStatus::SUCCESS)
			{
				std::cout << "User Login Success! Welcome user : " << username << std::endl;
				isMenuActive = false;
				handleMenus(getUserType(username));
			}
			else
			{
				std::cout << "Invalid credentials  ! " << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}
	}
}

void UserInterface::registerShippingAgentUI()
{
	bool isMenuActive = true;
	//while (isMenuActive)
	//{
		try
		{
			std::vector<std::string>userInformation;
			Enums::UserTypes type=Enums::UserTypes::SHIPPING_AGENT;
			Enums::UserStatus status = Enums::UserStatus::PENDING;
			handleShippingAgentUserInput(userInformation);
			Enums::ProcessStatus processStatus=m_dockUManController->registerShippingAgent(userInformation,type,status);
			if (processStatus == Enums::ProcessStatus::SUCCESS)
			{
				std::cout << "User Created Succesfull!" << std::endl;
			}
			else
			{
				std::cout << "User Creation Failed !" << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}
	//}
}

void UserInterface::handlCommonUserInput(std::vector<std::string>& userInformation,std::string& name, std::string& password, std::string& email, std::string& phoneNumber)
{
	std::cout << "Enter Name :";
	util::read(name);
	userInformation.push_back(name);
	std::cout << "Enter pasword : ";
	validator::validatePassword(password);
	userInformation.push_back(password);
	std::cout << "Enter email : ";
	validator::validateEmail(email);
	userInformation.push_back(email);
	std::cout << "Enter phoneNumber : ";
	validator::validatePhoneNumber(phoneNumber);
	userInformation.push_back(phoneNumber);
}

void UserInterface::handleMenus(Enums::UserTypes userType)
{
	if (userType == Enums::UserTypes::PICKUP_AGENT)
	{
		//call pickupmenu
	}
	else if (userType == Enums::UserTypes::PORT_AUTHORITY_ADMINISTRATOR)
	{
		handleAdminMenu();
	}
	else if (userType == Enums::UserTypes::SHIPPING_AGENT)
	{
		//call menu
	}
	else if (userType == Enums::UserTypes::SHIP_MANAGER)
	{
		//call menu
	}
	else if (userType == Enums::UserTypes::TERMINAL_OPERATOR)
	{
		handleTerminalOperatorMenu();
	}
	else if (userType == Enums::UserTypes::FINANCE_MANAGER)
	{
		//call menu
	}
	else if (userType == Enums::UserTypes::CUSTOMS_OFFICER)
	{
		//call menu
	}
}

Enums::UserTypes UserInterface::getUserType(std::string& username)
{
	return m_dockUManController->getUserType(username);
}

void UserInterface::handleShippingAgentUserInput(std::vector<std::string>& userInformation) //error management
{
	std::string licenseNumber, id, name, password, email, phoneNumber;
	std::cout << "Enter id : "; //id generaator
	util::read(id);
	userInformation.push_back(id);
	handlCommonUserInput(userInformation,name,password,email,phoneNumber);
	std::cout << "Enter license Number : ";
	validator::validateLiscenseNumber(licenseNumber);
	userInformation.push_back(licenseNumber);
}

void UserInterface::logoutUser()
{
	m_dockUManController->logoutUser();
}
void UserInterface::handleAdminMenu()
{
	bool isMenuActive = true;
	while (isMenuActive)
	{
		try
		{
			m_menu->getAdminMenu();
			int choice;
			std::cout << "\nEnter Choice : ";
			util::read<int>(choice);
			switch (choice)
			{
			case 1:
				std::cout << "Add Users selected\n";
				break;
			case 2:
				std::cout << "View User List selected\n";
				break;
			case 3:
				std::cout << "Update User Profile selected\n";
				break;
			case 4:
				std::cout << "Approve User selected\n";
				break;
			case 5:
				std::cout << "Deactivate User selected\n";
				break;
			case 6:
				std::cout << "Change Password selected\n";
				break;
			case 7:
				isMenuActive = false;
				std::cout << "Logging out ..." << std::endl;
				break;
			default:
				std::cout << "Invalid Input!" << std::endl;
				break;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception Occurred : " << e.what() << std::endl;
		}
	}
}

void UserInterface::handleTerminalOperatorMenu()
{
	bool isMenuActive = true;
	while (isMenuActive)
	{
		try
		{
			m_menu->getTerminalOperatorMenu(); 
			int choice;
			std::cout << "\nEnter Choice : ";
			util::read<int>(choice);
			switch (choice)
			{
			case 1:
				handleTruckOperations();
				break;
			case 2:
				handleCraneOperations();
				break;
			case 3:
				isMenuActive = false;
				std::cout << "Logging out Terminal Operator..." << std::endl;
				break;
			default:
				std::cout << "Invalid Input!" << std::endl;
				break;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}
	}
}

void UserInterface::handleTruckOperations()
{
	bool isMenuActive = true;
	while (isMenuActive)
	{
		try
		{
			m_menu->getTruckOperationsMenu();
			int choice;
			std::cout << "\nEnter Choice : ";
			util::read<int>(choice);
			switch (choice)
			{
			case 1: std::cout << "Add Truck selected\n";
				break;
			case 2: std::cout << "View Truck Details selected\n";
				break;
			case 3: std::cout << "Assign Container to Truck selected\n"; 
				break;
			case 4: std::cout << "Move Container to Yard selected\n";
				break;
			case 5: std::cout << "Update Truck Status selected\n";
				break;
			case 6: std::cout << "List Available Trucks selected\n"; 
				break;
			case 7: std::cout << "List All Trucks selected\n"; 
				break;
			case 8: isMenuActive = false;
				break; 
			default: std::cout << "Invalid Input!\n";
				break;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}
	}
}

void UserInterface::handleCraneOperations()
{
	bool isMenuActive = true;
	while (isMenuActive)
	{
		try
		{
			m_menu->getCraneOperationsMenu();
			int choice;
			std::cout << "\nEnter Choice : ";
			util::read<int>(choice);

			switch (choice)
			{
			case 1: std::cout << "Add Crane selected\n"; 
				break;
			case 2: std::cout << "View Crane Details selected\n"; 
				break;
			case 3: std::cout << "Assign Container to Crane selected\n";
				break;
			case 4: std::cout << "Load Container to Ship selected\n";
				break;
			case 5: std::cout << "Unload Container from Ship selected\n"; 
				break;
			case 6: std::cout << "Update Crane Status selected\n"; 
				break;
			case 7: std::cout << "List Available Cranes selected\n"; 
				break;
			case 8: std::cout << "List All Cranes selected\n";
				break;
			case 9: isMenuActive = false;
				break; 
			default: std::cout << "Invalid Input!\n"; 
				break;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}
	}
}

void UserInterface::getUserList()
{
	std::vector<std::string> userList;
	userList = m_dockUManController->getUserList();
	displayUserList(userList);
}

void UserInterface::displayUserList(std::vector<std::string>& userList)
{
	for (std::vector<std::string>::iterator iterator = userList.begin(); iterator != userList.end(); iterator++)
	{
		std::cout << *iterator << std::endl;
	}
}

Enums::ProcessStatus UserInterface::deactivateUser(std::string& userId)
{
	return m_dockUManController->deactivateUser(userId);
}



