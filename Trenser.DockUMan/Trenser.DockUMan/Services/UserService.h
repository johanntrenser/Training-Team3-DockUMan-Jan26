#pragma once
#include<iostream>
#include<vector>
#include "Enums.h"
#include "Factory.h"
#include "ShippingAgent.h"
#include "DataStore.h"
class UserService
{
private:
	DataStore& m_dataStore;
public:
	UserService() :m_dataStore(DataStore::getInstance()) {};
	Enums::ProcessStatus registerShippingAgent(std::vector<std::string>&, Enums::UserTypes&, Enums::UserStatus&);
};

