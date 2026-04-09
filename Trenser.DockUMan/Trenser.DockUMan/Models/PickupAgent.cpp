/*
 * File: PickupAgent.cpp
 * Description: Implements getter and setter functions for the PickupAgent model class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "PickupAgent.h"
#include"Container.h"

std::vector<std::shared_ptr<Container>> PickupAgent::getContainers() const
{
    return m_containers;
}

void PickupAgent::setContainers(const std::vector<std::shared_ptr<Container>>& containers)
{
    m_containers = containers;
}
