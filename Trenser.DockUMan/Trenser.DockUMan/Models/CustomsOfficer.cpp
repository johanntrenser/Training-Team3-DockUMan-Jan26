/*
 * File: CustomsOfficer.cpp
 * Description: Contains getters and setters for CustomsOfficer model class representing customs officer-related data
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "CustomsOfficer.h"
std::string CustomsOfficer::getBadgeNumber() const
{
	return m_badgeNumber;
}
void CustomsOfficer::setBadgeNumber(const std::string& badgeNumber)
{
	m_badgeNumber = badgeNumber;
}