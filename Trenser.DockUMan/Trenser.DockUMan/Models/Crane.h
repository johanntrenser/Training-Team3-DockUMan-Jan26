/*
 * File: Crane.h
 * Description: Defines the Crane class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Container.h"

class Crane
{
private:
    std::string m_id;
    std::shared_ptr<Container> m_currentContainer;
    Enums::CraneStatus m_status;
    Enums::AvailabilityStatus m_availabilityStatus;
public:
    Crane() : m_id(""), m_currentContainer(nullptr), m_status(Enums::CraneStatus::ACTIVE), m_availabilityStatus(Enums::AvailabilityStatus::AVAILABLE){}
    Crane(std::string id, std::shared_ptr<Container> currentContainer, Enums::CraneStatus status, Enums::AvailabilityStatus availabilityStatus) 
        : m_id(id), m_currentContainer(currentContainer), m_status(status), m_availabilityStatus(availabilityStatus) {}
    std::string getId() const;
    void setId(const std::string& craneId);
    std::shared_ptr<Container> getCurrentContainer() const;
    void setCurrentContainer(std::shared_ptr<Container> container);
    Enums::CraneStatus getStatus() const;
    void setStatus(Enums::CraneStatus status);
    Enums::AvailabilityStatus getAvailabilityStatus() const;
    void setAvailabilityStatus(Enums::AvailabilityStatus status);
};
