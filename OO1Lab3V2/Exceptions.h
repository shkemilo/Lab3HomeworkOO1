#pragma once
#include <exception>
#include <iostream>
#include <string>

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

class DateFormatException : public Exception
{
public:
	DateFormatException() : Exception("Invalid date format") { }

};

class DateException : public Exception
{
public:
	DateException(const char* message) : Exception(message) { }

};

class IndexException : public Exception
{
public:
	IndexException(const char* message) : Exception(message) { }
};
