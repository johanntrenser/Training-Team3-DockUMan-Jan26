/*
 * File: Ship.cpp
 * Description: Implements getter and setter functions for the Ship model class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "Ship.h"
#include "Container.h"

std::string Ship::getShipId() const
{
    return m_shipId;
}

std::string Ship::getShipName() const
{
    return m_shipName;
}

std::vector<Container*> Ship::getContainers() const
{
    return m_container;
}

User* Ship::getShipManager() const
{
    return m_shipManager;
}

std::string Ship::getETA() const
{
    return m_ETA;
}

std::string Ship::getETD() const
{
    return m_ETD;
}

std::string Ship::toString() const
{
    return m_shipName + " : " + m_shipId;
}

Dock* Ship::getAssignedDock() const
{
    return m_assignedDock;
}

Enums::ShipStatus Ship::getShipStatus() const
{
    return m_shipStatus;
}

Enums::AvailabilityStatus Ship::getAvailabilityStatus() const
{
    return m_availabilityStatus;
}

void Ship::setShipId(const std::string& shipId)
{
    m_shipId = shipId;
}

void Ship::setShipName(const std::string& shipName)
{
    m_shipName = shipName;
}

void Ship::setContainers(const std::vector<Container*>& containers)
{
    m_container = containers;
}

void Ship::setShipManager(User* shipManager)
{
    m_shipManager = shipManager;
}

void Ship::setETA(const std::string& ETA)
{
    m_ETA = ETA;
}

void Ship::setETD(const std::string& ETD)
{
    m_ETD = ETD;
}

void Ship::setAssignedDock(Dock* assignedDock)
{
    m_assignedDock = assignedDock;
}

void Ship::getShipStatus(const Enums::ShipStatus& shipStatus)
{
    m_shipStatus = shipStatus;
}

void Ship::setAvailabilityStatus(const Enums::AvailabilityStatus& availableStatus)
{
    m_availabilityStatus = availableStatus;
}
