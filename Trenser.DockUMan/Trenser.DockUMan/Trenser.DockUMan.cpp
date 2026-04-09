/*
 * File: Trenser.DockUMan.cpp
 * Description: Implements the main function
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */

#include <iostream>
#include "UserInterface.h"

int main()
{
    std::shared_ptr<UserInterface> userInterface = std::make_shared<UserInterface>();
    userInterface->start();
}
