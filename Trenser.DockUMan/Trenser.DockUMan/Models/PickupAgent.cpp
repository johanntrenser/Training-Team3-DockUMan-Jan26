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