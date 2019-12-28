#pragma once
#include <string>
#include <iostream>
#include "Datum.h"

class Vozilo
{
public:
	Vozilo(const std::string& modelName, const Datum& productionDate, double costPerDay);
	Vozilo(const Vozilo&) = delete;
	Vozilo(Vozilo&&) = delete;

	Vozilo& operator=(const Vozilo&) = delete;
	Vozilo& operator=(Vozilo&&) = delete;
	
	virtual int NumberOfPassengers() const = 0;

	virtual double Cost(const Datum& start, bool driver) const;

	virtual ~Vozilo() { }

	friend std::ostream& operator<<(std::ostream& os, const Vozilo& vozilo);

protected:
	virtual std::ostream& output(std::ostream& os) const;

	Datum productionDate;

private:
	std::string modelName;
	double costPerDay;
};

