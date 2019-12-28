#include "Stajaliste.h"
#include <string>
#include <iostream>

Stajaliste::Stajaliste(int id, const std::string& name, int zone) : id(id), name(name), zone(zone)
{
}

int Stajaliste::GetId() const
{
	return id;
}

std::string Stajaliste::GetName() const
{
	return name;
}

int Stajaliste::GetZone() const
{
	return zone;
}

bool operator==(const Stajaliste& s1, const Stajaliste& s2)
{
	return s1.id == s2.id;
}

std::ostream& operator<<(std::ostream& os, const Stajaliste& s)
{
	return os << '[' << s.zone << "]#" << s.id << '-' << s.name;
}
