#include "CustomsPenalty.h"
using namespace std;

string CustomsPenalty::getId() const
{ 
	return m_id; 
}

void CustomsPenalty::setId(const string& fineId) 
{
	m_id = fineId;
}

shared_ptr<BillAndPayment> CustomsPenalty::getBill() const
{ 
	return m_bill;
}

void CustomsPenalty::setBill(shared_ptr<BillAndPayment> bill) 
{ 
	m_bill = bill; 
}

vector<shared_ptr<Container>> CustomsPenalty::getFinedContainers() const 
{ 
	return m_finedContainers;
}

void CustomsPenalty::setFinedContainers(const vector<shared_ptr<Container>>& containers)
{ 
	m_finedContainers = containers;
}
