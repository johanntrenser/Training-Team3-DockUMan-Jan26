/*
 * File: Ship.h
 * Description: Defines the Ship class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "User.h"
#include "Dock.h"

class Container;

class Ship
{
private:
	std::string m_shipId;
	std::string m_shipName;
	std::vector<Container*> m_container;
	User* m_shipManager;
	Enums::ShipStatus m_shipStatus;
	Enums::AvailabilityStatus m_availabilityStatus;
	std::string m_ETA;
	std::string m_ETD;
	Dock* m_assignedDock;
public:
	Ship() :
		m_shipId(""),
		m_shipName(""),
		m_shipManager(nullptr),
		m_ETA(""),
		m_ETD(""),
		m_shipStatus(Enums::ShipStatus::ACTIVE),
		m_availabilityStatus(Enums::AvailabilityStatus::AVAILABLE),
		m_assignedDock(nullptr) {};
	Ship(std::string shipId, std::string shipName, std::vector<Container*> containers, User* shipManager, std::string ETA, std::string ETD, Dock* assignedDock, Enums::ShipStatus shipStatus, Enums::AvailabilityStatus availabilityStatus) :
		m_shipId(shipId), m_shipName(shipName), m_container(containers), m_shipManager(shipManager), m_ETA(ETA), m_ETD(ETD), m_assignedDock(assignedDock),m_shipStatus(shipStatus), m_availabilityStatus(availabilityStatus) { };
	std::string getShipId() const;
	std::string getShipName() const;
	std::vector<Container*> getContainers() const;
	User* getShipManager() const;
	std::string getETA() const;
	std::string getETD() const;
	std::string toString() const;
	Dock* getAssignedDock() const;
	Enums::ShipStatus getShipStatus() const;
	Enums::AvailabilityStatus getAvailabilityStatus() const;
	void setShipId(const std::string&);
	void setShipName(const std::string&);
	void setContainers(const std::vector<Container*>&);
	void setShipManager(User*);
	void setETA(const std::string&);
	void setETD(const std::string&);
	void setAssignedDock(Dock*);
	void getShipStatus(const Enums::ShipStatus&);
	void setAvailabilityStatus(const Enums::AvailabilityStatus&);
};

