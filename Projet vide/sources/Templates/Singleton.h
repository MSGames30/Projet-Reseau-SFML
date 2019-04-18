#pragma once
#include <iostream>
#include <cstddef>
// Template of a Singleton Design Pattern
// This is used to instantiate only one time an object
// Mainly used to create managers
template<typename T> class Singleton
{
public:
	// Method which returns the instance of this class
	static T* Instance()
	{
		if (_instance == NULL)
			_instance = new T;

		_ASSERT(_instance != NULL);

		return _instance;
	};
protected:
	// Store the static instance of this class
	static T* _instance;

};

// Create the static instance
template<typename T> T* Singleton<T>::_instance = NULL;