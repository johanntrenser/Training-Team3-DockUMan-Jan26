/*
 * File: Notification.h
 * Description: Defines the Notification class
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#pragma once
#include<iostream>
#include "Enums.h"
#include "User.h"

class Notification
{
private:
	std::string m_id;
	std::string m_message;
	std::string m_timeStamp;
	Enums::NotificationStatus m_notificationStatus;
	std::shared_ptr<User> m_receivingUser;
public:
	Notification() :m_id(""), m_message(""), m_timeStamp(""), m_receivingUser(nullptr),m_notificationStatus(Enums::NotificationStatus::UNREAD) {};
	Notification(std::string id,std::string message,std::string timeStamp, std::shared_ptr<User> recievingUser, Enums::NotificationStatus notificationStatus):
		m_id(id),m_message(message),m_timeStamp(timeStamp),m_receivingUser(recievingUser),m_notificationStatus(notificationStatus){};
	std::string getNotificationId() const;
	std::string getMessage() const;
	std::string getTimeStamp() const;
	std::shared_ptr<User> getRecievingUser() const;
	void setId(const std::string&);
	void setMessage(const std::string&);
	void setTimeStamp(const std::string&);
	void setRecievingUser(const std::shared_ptr<User>&);
};

