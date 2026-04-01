#include "CustomsOfficer.h"
std::string CustomsOfficer::getBadgeNumber() const
{
	return m_badgeNumber;
}
void CustomsOfficer::setBadgeNumber(const std::string& badgeNumber)
{
	m_badgeNumber = badgeNumber;
}