/*
 * File: InputHelper.h
 * Description: Provides utility functions for safe and validated console input handling
 * Author: Akish Babu
 * Created: 02-Apr-2026
 */
#pragma once
#include<iostream>
#include<string>

namespace util 
{
    template <typename T>
    inline void read(T& value)
    {
        if (!(std::cin >> value))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Invalid console input");
        }
    }

    inline void read(std::string& value)
    {
        std::getline(std::cin >> std::ws, value);
    }
}


