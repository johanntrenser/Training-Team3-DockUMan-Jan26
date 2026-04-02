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

