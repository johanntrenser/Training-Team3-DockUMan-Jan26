#include "ShippingAgent.h"
std::string ShippingAgent::getLicenseNumber() const
{
	return m_licenseNumber;
}
void ShippingAgent::setLicenseNumber(const std::string& licenseNumber)
{
	m_licenseNumber = licenseNumber;
}