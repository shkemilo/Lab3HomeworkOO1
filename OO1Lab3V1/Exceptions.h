#pragma once
#include <exception>
#include <iostream>
#include <string>

class Exception : public std::exception
{
public:
	explicit Exception(const char* message) : std::exception(message) { }
	Exception() { }

	friend std::ostream& operator<<(std::ostream& os, const Exception& e)
	{
		return os << e.what();
	}
};

class OutOfRangeException : public Exception
{
public:
	explicit OutOfRangeException(int i, int n = -1) : i(i), n(n) { }

	const char* what() const override
	{
		std::string& temp = *new std::string("Index out of range: index = " + std::to_string(i));
		if (n != -1)
			temp += " size = " + std::to_string(n);

		return temp.c_str();
	}

private:
	int i;
	int n;
};

class InvalidPasswordException : public Exception
{
public:
	explicit InvalidPasswordException(const char* message) : Exception(message) { }
};

class NegativeException : public Exception
{
public:
	explicit NegativeException(const std::string& what) : Exception((what + " can not be negative").c_str()) { }
};

class UserException : public Exception
{
public:
	UserException(const char* message) : Exception(message) { }
};
