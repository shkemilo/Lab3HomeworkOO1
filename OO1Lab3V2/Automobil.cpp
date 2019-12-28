#include "Automobil.h"

Automobil::Automobil(const std::string& modelName, const Datum& productionDate, double costPerDay, VehicleType vehicleType, int driverCostPerDay) : Vozilo(modelName, productionDate, costPerDay), vehicleType(vehicleType), driverCostPerDay(driverCostPerDay)
{
}

int Automobil::NumberOfPassengers() const
{
	if (vehicleType == KUPE)
		return 2;
	if (vehicleType == LIMUZINA)
		return 5;
}

double Automobil::Cost(const Datum& start, bool driver) const
{
	double percent = 100;
	if (((start - productionDate) / 365) < 2)
		percent += 15;

	return (Vozilo::Cost(start, driver) * (percent / 100) + (driver ? driverCostPerDay : 0));
}

std::ostream& Automobil::output(std::ostream& os) const
{
	return Vozilo::output(os) << '-' << ((vehicleType == KUPE) ? "KUPE" : "LIMUZINA");
}
