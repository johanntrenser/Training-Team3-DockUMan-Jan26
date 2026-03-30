#pragma once
#include "User.h"
class ShipManager :
    public User
{
public:
    ShipManager() :User() {};
    ShipManager(std::string id, std::string name, std::string password, std::string email, std::string phoneNumber, Enums::UserTypes type, Enums::UserStatus status) :
        User(id, name, password, email, phoneNumber,type,status) {};
};

