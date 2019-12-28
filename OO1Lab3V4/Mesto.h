#pragma once
#include <string>
#include <iostream>

class Mesto
{
public:
	Mesto(const std::string& name, double longitude, double latitude);

	const std::string& GetName() const;
	double GetLatitude() const;
	double GetLongitude() const;

	friend double operator-(const Mesto& m1, const Mesto& m2);

	friend std::ostream& operator<<(std::ostream& os, const Mesto& m);

private:
	static double convertToRad(double deg);

	static const double PI;
	static const double EARTH_RADIUS;

	std::string name;
	double longitude;
	double latitude;
};