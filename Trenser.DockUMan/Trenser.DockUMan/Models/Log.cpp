#include "Log.h"

std::string Log::getMessage() const
{
	return m_message;
}

std::string Log::getTimestamp() const
{
	return m_timestamp;
}

void Log::setMessage(const std::string& message)
{
	m_message = message;
}

void Log::setTimestamp(const std::string& timestamp)
{
	m_timestamp = timestamp;
}

