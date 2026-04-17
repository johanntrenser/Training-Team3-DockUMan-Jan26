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
        bool isPasswordValid = false;
        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
        for (char ch : value) {
            if (std::isupper(static_cast<unsigned char>(ch))) {
                hasUpper = true;
            }
            else if (std::islower(static_cast<unsigned char>(ch))) {
                hasLower = true;
            }
            else if (std::isdigit(static_cast<unsigned char>(ch))) {
                hasDigit = true;
            }
            else {
                hasSpecial = true;
            }
        }
        if (value.size() >= 8 && hasUpper && hasLower && hasDigit && hasSpecial) {
            std::cout << "Password set!\n";
            return;
        }
        while (!isPasswordValid)
        {
            std::cout << "Invalid password: must be at least 8 characters, contain upper, lower, digit, and special character.\n";
            util::read(value);
            hasUpper = hasLower = hasDigit = hasSpecial = false;
            for (char ch : value) {
                if (std::isupper(static_cast<unsigned char>(ch))) {
                    hasUpper = true;
                }
                else if (std::islower(static_cast<unsigned char>(ch))) {
                    hasLower = true;
                }
                else if (std::isdigit(static_cast<unsigned char>(ch))) {
                    hasDigit = true;
                }
                else {
                    hasSpecial = true;
                }
            }
            if (value.size() >= 8 && hasUpper && hasLower && hasDigit && hasSpecial) {
                std::cout << "Password set!\n";
                isPasswordValid = true;
            }
        }
    }

    inline void validateEmail(std::string& value)
    {
        bool isValidEmail = false;
        std::regex emailPattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
        if (std::regex_match(value, emailPattern)) {
            std::cout << "Email address accepted.\n";
            return;
        }
        while (!isValidEmail) {
            std::cout << "Invalid email address. Please enter a valid format such as example@domain.com.\n";
            util::read(value);
            if (std::regex_match(value, emailPattern)) {
                std::cout << "Email address accepted.\n";
                isValidEmail = true;
            }
        }
    }

    inline void validatePhoneNumber(std::string& value)
    {
        bool isValidPhoneNumber = false;
        std::regex phoneNumberPattern(R"(^[0-9]{10}$)");
        if (std::regex_match(value, phoneNumberPattern)) {
            std::cout << "Phone Number accepted.\n";
            return;
        }
        while (!isValidPhoneNumber)
        {
            std::cout << "Invalid phone number. Phone number should be of 10 digits.\n";
            util::read(value);
            if (std::regex_match(value, phoneNumberPattern)) {
                std::cout << "Phone Number accepted.\n";
                isValidPhoneNumber = true;
            }
        }
    }

    inline void validateLicenseNumber(std::string& value)
    {
        bool isValidLicenseNumber = false;
        std::regex licenseNumberPattern(R"(^(?=.*[0-9])(?=.*[A-Za-z])(?=.*@).{10}$)");
        if (std::regex_match(value, licenseNumberPattern)) {
            std::cout << "License Number accepted.\n";
            return;
        }
        while (!isValidLicenseNumber)
        {
            std::cout << "Invalid License Number. "
                "License Number should be 10 characters long, "
                "contain at least one alphabet, one number, and '@'.\n";
            util::read(value);
            if (std::regex_match(value, licenseNumberPattern)) {
                std::cout << "License Number accepted.\n";
                isValidLicenseNumber = true;
            }
        }
    }
}
