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
		//call menu
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
		//call menu
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
	handlCommonUserInput(userInformation,name,password,email,phoneNumber);
	std::cout << "Enter id : "; //id generaator
	util::read(id);
	userInformation.push_back(id);
	std::cout << "Enter license Number : ";
	validator::validateLiscenseNumber(licenseNumber);
	userInformation.push_back(licenseNumber);
}

void UserInterface::logoutUser()
{
	m_dockUManController->logoutUser();
}

