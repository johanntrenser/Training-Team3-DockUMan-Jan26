#pragma once
#include "User.h"
class CustomsOfficer :
    public User
{
private:
    std::string m_badgeNumber;
public:
    CustomsOfficer() :m_badgeNumber(""), User() {};
    CustomsOfficer(std::string badgeNumber,std::string id, std::string name, std::string password, std::string email, std::string phoneNumber, Enums::UserTypes type, Enums::UserStatus status) :m_badgeNumber(badgeNumber),
        User(id, name, password, email, phoneNumber,type,status) {};
    std::string getBadgeNumber() const;
    void setBadgeNumber(const std::string&);
};

