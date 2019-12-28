#pragma once
#include "Lista.h"
#include "Deonica.h"

#include <iostream>

class Ruta
{
public:
	Ruta(const Lista<Deonica&> sections);

	Lista<Deonica&>& GetSections();
	const Lista<Deonica&>& GetSections() const;

	double operator()(double consumption) const;
	int operator()(VehicleCategory category) const;

	friend std::ostream& operator<<(std::ostream& os, const Ruta& r);

private:
	Lista<Deonica&> sections;
};

