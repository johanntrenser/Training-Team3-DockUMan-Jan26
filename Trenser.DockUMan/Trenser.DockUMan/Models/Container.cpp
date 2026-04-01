#include "Container.h"
#include "Ship.h"

std::string Container::getContainerId() const
{
    return m_containerId;
}

double Container::getWeight() const
{
    return m_weight;
}

std::string Container::getDateOfDeparture() const
{
    return m_dateOfDeparture;
}

std::string Container::getExpiryDate() const
{
    return m_expiryDate;
}

bool Container::getCustomsCleared() const
{
    return false;
}

std::shared_ptr<Ship> Container::getShipOfDeparture() const
{
    return m_shipOfDeparture;
}

std::shared_ptr<User> Container::getPickupAgent() const
{
    return m_pickupAgent;
}

Enums::ContainerType Container::getContainerType() const
{
    return m_containerType;
}

Enums::ContainerStatus Container::getContainerStatus() const
{
    return m_containerStatus;
}

Enums::ContainerTransportType Container::getTransportType() const
{
    return m_transportType;
}

void Container::setContainerId(const std::string& containerId)
{
    m_containerId = containerId;
}

void Container::setWeight(double weight)
{
    m_weight = weight;
}

void Container::setDateOfDeparture(const std::string& dateOfDeparture)
{
    m_dateOfDeparture = dateOfDeparture;
}

void Container::setExpiryDate(const std::string& expiryDate)
{
    m_expiryDate = expiryDate;
}

void Container::setCustomsCleared(bool customsCleared)
{
    m_customsCleared = customsCleared;
}

void Container::setShipOfDeparture(std::shared_ptr<Ship> shipOfDeparture)
{
    m_shipOfDeparture = shipOfDeparture;
}

void Container::setPickupAgent(std::shared_ptr<User> pickupAgent)
{
    m_pickupAgent = pickupAgent;
}

void Container::setContainerType(const Enums::ContainerType& containerType)
{
    m_containerType = containerType;
}

void Container::setContainerStatus(const Enums::ContainerStatus& containerStatus)
{
    m_containerStatus = containerStatus;
}

void Container::setTransportType(const Enums::ContainerTransportType& transportType)
{
    m_transportType = transportType;
}




