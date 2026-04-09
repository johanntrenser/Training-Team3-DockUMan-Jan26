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

std::vector<std::shared_ptr<Container>> Ship::getContainers() const
{
    return m_container;
}

std::shared_ptr<User> Ship::getShipManager() const
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

std::shared_ptr<Dock> Ship::getAssignedDock() const
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

void Ship::setContainers(const std::vector<std::shared_ptr<Container>>& containers)
{
    m_container = containers;
}

void Ship::setShipManager(const std::shared_ptr<User>& shipManager)
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

void Ship::setAssignedDock(const std::shared_ptr<Dock>& assignedDock)
{
    m_assignedDock = assignedDock;
}

void Ship::getShipStatus(const Enums::ShipStatus& shipStatus)
{
    m_shipStatus = shipStatus;
}

void Ship::getAvailabilityStatus(const Enums::AvailabilityStatus& availableStatus)
{
    m_availabilityStatus = availableStatus;
}
