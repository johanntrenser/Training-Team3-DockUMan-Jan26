#include "Dock.h"
#include "Ship.h"

std::string Dock::getId() const
{
    return m_id;
}

Enums::DockStatus Dock::getStatus() const
{
    return m_status;
}

std::shared_ptr<Ship> Dock::getShip() const
{
    return m_ship;
}

std::vector<std::shared_ptr<Crane>> Dock::getCranes() const
{
    return m_cranes;
}

void Dock::setId(const std::string& id)
{
    m_id = id;
}

void Dock::setStatus(Enums::DockStatus status)
{
    m_status = status;
}

void Dock::setShip(const std::shared_ptr<Ship>& ship)
{
    m_ship = ship;
}

void Dock::setCranes(const std::vector<std::shared_ptr<Crane>>& cranes)
{
    m_cranes = cranes;
}
