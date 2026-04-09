/*
 * File: DataStore.cpp
 * Description: Manages in-memory storage and retrieval of system entities such as users, docks, containers, and transactions
 * Author: Entire Team
 * Created: 30-Mar-2026
 */
#include "DataStore.h"

 /*
  * Function: getUsers
  * Description: Retrieves all users from the data store
  * Returns:
  *    Reference to vector of users
  */
const std::vector<std::shared_ptr<User>>& DataStore::getUsers() const 
{
    return m_users;
}

/*
 * Function: getDocks
 * Description: Retrieves all docks from the data store
 * Returns:
 *    Reference to vector of docks
 */
const std::vector<std::shared_ptr<Dock>>& DataStore::getDocks() const
{
    return m_docks;
}

/*
 * Function: getYard
 * Description: Retrieves all yard data
 * Returns:
 *    Reference to vector of yard objects
 */
const std::vector<std::shared_ptr<Yard>>& DataStore::getYard() const
{
    return m_yard;
}

/*
 * Function: getContainers
 * Description: Retrieves all containers
 * Returns:
 *    Reference to vector of containers
 */
const std::vector<std::shared_ptr<Container>>& DataStore::getContainers() const
{
    return m_containers;
}

/*
 * Function: getCranes
 * Description: Retrieves all cranes
 * Returns:
 *    Reference to vector of cranes
 */
const std::vector<std::shared_ptr<Crane>>& DataStore::getCranes() const
{
    return m_cranes;
}

/*
 * Function: getTrucks
 * Description: Retrieves all trucks
 * Returns:
 *    Reference to vector of trucks
 */
const std::vector<std::shared_ptr<Truck>>& DataStore::getTrucks() const
{
    return m_trucks;
}

/*
 * Function: getShips
 * Description: Retrieves all ships
 * Returns:
 *    Reference to vector of ships
 */
const std::vector<std::shared_ptr<Ship>>& DataStore::getShips() const
{
    return m_ships;
}

/*
 * Function: getBookings
 * Description: Retrieves all bookings
 * Returns:
 *    Reference to vector of bookings
 */
const std::vector<std::shared_ptr<Booking>>& DataStore::getBookings() const
{
    return m_bookings;
}

/*
 * Function: getBillAndPayments
 * Description: Retrieves all billing and payment records
 * Returns:
 *    Reference to vector of bill and payment objects
 */
const std::vector<std::shared_ptr<BillAndPayment>>& DataStore::getBillAndPayments() const
{
    return m_billAndPayments;
}

/*
 * Function: getThresholds
 * Description: Retrieves container threshold configurations
 * Returns:
 *    Map of container types to threshold objects
 */
const std::map<Enums::ContainerType, std::shared_ptr<Threshold>>& DataStore::getThresholds() const
{
    return m_thresholds;
}

/*
 * Function: getNotifications
 * Description: Retrieves all notifications
 * Returns:
 *    Reference to vector of notifications
 */
const std::vector<std::shared_ptr<Notification>>& DataStore::getNotifications() const
{
    return m_notifications;
}

/*
 * Function: getLogs
 * Description: Retrieves all system logs
 * Returns:
 *    Reference to vector of logs
 */
const std::vector<std::shared_ptr<Log>>& DataStore::getLogs() const
{
    return m_logs;
}

/*
 * Function: getUserByEmail
 * Description: Retrieves a user based on email
 * Parameters:
 *    email - email of the user
 * Returns:
 *    Shared pointer to user if found, otherwise nullptr
 */
std::shared_ptr<User> DataStore::getUserByEmail(std::string& email)
{
    for (std::vector<std::shared_ptr<User>>::iterator iterator = m_users.begin();iterator != m_users.end(); ++iterator)
    {
        if ((*iterator)->getEmail() == email)
        {
            return (*iterator);
        }
    }
    return nullptr;
}

/*
 * Function: getUserById
 * Description: Retrieves a user based on user ID
 * Parameters:
 *    userId - ID of the user
 * Returns:
 *    Shared pointer to user if found, otherwise nullptr
 */
