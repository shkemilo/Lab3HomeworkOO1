#include "GradskaLinija.h"
#include "Stajaliste.h"

#include <iostream>
#include <string>

GradskaLinija::GradskaLinija(const std::string& tag, const Lista<Stajaliste&>& stops) : tag(tag), stops(stops)
{
	
}

std::string GradskaLinija::GetTag() const
{
	return tag;
}

const Lista<Stajaliste&>& GradskaLinija::GetStops() const
{
	return stops;
}

Lista<Stajaliste&>& GradskaLinija::GetStops()
{
	return stops;
}

int operator&(const GradskaLinija& line1, const GradskaLinija& line2)
{
	int count = 0;
	for (line1.stops.Begin(); line1.stops.CurrentExsist(); line1.stops.Advance())
		for (line2.stops.Begin(); line2.stops.CurrentExsist(); line2.stops.Advance())
			if (line1.stops.Current() == line2.stops.Current())
			{
				count++;
				break;
			}

	return count;
}

std::ostream& operator<<(std::ostream& os, const GradskaLinija& line)
{
	return os << line.tag << std::endl << line.stops;
}
