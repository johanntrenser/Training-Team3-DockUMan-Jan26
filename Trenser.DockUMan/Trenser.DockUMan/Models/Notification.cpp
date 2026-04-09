/*
 * File: Notification.cpp
 * Description: Implements getter and setter functions for the Notification model class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "Notification.h"

std::string Notification::getNotificationId() const
{
	return m_id;
}

std::string Notification::getMessage() const
{
	return m_message;
}

std::string Notification::getTimeStamp() const
{
	return m_timeStamp;
}

std::shared_ptr<User> Notification::getRecievingUser() const
{
	return m_receivingUser;
}

void Notification::setId(const std::string& id)
{
	m_id = id;
}

void Notification::setMessage(const std::string& message)
{
	m_message = message;
}

void Notification::setTimeStamp(const std::string& timestamp)
{
	m_timeStamp = timestamp;
}

void Notification::setRecievingUser(const std::shared_ptr<User>& recievingUser)
{
	m_receivingUser = recievingUser;
}

