#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Crane.h"
#include "Enums.h"

class Ship;

class Dock
{
private:
    std::string m_id;
    Enums::DockStatus m_status;
    Enums::AvailabilityStatus m_availabilityStatus;
    std::shared_ptr<Ship> m_ship;
    std::vector<std::shared_ptr<Crane>> m_cranes;
public:
    Dock()
        : m_id{ "" }, m_ship{ nullptr }, m_status{ Enums::DockStatus::ACTIVE }, m_availabilityStatus{Enums::AvailabilityStatus::AVAILABLE} {
    }
    Dock(std::string id, Enums::DockStatus status, std::shared_ptr<Ship> ship, std::vector<std::shared_ptr<Crane>> cranes, Enums::AvailabilityStatus availabilityStatus)
        : m_id{ id }, m_status{ status }, m_ship{ ship }, m_cranes{ cranes }, m_availabilityStatus{availabilityStatus} {
    }
    std::string getId() const;
    Enums::DockStatus getStatus() const;
    std::shared_ptr<Ship> getShip() const;
    std::vector<std::shared_ptr<Crane>> getCranes() const;
    void setId(const std::string& id);
    void setStatus(Enums::DockStatus status);
    void setShip(const std::shared_ptr<Ship>& ship);
    void setCranes(const std::vector<std::shared_ptr<Crane>>& cranes);
};
