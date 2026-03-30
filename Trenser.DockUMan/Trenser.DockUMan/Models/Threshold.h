#pragma once
#include <iostream>
#include <string>
class Threshold
{
private:
    std::string m_id;
    double m_pricePerWeightInTon;
    double m_pricePerDay;
    double m_penalty;
    double m_equipmentCharge;
public:
    Threshold() 
        : m_id{ "" }, m_pricePerWeightInTon{ 0.0 }, m_pricePerDay{ 0.0 }, 
        m_penalty{ 0.0 }, m_equipmentCharge{ 0.0 } {}
    Threshold(std::string id, double pricePerWeightInTon, double pricePerDay, 
        double penalty, double equipmentCharge) 
        : m_id{ id }, m_pricePerWeightInTon{ pricePerWeightInTon },
        m_pricePerDay{ pricePerDay }, m_penalty{ penalty }, m_equipmentCharge{ equipmentCharge } { }
    std::string getId() const;
    double getPricePerWeightInTon() const;
    double getPricePerDay() const;
    double getPenalty() const;
    double getEquipmentCharge() const;
    void setId(const std::string& id);
    void setPricePerWeightInTon(double pricePerWeightInTon);
    void setPricePerDay(double pricePerDay);
    void setPenalty(double penalty);
    void setEquipmentCharge(double equipmentCharge);
};
