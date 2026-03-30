#include "Threshold.h"

std::string Threshold::getId() const
{
    return m_id;
}

double Threshold::getPricePerWeightInTon() const
{
    return m_pricePerWeightInTon;
}

double Threshold::getPricePerDay() const
{
    return m_pricePerDay;
}

double Threshold::getPenalty() const
{
    return m_penalty;
}

double Threshold::getEquipmentCharge() const
{
    return m_equipmentCharge;
}

void Threshold::setId(const std::string& id)
{
    m_id = id;
}

void Threshold::setPricePerWeightInTon(double pricePerWeightInTon)
{
    m_pricePerWeightInTon = pricePerWeightInTon;
}

void Threshold::setPricePerDay(double pricePerDay)
{
    m_pricePerDay = pricePerDay;
}

void Threshold::setPenalty(double penalty)
{
    m_penalty = penalty;
}

void Threshold::setEquipmentCharge(double equipmentCharge)
{
    m_equipmentCharge = equipmentCharge;
}
