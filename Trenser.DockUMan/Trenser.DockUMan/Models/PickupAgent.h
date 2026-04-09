/*
 * File: PickupAgent.h
 * Description: Defines the PickupAgent class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#pragma once
#include "User.h"
#include<vector>

class Container;

class PickupAgent :
    public User
{
private:
    std::vector<std::shared_ptr<Container>>m_containers;
public:
    PickupAgent() :User() {};
    PickupAgent(std::string id, std::string name, std::string password, std::string email, std::string phoneNumber, Enums::UserTypes type, Enums::UserStatus status) :
        User(id, name, password, email, phoneNumber,type,status) {};
    std::vector<std::shared_ptr<Container>>getContainers() const;
    void setContainers(const std::vector<std::shared_ptr<Container>>&);
};

