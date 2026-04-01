#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "User.h"
#include "Container.h"

class Booking
{
private:
    std::string m_id;
    std::shared_ptr<User> m_shippingAgent;
    std::vector<std::shared_ptr<Container>> m_containers;
    Enums::RequestStatus m_status;
    std::string m_timestamp;
    std::string m_arrivingShipId;
    std::string m_dateOfArrival;
public:
    Booking() : m_id(""), m_shippingAgent(nullptr), m_containers(), m_timestamp(""), m_arrivingShipId(""), m_dateOfArrival(""), m_status(Enums::RequestStatus::PENDING) {}
    Booking(std::string id, std::shared_ptr<User> shippingAgent, std::vector<std::shared_ptr<Container>> containers, std::string timestamp, std::string arrivingShipId, std::string dateOfArrival, Enums::RequestStatus status)
        : m_id(id), m_shippingAgent(shippingAgent), m_containers(containers), m_timestamp(timestamp), m_arrivingShipId(arrivingShipId), m_dateOfArrival(dateOfArrival), m_status(status) {}
    std::string getId() const;
    void setId(const std::string& bookingId);
    std::shared_ptr<User> getShippingAgent() const;
    void setShippingAgent(std::shared_ptr<User> agent);
    std::vector<std::shared_ptr<Container>> getContainers() const;
    void setContainers(const std::vector<std::shared_ptr<Container>>& containers);
    std::string getTimestamp() const;
    void setTimestamp(const std::string& timestamp);
    std::string getArrivingShipId() const;
    void setArrivingShipId(const std::string& shipId);
    std::string getDateOfArrival() const;
    void setDateOfArrival(const std::string& date);
    Enums::RequestStatus getStatus() const;
    void setStatus(Enums::RequestStatus status);
};
