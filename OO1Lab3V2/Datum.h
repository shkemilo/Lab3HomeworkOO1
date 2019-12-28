#pragma once
#include <iostream>

class Datum
{
public:
	explicit Datum(int day = 28, int month = 12, int year = 2019);

	int operator[](const char* index) const;

	friend bool operator<(const Datum& d1, const Datum& d2);
	friend int operator-(const Datum & d1, const Datum & d2);
	friend std::ostream& operator<<(std::ostream& os, const Datum& date);

private:
	long int days() const;
	int countLeapYears() const;
	bool isLeapYear() const;
	bool isValidDate() const;

	static const short monthDays[];
	int day;
	int month;
	int year;
};

