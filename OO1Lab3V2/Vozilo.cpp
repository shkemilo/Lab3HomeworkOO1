#include "Vozilo.h"

#include <string>
#include <iostream>
#include "Datum.h"

Vozilo::Vozilo(const std::string& modelName, const Datum& productionDate, double costPerDay) : modelName(modelName), productionDate(productionDate), costPerDay(costPerDay)
{
}

double Vozilo::Cost(const Datum& start, bool driver) const
{
	return costPerDay;
}

std::ostream& Vozilo::output(std::ostream& os) const
{
	return os << modelName << '-' << NumberOfPassengers() << '-' << productionDate;
}

std::ostream& operator<<(std::ostream& os, const Vozilo& vozilo)
{
	return vozilo.output(os);
}
