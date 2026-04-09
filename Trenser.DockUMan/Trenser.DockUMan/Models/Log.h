/*
 * File: Log.h
 * Description: Defines the Log class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#pragma once
#include<iostream>
class Log
{
private:
	std::string m_message;
	std::string m_timestamp;
public:
	Log() :m_message(""),m_timestamp("") {};
	Log(std::string message, std::string timestamp) :m_message(message), m_timestamp(timestamp) {};
	std::string getMessage() const;
	std::string getTimestamp() const;
	void setMessage(const std::string&);
	void setTimestamp(const std::string&);
};

