#include "Yard.h"
using namespace std;

string Yard::getId() const 
{
	return m_id;
}

void Yard::setId(const string& yardId) 
{
	m_id = yardId;
}

vector<Yardblock> Yard::getYardBlocks() const 
{
	return m_yardBlocks;
}

void Yard::setYardBlocks(const vector<Yardblock>& yardBlocks) 
{ 
	m_yardBlocks = yardBlocks; 
}

int Yard::getCapacity() const
{
	return m_capacity;
}

void Yard::setCapacity(int capacity) 
{
	m_capacity = capacity; 
}

vector<Crane> Yard::getCranes() const 
{ 
	return m_cranes;
}

void Yard::setCranes(const vector<Crane>& cranes) 
{
	m_cranes = cranes;
}

Enums::YardType Yard::getStatus() const
 {
 return m_type;
 }
 
void Yard::setStatus(Enums::YardType yardType)
{
	m_type = yardType;
}
