#pragma once
#include "Mesto.h"
#include <iostream>

enum VehicleCategory { LAKO = 0, TESKO };

class Deonica
{
public:
	enum RoadCategory { MAGISTRALNI = 0, AUTOPUT };

	Deonica(const Mesto& start, const Mesto& finish, RoadCategory roadCategory);

	const Mesto& GetStart() const;
	const Mesto& GetFinish() const;

	double operator~() const;
	int operator()(VehicleCategory category) const;

	friend std::ostream& operator<<(std::ostream& os, const Deonica& d);

private:
	std::string categoryToString() const;

	RoadCategory roadCategory;
	const Mesto& start;
	const Mesto& finish;
};