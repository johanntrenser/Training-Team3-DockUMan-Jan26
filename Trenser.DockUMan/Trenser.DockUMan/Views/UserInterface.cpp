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
		//login function
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
			Enums::ProcessStatus processStatus=m_DockUManController->registerShippingAgent(userInformation,type,status);
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

void UserInterface::handleShippingAgentUserInput(std::vector<std::string>& userInformation) //error management
{
	std::string licenseNumber, id, name, password, email, phoneNumber;
	std::cout << "Enter id : "; //id generaator
	util::read(id);
	userInformation.push_back(id);
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
	std::cout << "Enter license Number : ";
	validator::validateLiscenseNumber(licenseNumber);
	userInformation.push_back(licenseNumber);
}

