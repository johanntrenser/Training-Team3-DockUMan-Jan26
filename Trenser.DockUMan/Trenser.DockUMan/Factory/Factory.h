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
	static T* getObject(Args&&... args)
	{
		return new T(std::forward<Args>(args)...);
	}
};

