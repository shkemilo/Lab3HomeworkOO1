#include "Datum.h"
#include "Exceptions.h"

#include <iomanip>

const short Datum::monthDays[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Datum::Datum(int day, int month, int year) : day(day), month(month), year(year)
{
	if (!isValidDate())
		throw DateFormatException();
}

int Datum::operator[](const char* index) const
{
	if (index == "dan")
		return day;
	else if (index == "mesec")
		return month;
	else if (index == "godina")
		return year;

	throw IndexException("Invalid index, valid indexes are: 'dan', 'mesec', 'godina'");
}

long int Datum::days() const
{
	long int days = year * 365 + day;
	for (int i = 0; i < month - 1; i++)
		days += monthDays[i];

	return days += countLeapYears();
}

int Datum::countLeapYears() const
{
	int years = year;

	if (month <= 2)
		years--;

	return years / 4 - years / 100 + years / 400;
}

bool Datum::isLeapYear() const
{
	return (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0));
}

bool Datum::isValidDate() const
{
	if (day <= 0 || month <= 0  || month > 12|| year <= 0)
		return false;

	if (month == 2)
	{
		if (day > monthDays[month - 1] + isLeapYear())
			return false;
	}
	else if (day > monthDays[month - 1])
		return false;

	return true;
}

bool operator<(const Datum& d1, const Datum& d2)
{
	int date1 = d1.day + d1.month * 100 + d1.year * 10000;
	int date2 = d2.day + d2.month * 100 + d2.year * 10000;

	return date1 < date2;
}

int operator-(const Datum& d1, const Datum& d2)
{
	if (d1 < d2)
		throw DateException("First date is before second date");

	return d1.days() - d2.days();
}

std::ostream& operator<<(std::ostream& os, const Datum& date)
{
	char prevFill = os.fill();
	return os << std::setfill('0') 
		<< std::setw(2) << date["dan"] << '.' 
		<< std::setw(2) << date["mesec"] << '.' 
		<< date["godina"] << '.'
		<< std::setfill(prevFill);
}
