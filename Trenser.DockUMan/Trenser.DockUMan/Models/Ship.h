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
	std::vector<std::shared_ptr<Container>> m_container;
	std::shared_ptr<User> m_shipManager;
	Enums::ShipStatus m_shipStatus;
	Enums::AvailabilityStatus m_availabilityStatus;
	std::string m_ETA;
	std::string m_ETD;
	std::shared_ptr<Dock> m_assignedDock;
public:
	Ship() :m_shipId(""), m_shipName(""), m_shipManager(nullptr), m_ETA(""), m_ETD(""),m_shipStatus(Enums::ShipStatus::ACTIVE),m_availabilityStatus(Enums::AvailabilityStatus::AVAILABLE) {};
	Ship(std::string shipId, std::string shipName, std::vector<std::shared_ptr<Container>> containers, std::shared_ptr<User> shipManager, std::string ETA, std::string ETD, std::shared_ptr<Dock> assignedDock, Enums::ShipStatus shipStatus, Enums::AvailabilityStatus availabilityStatus) :
		m_shipId(shipId), m_shipName(shipName), m_container(containers), m_shipManager(shipManager), m_ETA(ETA), m_ETD(ETD), m_assignedDock(assignedDock),m_shipStatus(shipStatus), m_availabilityStatus(availabilityStatus) { };
	std::string getShipId() const;
	std::string getShipName() const;
	std::vector<std::shared_ptr<Container>> getContainers() const;
	std::shared_ptr<User> getShipManager() const;
	std::string getETA() const;
	std::string getETD() const;
	std::string toString() const;
	std::shared_ptr<Dock> getAssignedDock() const;
	Enums::ShipStatus getShipStatus() const;
	Enums::AvailabilityStatus getAvailabilityStatus() const;
	void setShipId(const std::string&);
	void setShipName(const std::string&);
	void setContainers(const std::vector<std::shared_ptr<Container>>&);
	void setShipManager(const std::shared_ptr<User>&);
	void setETA(const std::string&);
	void setETD(const std::string&);
	void setAssignedDock(const std::shared_ptr<Dock>&);
	void getShipStatus(const Enums::ShipStatus&);
	void setAvailabilityStatus(const Enums::AvailabilityStatus&);
};

