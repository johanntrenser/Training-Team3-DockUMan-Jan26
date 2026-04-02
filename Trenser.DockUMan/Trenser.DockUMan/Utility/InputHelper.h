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


