#include "DataStore.h"

std::vector<std::shared_ptr<Dock>> DataStore::getDocks() const
{
    return m_docks;
}

std::vector<std::shared_ptr<Yard>> DataStore::getYard() const
{
    return m_yard;
}

std::vector<std::shared_ptr<Container>> DataStore::getContainers() const
{
    return m_containers;
}

std::vector<std::shared_ptr<Crane>> DataStore::getCranes() const
{
    return m_cranes;
}

std::vector<std::shared_ptr<Truck>> DataStore::getTrucks() const
{
    return m_trucks;
}

std::vector<std::shared_ptr<Ship>> DataStore::getShips() const
{
    return m_ships;
}

std::vector<std::shared_ptr<Booking>> DataStore::getBookings() const
{
    return m_bookings;
}

std::vector<std::shared_ptr<BillAndPayment>> DataStore::getBillAndPayments() const
{
    return m_billAndPayments;
}

std::map<Enums::ContainerType, std::shared_ptr<Threshold>> DataStore::getThresholds() const
{
    return m_thresholds;
}

std::vector<std::shared_ptr<Notification>> DataStore::getNotifications() const
{
    return m_notifications;
}

std::vector<std::shared_ptr<Log>> DataStore::getLogs() const
{
    return m_logs;
}

std::shared_ptr<User> DataStore::getUser(std::string& username)
{
    for (std::vector<std::shared_ptr<User>>::iterator iterator = m_users.begin();iterator!=m_users.end();iterator++)
    {
        if ((*iterator)->getName() == username)
        {
            return (*iterator);
        }
    }
    return nullptr;
}

bool DataStore::addUser(const std::shared_ptr<User>& agent)
{
        m_users.push_back(agent);
        return true;
}

void DataStore::setDocks(const std::vector<std::shared_ptr<Dock>>& docks)
{
    m_docks = docks;
}

void DataStore::setYard(const std::vector<std::shared_ptr<Yard>>& yard)
{
    m_yard = yard;
}

void DataStore::setContainers(const std::vector<std::shared_ptr<Container>>& containers)
{
    m_containers = containers;
}

void DataStore::setCranes(const std::vector<std::shared_ptr<Crane>>& cranes)
{
    m_cranes = cranes;
}

void DataStore::setTrucks(const std::vector<std::shared_ptr<Truck>>& trucks)
{
    m_trucks = trucks;
}

void DataStore::setShips(const std::vector<std::shared_ptr<Ship>>& ships)
{
    m_ships = ships;
}

void DataStore::setBookings(const std::vector<std::shared_ptr<Booking>>& bookings)
{
    m_bookings = bookings;
}

void DataStore::setBillAndPayments(const std::vector<std::shared_ptr<BillAndPayment>>& billAndPayments)
{
    m_billAndPayments = billAndPayments;
}

void DataStore::setThresholds(const std::map<Enums::ContainerType, std::shared_ptr<Threshold>>& thresholds)
{
    m_thresholds = thresholds;
}

void DataStore::setNotifications(const std::vector<std::shared_ptr<Notification>>& notifications)
{
    m_notifications = notifications;
}

void DataStore::setLogs(const std::vector<std::shared_ptr<Log>>& logs)
{
    m_logs = logs;
}

void DataStore::setCurrentUser(const std::shared_ptr<User>& user)
{
    m_currentUser = user;
}

DataStore& DataStore::getInstance()
{
    static DataStore instance;
    return instance;
}
