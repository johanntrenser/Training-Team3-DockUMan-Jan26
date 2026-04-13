/*
 * File: YardBlock.cpp
 * Description: Implements getter and setter functions for the YardBlock model class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "Yardblock.h"
using namespace std;

string Yardblock::getId() const 
{
	return m_id;
}

void Yardblock::setId(const string& yardBlockId) 
{ 
	m_id = yardBlockId;
}

Crane Yardblock::getAssignedCrane() const 
{
	return m_assignedCrane;
}

void Yardblock::setAssignedCrane(const Crane& crane) 
{ 
	m_assignedCrane = crane;
}

int Yardblock::getRows() const 
{ 
	return m_rows; 
}

void Yardblock::setRows(int rows) 
{ 
	m_rows = rows;
}

int Yardblock::getColumns() const 
{
	return m_columns; 
}

void Yardblock::setColumns(int columns) 
{ 
	m_columns = columns; 
}

Enums::YardBlockType Yardblock::getStatus() const
{ 
	return m_yardBlockType; 
}

void Yardblock::setStatus(Enums::YardBlockType status)
 {
	m_yardBlockType = status;
}
