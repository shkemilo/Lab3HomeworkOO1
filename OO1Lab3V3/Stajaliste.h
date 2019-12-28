#pragma once
#include <iostream>
#include <string>

class Stajaliste
{
public:
	Stajaliste(int id, const std::string& name, int zone);

	int GetId() const;
	std::string GetName() const;
	int GetZone() const;

	friend bool operator==(const Stajaliste& s1, const Stajaliste& s2);
	friend std::ostream& operator<<(std::ostream& os, const Stajaliste& s);

private:
	std::string name;
	int id;
	int zone;
};

