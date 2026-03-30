#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
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
    DataStore() = default;
    std::vector<std::shared_ptr<Dock>> m_docks;
    std::vector<std::shared_ptr<Yard>> m_yard;
    std::vector<std::shared_ptr<Container>> m_containers;
    std::vector<std::shared_ptr<Crane>> m_cranes;
    std::vector<std::shared_ptr<Truck>> m_trucks;
    std::vector<std::shared_ptr<Ship>> m_ships;
    std::vector<std::shared_ptr<Booking>> m_bookings;
    std::vector<std::shared_ptr<BillAndPayment>> m_billAndPayments;
    std::map<Enums::ContainerType, std::shared_ptr<Threshold>> m_thresholds;
    std::vector<std::shared_ptr<Notification>> m_notifications;
    std::vector<std::shared_ptr<Log>> m_logs;
public:
    std::vector<std::shared_ptr<Dock>> getDocks() const;
    std::vector<std::shared_ptr<Yard>> getYard() const;
    std::vector<std::shared_ptr<Container>> getContainers() const;
    std::vector<std::shared_ptr<Crane>> getCranes() const;
    std::vector<std::shared_ptr<Truck>> getTrucks() const;
    std::vector<std::shared_ptr<Ship>> getShips() const;
    std::vector<std::shared_ptr<Booking>> getBookings() const;
    std::vector<std::shared_ptr<BillAndPayment>> getBillAndPayments() const;
    std::map<Enums::ContainerType, std::shared_ptr<Threshold>> getThresholds() const;
    std::vector<std::shared_ptr<Notification>> getNotifications() const;
    std::vector<std::shared_ptr<Log>> getLogs() const;
    void setDocks(const std::vector<std::shared_ptr<Dock>>& docks);
    void setYard(const std::vector<std::shared_ptr<Yard>>& yard);
    void setContainers(const std::vector<std::shared_ptr<Container>>& containers);
    void setCranes(const std::vector<std::shared_ptr<Crane>>& cranes);
    void setTrucks(const std::vector<std::shared_ptr<Truck>>& trucks);
    void setShips(const std::vector<std::shared_ptr<Ship>>& ships);
    void setBookings(const std::vector<std::shared_ptr<Booking>>& bookings);
    void setBillAndPayments(const std::vector<std::shared_ptr<BillAndPayment>>& billAndPayments);
    void setThresholds(const std::map<Enums::ContainerType, std::shared_ptr<Threshold>>& thresholds);
    void setNotifications(const std::vector<std::shared_ptr<Notification>>& notifications);
    void setLogs(const std::vector<std::shared_ptr<Log>>& logs);
    DataStore(const DataStore&) = delete;
    DataStore& operator=(const DataStore&) = delete;
    static DataStore& getInstance();
    ~DataStore() = default;
};

