/*
 * File: Factory.h
 * Description: Provides a generic factory method for creating pointer objects using perfect forwarding
 * Author: Akish Babu
 * Created: 02-Apr-2026
 */
#pragma once
#include<memory>
#include<utility>

class Factory
{
public:
	template<typename T,typename...Args>
	static std::shared_ptr<T>getObject(Args&&... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
};

