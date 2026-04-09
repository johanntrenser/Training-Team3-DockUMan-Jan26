/*
 * File: Yard.h
 * Description: Defines the Yard class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Yardblock.h"
#include "Crane.h"

class Yard
{
private:
    std::string m_id;
    std::vector<Yardblock> m_yardBlocks;
    int m_capacity;
    Enums::YardType m_type;
    std::vector<Crane> m_cranes;
public:
    Yard() : m_id(""), m_yardBlocks(), m_capacity(0), m_cranes(), m_type(Enums::YardType::IMPORT){}
    Yard(std::string id, std::vector<Yardblock> yardBlocks, int capacity, std::vector<Crane> cranes, Enums::YardType yardType)
        : m_id(id), m_yardBlocks(yardBlocks), m_capacity(capacity), m_cranes(cranes), m_type(yardType) {}
    std::string getId() const;
    void setId(const std::string& yardId);
    std::vector<Yardblock> getYardBlocks() const;
    void setYardBlocks(const std::vector<Yardblock>& yardBlocks);
    int getCapacity() const;
    void setCapacity(int capacity);
    std::vector<Crane> getCranes() const;
    void setCranes(const std::vector<Crane>& cranes);
    Enums::YardType getStatus() const;
    void setStatus(Enums::YardType type);
};
