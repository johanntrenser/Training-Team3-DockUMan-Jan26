#pragma once
#include<iostream>
#include<vector>
#include "Enums.h"
#include "Factory.h"
#include "ShippingAgent.h"
#include "ShipManager.h"
#include "CustomsOfficer.h"
#include "DataStore.h"
class ShipService
{
private:
	DataStore& m_dataStore;
public:
	ShipService() :m_dataStore(DataStore::getInstance()) {}
	Enums::ProcessStatus registerShip(std::vector<std::string>&, Enums::AvailabilityStatus, Enums::ShipStatus, std::shared_ptr<User>);
	Enums::ProcessStatus registerShipObject(std::vector<std::string>& shipInformation, std::shared_ptr<User>, Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status);
	std::vector<std::string> getShipList();
	Enums::ProcessStatus trackShipStatus(std::string&,std::string&);
};

