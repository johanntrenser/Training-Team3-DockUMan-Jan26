/*
 * File: ShippingAgenr.cpp
 * Description: Implements getter and setter functions for the ShippingAgent model class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "ShippingAgent.h"

std::string ShippingAgent::getLicenseNumber() const
{
	return m_licenseNumber;
}
void ShippingAgent::setLicenseNumber(const std::string& licenseNumber)
{
	m_licenseNumber = licenseNumber;
}
