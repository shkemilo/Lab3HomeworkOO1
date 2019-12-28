#include "Ruta.h"

Ruta::Ruta(const Lista<Deonica&> sections) : sections(sections)
{
}

Lista<Deonica&>& Ruta::GetSections()
{
	return sections;
}

const Lista<Deonica&>& Ruta::GetSections() const
{
	return sections;
}

double Ruta::operator()(double consumption) const
{
	double sum = 0;
	for (sections.Begin(); sections.CurrentExsist(); sections.Advance())
		sum += (~sections.Current() / 100) * consumption;
	return sum;
}

int Ruta::operator()(VehicleCategory category) const
{
	int sum = 0;
	for (sections.Begin(); sections.CurrentExsist(); sections.Advance())
		sum += sections.Current()(category);
	return sum;
}

std::ostream& operator<<(std::ostream& os, const Ruta& r)
{
	return os << r.sections;
}