std::shared_ptr<User> DataStore::getUserById(std::string& userId)
{
    for (std::vector<std::shared_ptr<User>>::iterator iterator = m_users.begin(); iterator != m_users.end(); ++iterator)
    {
        if ((*iterator)->getId() == userId)
        {
            return (*iterator);
        }
    }
    return nullptr;
}

/*
 * Function: addUser
 * Description: Adds a new user to the data store
 * Parameters:
 *    agent - shared pointer to user object
 * Returns:
 *    True if added successfully
 */
bool DataStore::addUser(const std::shared_ptr<User> agent)
{
    m_users.push_back(agent);
    return true;
}

/*
 * Function: setDocks
 * Description: Sets the dock data in the store
 * Parameters:
 *    docks - vector of dock objects
 */
void DataStore::setDocks(const std::vector<std::shared_ptr<Dock>>& docks)
{
    m_docks = docks;
}

/*
 * Function: setYard
 * Description: Sets the yard data
 * Parameters:
 *    yard - vector of yard objects
 */
void DataStore::setYard(const std::vector<std::shared_ptr<Yard>>& yard)
{
    m_yard = yard;
}

/*
 * Function: setContainers
 * Description: Sets container data
 * Parameters:
 *    containers - vector of container objects
 */
void DataStore::setContainers(const std::vector<std::shared_ptr<Container>>& containers)
{
    m_containers = containers;
}

/*
 * Function: setCranes
 * Description: Sets crane data
 * Parameters:
 *    cranes - vector of crane objects
 */
void DataStore::setCranes(const std::vector<std::shared_ptr<Crane>>& cranes)
{
    m_cranes = cranes;
}

/*
 * Function: setTrucks
 * Description: Sets truck data
 * Parameters:
 *    trucks - vector of truck objects
 */
void DataStore::setTrucks(const std::vector<std::shared_ptr<Truck>>& trucks)
{
    m_trucks = trucks;
}

/*
 * Function: setShips
 * Description: Sets ship data
 * Parameters:
 *    ships - vector of ship objects
 */
void DataStore::setShips(const std::vector<std::shared_ptr<Ship>>& ships)
{
    m_ships = ships;
}

/*
 * Function: setBookings
 * Description: Sets booking data
 * Parameters:
 *    bookings - vector of booking objects
 */
void DataStore::setBookings(const std::vector<std::shared_ptr<Booking>>& bookings)
{
    m_bookings = bookings;
}

/*
 * Function: setBillAndPayments
 * Description: Sets billing and payment data
 * Parameters:
 *    billAndPayments - vector of billingAndPayment objects
 */
void DataStore::setBillAndPayments(const std::vector<std::shared_ptr<BillAndPayment>>& billAndPayments)
{
    m_billAndPayments = billAndPayments;
}

/*
 * Function: setThresholds
 * Description: Sets threshold configurations
 * Parameters:
 *    thresholds - map of container type to threshold
 */
void DataStore::setThresholds(const std::map<Enums::ContainerType, std::shared_ptr<Threshold>>& thresholds)
{
    m_thresholds = thresholds;
}

/*
 * Function: setNotifications
 * Description: Sets notification data
 * Parameters:
 *    notifications - vector of notifications
 */
void DataStore::setNotifications(const std::vector<std::shared_ptr<Notification>>& notifications)
{
    m_notifications = notifications;
}

/*
 * Function: setLogs
 * Description: Sets log data
 * Parameters:
 *    logs - vector of logs
 */
void DataStore::setLogs(const std::vector<std::shared_ptr<Log>>& logs)
{
    m_logs = logs;
}

/*
 * Function: setCurrentUser
 * Description: Sets the currently logged-in user
 * Parameters:
 *    user - shared pointer to user
 */
void DataStore::setCurrentUser(const std::shared_ptr<User> user)
{
    m_currentUser = user;
}

/*
 * Function: getCurrentUser
 * Description: Retrieves the currently logged-in user
 * Returns:
 *    Reference to shared pointer of current user
 */
std::shared_ptr<User>& DataStore::getCurrentUser()
{
    return m_currentUser;
}

/*
 * Function: getInstance
 * Description: Provides singleton instance of DataStore
 * Returns:
 *    Reference to DataStore instance
 */
DataStore& DataStore::getInstance()
{
    static DataStore instance;
    return instance;
}
