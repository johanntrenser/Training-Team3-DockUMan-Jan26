/*
 * File: Container.h
 * Description: Defines the Container class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#pragma once
#include<iostream>
#include "User.h"

class Ship;

class Container
{
private:
	std::string m_containerId;
	Enums::ContainerType m_containerType;
	Enums::ContainerStatus m_containerStatus;
	Enums::ContainerTransportType m_transportType;
	double m_weight;
	std::string m_dateOfDeparture;
	std::string m_expiryDate;
	bool m_customsCleared;
	std::shared_ptr<Ship>m_shipOfDeparture;
	std::shared_ptr<User>m_pickupAgent;
public:
	Container() :m_containerId(""), m_weight(0.0), m_dateOfDeparture(""), m_expiryDate(""), m_customsCleared(false), m_shipOfDeparture(nullptr), m_pickupAgent(nullptr),m_containerType(Enums::ContainerType::GENERAL), m_containerStatus(Enums::ContainerStatus::ACTIVE),m_transportType(Enums::ContainerTransportType::IMPORT) {};
	Container(std::string containerId, double weight, std::string dateOfDeparture, std::string expiryDate, bool customsCleared, std::shared_ptr<Ship> shipOfDeparture, std::shared_ptr<User> pickupAgent, Enums::ContainerType containerType,Enums::ContainerStatus containerStatus,Enums::ContainerTransportType transportType) :
		m_containerId(containerId), m_weight(weight), m_dateOfDeparture(dateOfDeparture), m_expiryDate(expiryDate), m_customsCleared(customsCleared), m_shipOfDeparture(shipOfDeparture), m_pickupAgent(pickupAgent),m_containerType(containerType),m_containerStatus(containerStatus),m_transportType(transportType) {};
	std::string getContainerId() const;
	double getWeight() const;
	std::string getDateOfDeparture() const;
	std::string getExpiryDate() const;
	bool getCustomsCleared() const;
	std::shared_ptr<Ship> getShipOfDeparture() const;
	std::shared_ptr<User> getPickupAgent() const;
	Enums::ContainerType getContainerType() const;
	Enums::ContainerStatus getContainerStatus() const;
	Enums::ContainerTransportType getTransportType() const;
	void setContainerId(const std::string&);
	void setWeight(double);
	void setDateOfDeparture(const std::string&);
	void setExpiryDate(const std::string&);
	void setCustomsCleared(bool);
	void setShipOfDeparture(const std::shared_ptr<Ship>);
	void setPickupAgent(const std::shared_ptr<User>);
	void setContainerType(const Enums::ContainerType&);
	void setContainerStatus(const Enums::ContainerStatus&);
	void setTransportType(const Enums::ContainerTransportType&);
};

