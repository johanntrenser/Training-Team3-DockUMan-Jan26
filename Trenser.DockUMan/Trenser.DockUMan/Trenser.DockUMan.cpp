// Trenser.DockUMan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UserInterface.h"

int main()
{
    std::shared_ptr<UserInterface> userInterface = std::make_shared<UserInterface>();
    userInterface->start();
}
