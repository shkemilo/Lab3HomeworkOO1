#include "Mesto.h"
#include "Exceptions.h"

#include <iostream>
#include <string>
#include <cmath>

const double Mesto::PI = 3.14159265359;
const double Mesto::EARTH_RADIUS = 6371;

double Mesto::convertToRad(double deg)
{
	return (deg * PI) / 180;
}

Mesto::Mesto(const std::string& name, double longitude, double latitude) : name(name), longitude(longitude), latitude(latitude)
{
	if (longitude < -180 || longitude > 180 || latitude < -90 || latitude > 90)
		throw GeoException();
}

const std::string& Mesto::GetName() const
{
	return name;
}

double Mesto::GetLatitude() const
{
	return latitude;
}

double Mesto::GetLongitude() const
{
	return longitude;
}

double operator-(const Mesto& m1, const Mesto& m2)
{
	double dLong = Mesto::convertToRad(m1.longitude - m2.longitude);
	double dLat = Mesto::convertToRad(m1.latitude - m2.latitude);

	return 2 * (Mesto::EARTH_RADIUS) *
		asin(sqrt(pow(sin(dLat / 2), 2) +
			cos(Mesto::convertToRad(m1.latitude)) * cos(Mesto::convertToRad(m2.latitude))
			* pow(sin(dLong / 2), 2)));
}

std::ostream& operator<<(std::ostream& os, const Mesto& m)
{
	return os << m.name << '(' << m.longitude << ", " << m.latitude << ')';
}