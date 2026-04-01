#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Container.h"

class Truck
{
private:
    std::string m_id;
    std::shared_ptr<Container> m_currentContainer;
    Enums::TruckStatus m_status;
    Enums::AvailabilityStatus m_availabilityStatus;
public:
    Truck() : m_id(""), m_currentContainer(nullptr), m_status(Enums::TruckStatus::ACTIVE), m_availabilityStatus(Enums::AvailabilityStatus::AVAILABLE) {}
    Truck(std::string id, std::shared_ptr<Container> currentContainer, Enums::TruckStatus status, Enums::AvailabilityStatus availabilityStatus)
        : m_id(id), m_currentContainer(currentContainer), m_status(status), m_availabilityStatus(availabilityStatus) {}
    std::string getId() const;
    void setId(const std::string& truckId);
    std::shared_ptr<Container> getCurrentContainer() const;
    void setCurrentContainer(std::shared_ptr<Container> container);
    Enums::TruckStatus getStatus() const;
    void setStatus(Enums::TruckStatus status);
    Enums::AvailabilityStatus getAvailabilityStatus() const;
    void setAvailabilityStatus(Enums::AvailabilityStatus status);
};
