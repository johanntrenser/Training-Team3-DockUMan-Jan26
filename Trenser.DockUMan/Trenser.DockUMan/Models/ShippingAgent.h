/*
 * File: ShippingAgent.h
 * Description: Defines the ShippingAgent class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#pragma once
#include "User.h"
class ShippingAgent :
    public User
{
private:
    std::string m_licenseNumber;
public:
    ShippingAgent() :m_licenseNumber(""),User() {};
    ShippingAgent(std::string licenseNumber,std::string id, std::string name, std::string password, std::string email, std::string phoneNumber, Enums::UserTypes type, Enums::UserStatus status):m_licenseNumber(licenseNumber),
        User(id, name, password, email, phoneNumber,type,status){  };
    std::string getLicenseNumber() const;
    void setLicenseNumber(const std::string&);
};

