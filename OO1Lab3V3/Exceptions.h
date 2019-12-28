#pragma once
#include <exception>
#include <iostream>

class Exception : public std::exception
{
public:
	Exception(const char* message) : std::exception(message) { }

	friend std::ostream& operator<<(std::ostream& os, const Exception& e)
	{
		return os << e.what();
	}
};

class IteratorException : public Exception
{
public:
	IteratorException() : Exception("Current element does not exsist!") { }

};

