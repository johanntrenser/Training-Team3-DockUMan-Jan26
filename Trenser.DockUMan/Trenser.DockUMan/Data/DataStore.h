/*
 * File: DataStore.cpp
 * Description: Manages in-memory storage and retrieval of system entities such as users, docks, containers, and transactions
 * Author: Entire Team
 * Created: 30-Mar-2026
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<utility>
#include <map>
#include "User.h"
#include "Dock.h"
#include "Yard.h"
#include "Container.h"
#include "Crane.h"
#include "Truck.h"
#include "Ship.h"
#include "Booking.h"
#include "BillAndPayment.h"
#include "Notification.h"
#include "Log.h"
#include "Threshold.h"
#include "Enums.h"

class DataStore
{
private:
    DataStore() : m_currentUser(nullptr) {}
    std::vector<User*> m_users;
    std::vector<Dock*> m_docks;
    std::vector<Yard*> m_yard;
    std::vector<Container*> m_containers;
    std::vector<Crane*> m_cranes;
    std::vector<Truck*> m_trucks;
    std::vector<Ship*> m_ships;
    std::vector<Booking*> m_bookings;
    std::vector<BillAndPayment*> m_billAndPayments;
    std::map<Enums::ContainerType, Threshold*> m_thresholds;
    std::vector<Notification*> m_notifications;
    std::vector<Log*> m_logs;
    User* m_currentUser;
    std::queue<Ship*> m_waitingQueue;
public:
    std::vector<User*>& getUsers();
    std::vector<Dock*>& getDocks();
    std::vector<Yard*>& getYard();
    std::vector<Container*>& getContainers();
    std::vector<Crane*>& getCranes();
    std::vector<Truck*>& getTrucks();
    std::vector<Ship*>& getShips();
    std::vector<Booking*>& getBookings();
    std::vector<BillAndPayment*>& getBillAndPayments();
    std::map<Enums::ContainerType, Threshold*>& getThresholds();
    std::vector<Notification*>& getNotifications();
    std::vector<Log*>& getLogs();
    User* getUserById(const std::string&);
    User* getUserByEmail(const std::string&);
    Ship* getShipById(std::string&);
    Ship* getshipByShipManager();
    Dock* getDockById(const std::string&);
    bool addUser(User* agent);
    bool addShip(Ship* ship);
    void setDocks(const std::vector<Dock*>& docks);
    void setYard(const std::vector<Yard*>& yard);
    void setContainers(const std::vector<Container*>& containers);
    void setCranes(const std::vector<Crane*>& cranes);
    void setTrucks(const std::vector<Truck*>& trucks);
    void setShips(const std::vector<Ship*>& ships);
    void setBookings(const std::vector<Booking*>& bookings);
    void setBillAndPayments(const std::vector<BillAndPayment*>& billAndPayments);
    void setThresholds(const std::map<Enums::ContainerType, Threshold*>& thresholds);
    void setNotifications(const std::vector<Notification*>& notifications);
    void setLogs(const std::vector<Log*>& logs);
    void setCurrentUser(User* user);
    void addShipToWaitingQueue(Ship* ship);
    void removeShipFromWaitingQueue();
    User* getCurrentUser();
    DataStore(const DataStore&) = delete;
    DataStore& operator=(const DataStore&) = delete;
    static DataStore& getInstance();
    ~DataStore();
};

