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
}

