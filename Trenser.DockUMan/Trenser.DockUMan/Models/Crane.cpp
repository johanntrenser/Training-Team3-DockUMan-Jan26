#include "Crane.h"
using namespace std;

string Crane::getId() const 
{
	return m_id; 
}

void Crane::setId(const string& craneId) 
{ 
	m_id = craneId; 
}

shared_ptr<Container> Crane::getCurrentContainer() const 
{
	return m_currentContainer;
}

void Crane::setCurrentContainer(shared_ptr<Container> container) 
{ 
	m_currentContainer = container; 
}

Enums::CraneStatus Crane::getStatus() const 
{
	return m_status; 
}

void Crane::setStatus(Enums::CraneStatus status) 
{
	m_status = status; 
}

Enums::AvailabilityStatus Crane::getAvailabilityStatus() const 
{ 
	return m_availabilityStatus;
}

void Crane::setAvailabilityStatus(Enums::AvailabilityStatus status)
{ 
	m_availabilityStatus = status; 
}