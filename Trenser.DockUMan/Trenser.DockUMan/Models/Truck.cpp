#include "Truck.h"
using namespace std;

string Truck::getId() const
{
    return m_id;
}

void Truck::setId(const string& truckId)
{
    m_id = truckId;
}

shared_ptr<Container> Truck::getCurrentContainer() const
{
    return m_currentContainer;
}

void Truck::setCurrentContainer(shared_ptr<Container> container)
{
    m_currentContainer = container;
}

Enums::TruckStatus Truck::getStatus() const
{
    return m_status;
}

void Truck::setStatus(Enums::TruckStatus status)
{
    m_status = status;
}
Enums::AvailabilityStatus Truck::getAvailabilityStatus() const
{
    return m_availabilityStatus;
}

void Truck::setAvailabilityStatus(Enums::AvailabilityStatus status)
{
    m_availabilityStatus = status;
}
