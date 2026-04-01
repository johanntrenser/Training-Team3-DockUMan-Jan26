#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "BillAndPayment.h"
#include "Container.h"

class CustomsPenalty
{
private:
    std::string m_id;
    std::shared_ptr<BillAndPayment> m_bill;
    std::vector<std::shared_ptr<Container>> m_finedContainers;
public:
    CustomsPenalty() : m_id(""), m_bill(nullptr), m_finedContainers() {}
    CustomsPenalty(std::string id, std::shared_ptr<BillAndPayment> bill, std::vector<std::shared_ptr<Container>> finedContainers)
        : m_id(id), m_bill(bill), m_finedContainers(finedContainers) {}
    std::string getId() const;
    void setId(const std::string& fineId);
    std::shared_ptr<BillAndPayment> getBill() const;
    void setBill(std::shared_ptr<BillAndPayment> bill);
    std::vector<std::shared_ptr<Container>> getFinedContainers() const;
    void setFinedContainers(const std::vector<std::shared_ptr<Container>>& containers);
};
