#include "DataStore.h"

const std::vector<std::shared_ptr<User>>& DataStore::getUsers() const 
{
    return m_users;
}

const std::vector<std::shared_ptr<Dock>>& DataStore::getDocks() const
{
    return m_docks;
}

const std::vector<std::shared_ptr<Yard>>& DataStore::getYard() const
{
    return m_yard;
}

const std::vector<std::shared_ptr<Container>>& DataStore::getContainers() const
{
    return m_containers;
}

const std::vector<std::shared_ptr<Crane>>& DataStore::getCranes() const
{
    return m_cranes;
}

const std::vector<std::shared_ptr<Truck>>& DataStore::getTrucks() const
{
    return m_trucks;
}

const std::vector<std::shared_ptr<Ship>>& DataStore::getShips() const
{
    return m_ships;
}

const std::vector<std::shared_ptr<Booking>>& DataStore::getBookings() const
{
    return m_bookings;
}

const std::vector<std::shared_ptr<BillAndPayment>>& DataStore::getBillAndPayments() const
{
    return m_billAndPayments;
}

const std::map<Enums::ContainerType, std::shared_ptr<Threshold>>& DataStore::getThresholds() const
{
    return m_thresholds;
}

const std::vector<std::shared_ptr<Notification>>& DataStore::getNotifications() const
{
    return m_notifications;
}

const std::vector<std::shared_ptr<Log>>& DataStore::getLogs() const
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

bool DataStore::addShip(const std::shared_ptr<Ship>& ship)
{
    m_ships.push_back(ship);
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
