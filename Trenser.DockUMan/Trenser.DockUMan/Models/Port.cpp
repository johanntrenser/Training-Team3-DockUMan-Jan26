#include "Port.h"

std::string Port::getPortName() const 
{
    return m_portName;
}

std::vector<std::shared_ptr<Dock>> Port::getDocks() const 
{
    return m_docks;
}

std::vector<std::shared_ptr<Yard>> Port::getYard() const 
{
    return m_yard;
}

std::vector<std::shared_ptr<Container>> Port::getContainers() const 
{
    return m_containers;
}

std::vector<std::shared_ptr<Crane>> Port::getCranes() const 
{
    return m_cranes;
}

std::vector<std::shared_ptr<Truck>> Port::getTrucks() const 
{
    return m_trucks;
}

std::vector<std::shared_ptr<Ship>> Port::getShips() const 
{
    return m_ships;
}

std::vector<std::shared_ptr<Booking>> Port::getBookings() const 
{
    return m_bookings;
}

std::vector<std::shared_ptr<BillAndPayment>> Port::getBillAndPayments() const 
{
    return m_billAndPayments;
}

std::map<Enums::ContainerType, std::shared_ptr<Threshold>> Port::getThresholds() const 
{
    return m_thresholds;
}

std::vector<std::shared_ptr<Notification>> Port::getNotifications() const 
{
    return m_notifications;
}

std::vector<std::shared_ptr<Log>> Port::getLogs() const
{
    return m_logs;
}

void Port::setPortName(const std::string& portName)
{
    m_portName = portName;
}

void Port::setDocks(const std::vector<std::shared_ptr<Dock>>& docks)
{
    m_docks = docks;
}

void Port::setYard(const std::vector<std::shared_ptr<Yard>>& yard) 
{
    m_yard = yard;
}

void Port::setContainers(const std::vector<std::shared_ptr<Container>>& containers)
{
    m_containers = containers;
}

void Port::setCranes(const std::vector<std::shared_ptr<Crane>>& cranes)
{
    m_cranes = cranes;
}

void Port::setTrucks(const std::vector<std::shared_ptr<Truck>>& trucks) 
{
    m_trucks = trucks;
}

void Port::setShips(const std::vector<std::shared_ptr<Ship>>& ships) 
{
    m_ships = ships;
}

void Port::setBookings(const std::vector<std::shared_ptr<Booking>>& bookings)
{
    m_bookings = bookings;
}

void Port::setBillAndPayments(const std::vector<std::shared_ptr<BillAndPayment>>& billAndPayments)
{
    m_billAndPayments = billAndPayments;
}

void Port::setThresholds(const std::map<Enums::ContainerType, std::shared_ptr<Threshold>>& thresholds) 
{
    m_thresholds = thresholds;
}

void Port::setNotifications(const std::vector<std::shared_ptr<Notification>>& notifications)
{
    m_notifications = notifications;
}

void Port::setLogs(const std::vector<std::shared_ptr<Log>>& logs) 
{
    m_logs = logs;
}
