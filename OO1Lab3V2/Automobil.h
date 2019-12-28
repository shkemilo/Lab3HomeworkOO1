#pragma once
#include "Vozilo.h"
#include <string>
#include <iostream>
#include "Datum.h"

class Automobil : public Vozilo
{
public:
	enum VehicleType { KUPE = 0, LIMUZINA };
	
	Automobil(const std::string& modelName, const Datum& productionDate, double costPerDay, VehicleType vehicleType, int driverCostPerDay);
	Automobil(const Automobil&) = delete;
	Automobil(Automobil&&) = delete;

	Automobil& operator=(const Automobil&) = delete;
	Automobil& operator=(Automobil&&) = delete;

	int NumberOfPassengers() const override;

	double Cost(const Datum& start, bool driver) const override;

public:
	std::ostream& output(std::ostream& os) const override;

private:
	VehicleType vehicleType;
	int driverCostPerDay;
};

