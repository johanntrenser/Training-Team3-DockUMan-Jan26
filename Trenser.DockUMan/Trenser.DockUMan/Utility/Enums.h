/*
 * File: Enums.h
 * Description: Defines all enumerations used across the DockUMan system including user roles, statuses, and operational types
 * Author: Akish Babu, Avinash M R
 * Created: 02-Apr-2026
 */
#pragma once
#include<iostream>

namespace Enums 
{
	//Defines different type of Users in the system
	enum class UserTypes
	{
		NOT_ASSIGNED,
		PICKUP_AGENT,
		PORT_AUTHORITY_ADMINISTRATOR,
		FINANCE_MANAGER,
		SHIPPING_AGENT,
		CUSTOMS_OFFICER,
		TERMINAL_OPERATOR,
		SHIP_MANAGER
	};
	//Represent the Result of Process Execution.
	enum class ProcessStatus
	{
		FAILED,
		SUCCESS
	};
	//Indicates the Users Current Status.
	enum class UserStatus
	{
		ACTIVE,
		INACTIVE,
		PENDING
	};
	//Tracks whether the notification has been read or not.
	enum class NotificationStatus
	{
		READ,
		UNREAD
	};
	//Specifies the types of Yard Block.
	enum class YardType
	{
		IMPORT,
		EXPORT
	};
	//Define the different types of yard blocks for Container storage.
	enum class YardBlockType
	{
		REEFER,
		HAZARDOUS,
		GENERAL,
		FRAGILE
	};
	//Indicates the Current Cranes Status.
	enum class CraneStatus
	{
		ACTIVE,
		INACTIVE
	};
	//Represents billing lifecycle states
	enum class BillingStatus
	{
		PENDING,
		GENERATED,
		CANCELLED,
		SETTLED
	};
	//Represents the Mode of Payment.
	enum class PaymentMethod
	{
		UPI,
		CARD,
		NETBANKING,
		CASH
	};
	//Indicate the status of a payment transaction
	enum class PaymentStatus
	{
		PAID,
		UNPAID,
		FAILED
	};
	//Represents the truck availability status
	enum class TruckStatus
	{
		ACTIVE,
		INACTIVE
	};
	//Tracks Ship availability or movement states
	enum class AvailabilityStatus
	{
		OCCUPIED,
		AVAILABLE,
		DOCKED,
		WAITING,
		DEPARTED
	};
	//Indicates Docks operational status
	enum class DockStatus
	{
		ACTIVE,
		INACTIVE
	};
	//Represents Request approval states for ShipDocking etc
	enum class RequestStatus
	{
		ACCEPTED,
		REJECTED,
		PENDING
	};
	//Indicates whether a container is active or not
	enum class ContainerStatus
	{
		ACTIVE,
		INACTIVE
	};
	//Defines the types of Containers
	enum class ContainerType
	{
		REEFER,
		HAZARDOUS,
		GENERAL,
		FRAGILE
	};
	//Specifies the Container transport type.
	enum class ContainerTransportType
	{
		IMPORT,
		EXPORT
	};
	//Indicates ship operational status
	enum class ShipStatus
	{
		ACTIVE,
		INACTIVE
	};
	//Converts availability status to human readable string
	inline std::string trackShipStatus(Enums::AvailabilityStatus status)
	{
		switch (status)
		{
		case Enums::AvailabilityStatus::AVAILABLE:
			return "Available";
		case Enums::AvailabilityStatus::DOCKED:
			return "Docked";
		case Enums::AvailabilityStatus::OCCUPIED:
			return "Occupied";
		case Enums::AvailabilityStatus::WAITING:
			return "Arrived";
		case Enums::AvailabilityStatus::DEPARTED:
			return "Departed";
		default:
			return "Not Available";
		}
	}
	//Converts User Type into human readable string
	inline std::string getUserTypeInString(Enums::UserTypes userType)
	{
		switch (userType)
		{
		case Enums::UserTypes::NOT_ASSIGNED:
			return "Not Assigned";
		case Enums::UserTypes::PICKUP_AGENT:
			return "Pickup Agent";
		case Enums::UserTypes::PORT_AUTHORITY_ADMINISTRATOR:
			return "Port Authority Administrator";
		case Enums::UserTypes::FINANCE_MANAGER:
			return "Finance Manager";
		case Enums::UserTypes::SHIPPING_AGENT:
			return "Shipping Agent";
		case Enums::UserTypes::CUSTOMS_OFFICER:
			return "Customs Officer";
		case Enums::UserTypes::TERMINAL_OPERATOR:
			return "Terminal Operator";
		case Enums::UserTypes::SHIP_MANAGER:
			return "Ship Manager";
		default:
			return "Unknown User Type";
		}
	}
	//Converts User Status into human readable string
	inline std::string getUserStatusInString(Enums::UserStatus status)
	{
		switch (status)
		{
		case Enums::UserStatus::ACTIVE:
			return "Active";
		case Enums::UserStatus::INACTIVE:
			return "Inactive";
		case Enums::UserStatus::PENDING:
			return "Pending";
		default:
			return "Unknown Status";
		}
	}
	//Converts User Type string into UserType Enum
	inline Enums::UserTypes getUserType(const std::string& userTypeString)
	{
		if (userTypeString == "Not Assigned")
			return Enums::UserTypes::NOT_ASSIGNED;
		else if (userTypeString == "Pickup Agent")
			return Enums::UserTypes::PICKUP_AGENT;
		else if (userTypeString == "Port Authority Administrator")
			return Enums::UserTypes::PORT_AUTHORITY_ADMINISTRATOR;
		else if (userTypeString == "Finance Manager")
			return Enums::UserTypes::FINANCE_MANAGER;
		else if (userTypeString == "Shipping Agent")
			return Enums::UserTypes::SHIPPING_AGENT;
		else if (userTypeString == "Customs Officer")
			return Enums::UserTypes::CUSTOMS_OFFICER;
		else if (userTypeString == "Terminal Operator")
			return Enums::UserTypes::TERMINAL_OPERATOR;
		else if (userTypeString == "Ship Manager")
			return Enums::UserTypes::SHIP_MANAGER;
		else
			return Enums::UserTypes::NOT_ASSIGNED;
	}
	//Converts User Status string into UserStatus Enum
	inline Enums::UserStatus getUserStatus(const std::string& statusStr)
	{
		if (statusStr == "Active")
			return Enums::UserStatus::ACTIVE;
		else if (statusStr == "Inactive")
			return Enums::UserStatus::INACTIVE;
		else if (statusStr == "Pending")
			return Enums::UserStatus::PENDING;
		else
			return Enums::UserStatus::INACTIVE;
	}
}