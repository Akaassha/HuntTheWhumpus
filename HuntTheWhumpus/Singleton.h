#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class Singleton
{
public:
	Singleton()
	{
		if (!instance)
		{
			instance = static_cast<T*>(this);
		}
		else
		{
			throw std::runtime_error("\nError: Trying to create more than one Singleton");
		}
	}

	~Singleton()
	{
		instance = nullptr;	
	}

	static void CreateInstance()
	{
		new T();
	}

	static T& GetInstance()
	{
		return *instance;
	}

private:
	static T* instance;
};

template<typename T>
T* Singleton<T>::instance = nullptr;