#include "Booking.h"
using namespace std;

string Booking::getId() const 
{ 
	return m_id;
}

void Booking::setId(const string& bookingId)
{ 
	m_id = bookingId;
}

shared_ptr<User> Booking::getShippingAgent() const 
{ 
	return m_shippingAgent; 
}

void Booking::setShippingAgent(shared_ptr<User> agent) 
{ 
	m_shippingAgent = agent; 
}

vector<shared_ptr<Container>> Booking::getContainers() const 
{ 
	return m_containers;
}

void Booking::setContainers(const vector<shared_ptr<Container>>& containers) 
{ 
	m_containers = containers;
}

string Booking::getTimestamp() const 
{
	return m_timestamp;
}

void Booking::setTimestamp(const string& timestamp)
{ 
	m_timestamp = timestamp;
}

string Booking::getArrivingShipId() const 
{ 
	return m_arrivingShipId; 
}

void Booking::setArrivingShipId(const string& shipId) 
{ 
	m_arrivingShipId = shipId;
}

string Booking::getDateOfArrival() const 
{ 
	return m_dateOfArrival; 
}

void Booking::setDateOfArrival(const string& date) 
{
	m_dateOfArrival = date;
}

Enums::RequestStatus Booking::getStatus() const
{
	return m_status;
}

void Booking::setStatus(Enums::RequestStatus status)
{ 
	m_status = status;
}
