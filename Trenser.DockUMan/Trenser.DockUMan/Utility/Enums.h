/*
 * File: Enums.h
 * Description: Defines all enumerations used across the DockUMan system including user roles, statuses, and operational types
 * Author: Akish Babu
 * Created: 02-Apr-2026
 */
#pragma once

namespace Enums {

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
	enum class ProcessStatus
	{
		FAILED,
		SUCCESS
	};
	enum class UserStatus
	{
		ACTIVE,
		INACTIVE,
		PENDING
	};
	enum class NotificationStatus
	{
		READ,
		UNREAD
	};
	enum class YardType
	{
		IMPORT,
		EXPORT
	};
	enum class YardBlockType
	{
		REEFER,
		HAZARDOUS,
		GENERAL,
		FRAGILE
	};
	enum class CraneStatus
	{
		ACTIVE,
		INACTIVE
	};
	enum class BillingStatus
	{
		PENDING,
		GENERATED,
		CANCELLED,
		SETTLED
	};
	enum class PaymentMethod
	{
		UPI,
		CARD,
		NETBANKING,
		CASH
	};
	enum class PaymentStatus
	{
		PAID,
		UNPAID,
		FAILED
	};
	enum class TruckStatus
	{
		ACTIVE,
		INACTIVE
	};
	enum class AvailabilityStatus
	{
		OCCUPIED,
		AVAILABLE
	};
	enum class DockStatus
	{
		ACTIVE,
		INACTIVE
	};
	enum class RequestStatus
	{
		ACCEPTED,
		REJECTED,
		PENDING
	};
	enum class ContainerStatus
	{
		ACTIVE,
		INACTIVE
	};
	enum class ContainerType
	{
		REEFER,
		HAZARDOUS,
		GENERAL,
		FRAGILE
	};
	enum class ContainerTransportType
	{
		IMPORT,
		EXPORT
	};
	enum class ShipStatus
	{
		ACTIVE,
		INACTIVE
	};
}

