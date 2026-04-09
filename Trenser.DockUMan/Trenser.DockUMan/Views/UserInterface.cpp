/*
 * File: UserInterface.cpp
 * Description: Handles user interface operations including authentication, 
				user management, and menu-driven interactions for DockUMan system
 * Author: Entire Team
 * Created: 02-Apr-2026
 */
#include "UserInterface.h"

 /*
  * Function: start
  * Description: Initializes and manages the authentication menu loop
  */
void UserInterface::start()
{
	bool isMenuActive = true;
	while (isMenuActive)
	{
		try
		{
			m_menu->getAuthenticationMenu();
			int choice;
			std::cout << "\nEnter Choice : ";
			util::read<int>(choice);
			handleAuthenticationOperation(choice,isMenuActive);
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception : " << e.what() << std::endl << std::endl;
		}
	}
}

/*
 * Function: handleAuthenticationOperation
 * Description: Processes user choice from authentication menu
 * Parameters:
 *    choice - selected menu option
 *    isMenuActive - controls menu loop execution
 */
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

/*
 * Function: authenticateUser
 * Description: Handles user login and redirects to respective menus upon success
 */
void UserInterface::authenticateUser()
{
	bool isMenuActive = true;
	while (isMenuActive)
	{
		try
		{
			std::string username,password,email;
			std::cout << "\nEnter User Email Id : ";
			util::read<std::string>(email);
			std::cout << "\nEnter Password : ";
			util::read<std::string>(password);
			if (m_dockUManController->handleAuthentication(username, password, email) == Enums::ProcessStatus::SUCCESS)
			{
				std::cout << "User Login Success! Welcome user : " << username << std::endl;
				isMenuActive = false;
				handleMenus(getUserType(username));
			}
			else
			{
				std::cout << "Invalid credentials! " << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}
	}
}

/*
 * Function: registerShippingAgentUI
 * Description: Handles UI flow for registering a shipping agent
 */
void UserInterface::registerShippingAgentUI()
{
	try
	{ 
		std::vector<std::string> userInformation;
		Enums::UserTypes type = Enums::UserTypes::SHIPPING_AGENT;
		Enums::UserStatus status = Enums::UserStatus::PENDING;
		handleShippingAgentUserInput(userInformation);
		Enums::ProcessStatus processStatus = m_dockUManController->registerShippingAgent(userInformation, type, status);
		if (processStatus == Enums::ProcessStatus::SUCCESS)
		{
			std::cout << "User Created Succesfull!" << std::endl;
		}
		else
		{
			std::cout << "User Creation Failed!" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}

/*
 * Function: handleCommonUserInput
 * Description: Collects and validates common user details
 * Parameters:
 *    userInformation - vector storing user data
 *    name - user name
 *    password - user password
 *    email - user email
 *    phoneNumber - user phone number
 */
void UserInterface::handleCommonUserInput(std::vector<std::string>& userInformation,std::string& name, std::string& password, std::string& email, std::string& phoneNumber)
{
	std::cout << "Enter Name :";
	util::read(name);
	userInformation.push_back(name);
	std::cout << "Enter pasword : ";
	validator::validatePassword(password);
	userInformation.push_back(password);
	std::cout << "Enter email : ";
	validator::validateEmail(email);
	while (m_dockUManController->IsEmailIdUnique(email) != Enums::ProcessStatus::SUCCESS)
	{
		std::cout << "Email already exists\nTry Again\n";
		std::cout << "Enter email : ";
		validator::validateEmail(email);
	}
	userInformation.push_back(email);
	std::cout << "Enter phone number : ";
	validator::validatePhoneNumber(phoneNumber);
	while (m_dockUManController->IsPhoneNumberUnique(phoneNumber) != Enums::ProcessStatus::SUCCESS)
	{
		std::cout << "Phone number already exists\nTry Again\n";
		std::cout << "Enter phone number : ";
		validator::validatePhoneNumber(phoneNumber);
	}
	userInformation.push_back(phoneNumber);
}

/*
 * Function: handleMenus
 * Description: Routes user to appropriate menu based on user type
 * Parameters:
 *    userType - type of logged-in user
 */
void UserInterface::handleMenus(Enums::UserTypes userType)
{
	if (userType == Enums::UserTypes::PICKUP_AGENT)
	{
		//call pickup agent menu
	}
	else if (userType == Enums::UserTypes::PORT_AUTHORITY_ADMINISTRATOR)
	{
		handleAdminMenu();
	}
	else if (userType == Enums::UserTypes::SHIPPING_AGENT)
	{
		handleAdminMenu(); // change later to shipping agent menu. set as admin menu for testing purpose
	}
	else if (userType == Enums::UserTypes::SHIP_MANAGER)
	{
		//call ship manager menu
	}
	else if (userType == Enums::UserTypes::TERMINAL_OPERATOR)
	{
		handleTerminalOperatorMenu();
	}
	else if (userType == Enums::UserTypes::FINANCE_MANAGER)
	{
		//call finance manager menu
	}
	else if (userType == Enums::UserTypes::CUSTOMS_OFFICER)
	{
		//call custom officer menu
	}
}

/*
 * Function: getUserType
 * Description: Retrieves user type based on username
 * Parameters:
 *    username - user identifier
 * Returns:
 *    User type
 */
Enums::UserTypes UserInterface::getUserType(std::string& username)
{
	return m_dockUManController->getUserType(username);
}

/*
 * Function: handleShippingAgentUserInput
 * Description: Collects input specific to shipping agent registration
 * Parameters:
 *    userInformation - vector storing user data
 */
void UserInterface::handleShippingAgentUserInput(std::vector<std::string>& userInformation) 
{
	std::string licenseNumber, id, name, password, email, phoneNumber;
	std::cout << "Enter id : "; //Add id generaator
	util::read(id);
	userInformation.push_back(id);
	handleCommonUserInput(userInformation,name,password,email,phoneNumber);
	std::cout << "Enter license Number : ";
	validator::validateLicenseNumber(licenseNumber);
	while (m_dockUManController->IsLicenseNumberUnique(licenseNumber) != Enums::ProcessStatus::SUCCESS)
	{
		std::cout << "License number already exists\nTry Again\n";
		std::cout << "Enter license Number : ";
		validator::validateLicenseNumber(licenseNumber);
	}
	userInformation.push_back(licenseNumber);
}

/*
 * Function: handleCustomsOfficerUserInput
 * Description: Collects input specific to customs officer registration
 * Parameters:
 *    userInformation - vector storing user data
 */
void UserInterface::handleCustomsOfficerUserInput(std::vector<std::string>& userInformation)
{
	std::string badgeNumber, id, name, password, email, phoneNumber;
	std::cout << "Enter id : "; // Add id generator
	util::read(id);
	userInformation.push_back(id);
	handleCommonUserInput(userInformation, name, password, email, phoneNumber);
	std::cout << "Enter badge number : ";
	/*validator::validateBadgeNumber(badgeNumber); */
	//need research
	while (m_dockUManController->IsBadgeNumberUnique(badgeNumber) != Enums::ProcessStatus::SUCCESS)
	{
		std::cout << "Badge number already exists\nTry Again\n";
		std::cout << "Enter badge number : ";
		/*validator::validateBadgeNumber(badgeNumber); */
	}
	userInformation.push_back(badgeNumber);
}

/*
 * Function: handleShipManagerUserInput
 * Description: Collects input for ship manager registration
 * Parameters:
 *    userInformation - vector storing user data
 */
void UserInterface::handleShipManagerUserInput(std::vector<std::string>& userInformation)
{
	std::string id, name, password, email, phoneNumber;
	std::cout << "Enter id : ";
	util::read(id);
	userInformation.push_back(id);
	handleCommonUserInput(userInformation, name, password, email, phoneNumber);
}

/*
 * Function: handlePickupAgentUserInput
 * Description: Collects input for pickup agent registration
 * Parameters:
 *    userInformation - vector storing user data
 */
void UserInterface::handlePickupAgentUserInput(std::vector<std::string>& userInformation)
{
	std::string id, name, password, email, phoneNumber;
	std::cout << "Enter id : ";
	util::read(id);
	userInformation.push_back(id);
	handleCommonUserInput(userInformation, name, password, email, phoneNumber);
}

/*
 * Function: handlePortAuthorityAdminUserInput
 * Description: Collects input for port authority administrator registration
 * Parameters:
 *    userInformation - vector storing user data
 */
void UserInterface::handlePortAuthorityAdminUserInput(std::vector<std::string>& userInformation)
{
	std::string id, name, password, email, phoneNumber;
	std::cout << "Enter id : ";
	util::read(id);
	userInformation.push_back(id);
	handleCommonUserInput(userInformation, name, password, email, phoneNumber);
}

/*
 * Function: handleFinanceManagerUserInput
 * Description: Collects input for finance manager registration
 * Parameters:
 *    userInformation - vector storing user data
 */
void UserInterface::handleFinanceManagerUserInput(std::vector<std::string>& userInformation)
{
	std::string id, name, password, email, phoneNumber;
	std::cout << "Enter id : ";
	util::read(id);
	userInformation.push_back(id);
	handleCommonUserInput(userInformation, name, password, email, phoneNumber);
}

/*
 * Function: handleTerminalOperatorUserInput
 * Description: Collects input for terminal operator registration
 * Parameters:
 *    userInformation - vector storing user data
 */
void UserInterface::handleTerminalOperatorUserInput(std::vector<std::string>& userInformation)
{
	std::string id, name, password, email, phoneNumber;
	std::cout << "Enter id : ";
	util::read(id);
	userInformation.push_back(id);
	handleCommonUserInput(userInformation, name, password, email, phoneNumber);
}

/*
 * Function: logoutUser
 * Description: Logs out the currently authenticated user
 */
void UserInterface::logoutUser()
{
	m_dockUManController->logoutUser();
}

/*
 * Function: handleAdminMenu
 * Description: Displays and processes admin menu operations
 */
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
				addUserUI();
				break;
			case 2:
				std::cout << "View User List selected\n";
				break;
			case 3:
				updateUserDetailsUI();
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
				logoutUser();
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

/*
 * Function: handleTerminalOperatorMenu
 * Description: Displays and processes terminal operator menu operations
 */
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

/*
 * Function: handleTruckOperations
 * Description: Handles truck-related operations menu
 */
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

/*
 * Function: handleCraneOperations
 * Description: Handles crane-related operations menu
 */
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

/*
 * Function: handleUserUpdate
 * Description: Handles updating user details based on role
 * Parameters:
 *    role - user role
 */
void UserInterface::handleUserUpdate(Enums::UserTypes role)
{
	std::string userId;
	std::vector<std::string> users = m_dockUManController->getUserListByRole(role);
	displayList(users);
	std::cout << "Enter id of user to update: ";
	util::read(userId);
	std::vector<std::string> userDetails = m_dockUManController->getUserDetailByIdAndType(userId, role);
	if (userDetails.empty())
	{
		std::cout << "Invalid user id or user doesn't exist!!" << std::endl;
		return;
	}
	displayList(userDetails);
	updateUserAttributeUI(userId);
}

/*
 * Function: getUserList
 * Description: Retrieves and displays all users
 */
void UserInterface::getUserList()
{
	std::vector<std::string> userList;
	userList = m_dockUManController->getUserList();
	displayList(userList);
}

/*
 * Function: displayList
 * Description: Displays a list of strings
 * Parameters:
 *    list - vector of strings to display
 */
void UserInterface::displayList(std::vector<std::string>& list)
{
	for (std::vector<std::string>::iterator iterator = list.begin(); iterator != list.end(); iterator++)
	{
		std::cout << *iterator << std::endl;
	}
}

/*
 * Function: updateUserDetailsUI
 * Description: Handles UI for updating user details
 */
void UserInterface::updateUserDetailsUI()
{
	try
	{
		int userRoleChoice;
		m_menu->getUserRolesMenu();
		std::cout << "\nEnter Choice : ";
		util::read<int>(userRoleChoice);
		switch (userRoleChoice)
		{
		case 1:
			handleUserUpdate(Enums::UserTypes::FINANCE_MANAGER);
			break;
		case 2:
			handleUserUpdate(Enums::UserTypes::PORT_AUTHORITY_ADMINISTRATOR);
			break;
		case 3:
			handleUserUpdate(Enums::UserTypes::CUSTOMS_OFFICER);
			break;
		case 4:
			handleUserUpdate(Enums::UserTypes::TERMINAL_OPERATOR);
			break;
		case 5:
			handleUserUpdate(Enums::UserTypes::SHIP_MANAGER);
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

/*
 * Function: changeCurrentUserPassword
 * Description: Changes password of the current user
 * Returns:
 *    Process status
 */
Enums::ProcessStatus UserInterface::changeCurrentUserPassword()
{
	std::string newPassword;
	std::cout << "Enter new password: ";
	util::read(newPassword);
	validator::validatePassword(newPassword);
	return m_dockUManController->changeCurrentUserPassword(newPassword);
}

/*
 * Function: updateUserAttributeUI
 * Description: Updates specific user attributes like email or phone number
 * Parameters:
 *    userId - ID of the user to update
 */
void UserInterface::updateUserAttributeUI(std::string& userId)
{
	int choice;
	Enums::ProcessStatus processStatus;
	std::string updatedAttribute;
	try
	{
		m_menu->getUpdateDetailsMenu();
		util::read<int>(choice);
		switch (choice)
		{
		case 1:
			std::cout << "Enter the updated email id: ";
			util::read(updatedAttribute);
			validator::validateEmail(updatedAttribute);
			while (m_dockUManController->IsEmailIdUnique(updatedAttribute) != Enums::ProcessStatus::SUCCESS)
			{
				std::cout << "Email already exists\nTry Again\n";
				std::cout << "Enter email : ";
				validator::validateEmail(updatedAttribute);
			}
			processStatus = m_dockUManController->updatedUserEmailId(userId, updatedAttribute);
			break;
		case 2:
			std::cout << "Enter the updated phone no: ";
			util::read(updatedAttribute);
			validator::validatePhoneNumber(updatedAttribute);
			while (m_dockUManController->IsPhoneNumberUnique(updatedAttribute) != Enums::ProcessStatus::SUCCESS)
			{
				std::cout << "Phone number already exists\nTry Again\n";
				std::cout << "Enter phone number : ";
				validator::validatePhoneNumber(updatedAttribute);
			}
			processStatus = m_dockUManController->updatedUserPhoneNumber(userId, updatedAttribute);
			break;
		default:
			std::cout << "Invalid choice!!" << std::endl;
			break;
		}
		if (processStatus == Enums::ProcessStatus::SUCCESS)
		{
			std::cout << "Updation Operation Successfull" << std::endl;
		}
		else
		{
			std::cout << "Updation Operation Failed!!" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}

/*
 * Function: deactivateUser
 * Description: Deactivates a user account
 * Parameters:
 *    userId - ID of the user
 * Returns:
 *    Process status
 */
Enums::ProcessStatus UserInterface::deactivateUser(std::string& userId)
{
	return m_dockUManController->deactivateUser(userId);
}

/*
 * Function: approveUser
 * Description: Approves a user account
 * Parameters:
 *    userId - ID of the user
 * Returns:
 *    Process status
 */
Enums::ProcessStatus UserInterface::approveUser(std::string& userId)
{
	return m_dockUManController->approveUser(userId);
}

/*
 * Function: addUserUI
 * Description: Handles UI flow for adding new users of different roles
 */
void UserInterface::addUserUI()
{
	try
	{
		std::vector<std::string> userInformation;
		Enums::UserTypes type;
		Enums::UserStatus status = Enums::UserStatus::ACTIVE;
		int typeChoice;
		m_menu->getAddUserMenu();
		util::read<int>(typeChoice);
		switch (typeChoice)
		{
		case 1:
			type = Enums::UserTypes::PICKUP_AGENT;
			handlePickupAgentUserInput(userInformation);
			break;
		case 2:
			type = Enums::UserTypes::PORT_AUTHORITY_ADMINISTRATOR;
			handlePortAuthorityAdminUserInput(userInformation);
			break;
		case 3:
			type = Enums::UserTypes::SHIPPING_AGENT;
			handleShippingAgentUserInput(userInformation);
			break;
		case 4:
			type = Enums::UserTypes::SHIP_MANAGER;
			handleShipManagerUserInput(userInformation); 
			break;
		case 5:
			type = Enums::UserTypes::TERMINAL_OPERATOR;
			handleTerminalOperatorUserInput(userInformation); 
			break;
		case 6:
			type = Enums::UserTypes::FINANCE_MANAGER;
			handleFinanceManagerUserInput(userInformation);
			break;
		case 7:
			type = Enums::UserTypes::CUSTOMS_OFFICER;
			handleCustomsOfficerUserInput(userInformation); 
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
			return;
		}
		Enums::ProcessStatus processStatus = m_dockUManController->addUser(userInformation, type, status);
		if (processStatus == Enums::ProcessStatus::SUCCESS)
		{
			std::cout << "User Created Successfully!" << std::endl;
		}
		else
		{
			std::cout << "User Creation Failed!" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}
