#pragma once
#include<iostream>
#include<vector>
#include "Timestamp.h"
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
	Ship* getShipID();
	Enums::ProcessStatus recordShipArrival(Ship* currentShip);
	Enums::ProcessStatus recordShipDeparture(Ship* currentShip);
public:
	ShipService() :m_dataStore(DataStore::getInstance()) {}
	Enums::ProcessStatus registerShip(std::vector<std::string>&, Enums::AvailabilityStatus, Enums::ShipStatus, User*);
	Enums::ProcessStatus registerShipObject(std::vector<std::string>& shipInformation, User*, Enums::AvailabilityStatus isAvailable, Enums::ShipStatus status);
	std::vector<std::string> getShipList();
	Enums::ProcessStatus trackShipStatus(std::string&,std::string&);
	Enums::ProcessStatus sendShipArrivalRequest();
	Enums::ProcessStatus sendShipDepartureRequest();
	Enums::ProcessStatus updateShipAvailabilityStatus(std::string&, Enums::AvailabilityStatus);
	Enums::ProcessStatus updateShipName(std::string&, const std::string&);
	Enums::ProcessStatus updateShipDock(std::string&, const std::string&);
};

