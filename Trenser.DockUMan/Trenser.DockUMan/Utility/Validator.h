/*
 * File: Validator.h
 * Description: Provides input validation functions for password, email, phone number, and license number
 * Author: Akish Babu
 * Created: 02-Apr-2026
 */
#pragma once
#include<iostream>
#include<string>
#include <regex>
#include "InputHelper.h"

namespace validator
{
    inline void validatePassword(std::string& value)
    {
        bool isPassword = false;
        while (!isPassword)
        {
            bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
            util::read(value);
            for (char ch : value) {
                if (std::isupper(static_cast<unsigned char>(ch)))
                {
                    hasUpper = true;
                }
                else if (std::islower(static_cast<unsigned char>(ch)))
                {
                    hasLower = true;
                }
                else if (std::isdigit(static_cast<unsigned char>(ch)))
                {
                    hasDigit = true;
                }
                else
                {
                    hasSpecial = true;
                }
            }

            if (value.size() < 8 || !hasUpper || !hasLower || !hasDigit || !hasSpecial) {
                std::cout << "Invalid password: must be at least 8 characters, "
                    "contain upper, lower, digit, and special character.\n";
            }
            else {
                std::cout << "Password set !\n";
                isPassword = true;
            }
        }
    }

    inline void validateEmail(std::string& value)
    {
        bool isValidEmail = false;
        std::regex emailPattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
        while (!isValidEmail)
        {
            util::read(value);
            if (std::regex_match(value, emailPattern)) {
                std::cout << "Email address accepted.\n";
                isValidEmail = true;
            }
            else {
                std::cout << "Invalid email address. "
                    "Please enter a valid format such as example@domain.com.\n";
            }
        }
    }
    inline void validatePhoneNumber(std::string& value)
    {
        bool isValidPhoneNumber = false;
        std::regex PhoneNumberPattern(R"(^[0-9]{10}$)");
        while (!isValidPhoneNumber)
        {
            util::read(value);
            if (std::regex_match(value, PhoneNumberPattern)) {
                std::cout << "Phone Number accepted.\n";
                isValidPhoneNumber = true;
            }
            else {
                std::cout << "Invalid phone number. "
                    "Phone number should be of 10 digits.\n";
            }
        }
    }
    inline void validateLicenseNumber(std::string& value)
    {
        bool isValidLicenseNumber = false;
        std::regex LicenseNumberPattern(R"(^(?=.*[0-9])(?=.*[A-Za-z])(?=.*@).{10}$)");
        while (!isValidLicenseNumber)
        {
            util::read(value);
            if (std::regex_match(value, LicenseNumberPattern)) {
                std::cout << "Liscense Number accepted.\n";
                isValidLicenseNumber = true;
            }
            else {
                std::cout << "Invalid Liscense Number. "
                    "Liscense Number should be of 10 digits contains at least one Alphabet,one Number and @ ,Total length of 10 digits.\n";
            }
        }
    }
}
