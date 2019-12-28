#include "Multimedija.h"

Multimedija::Multimedija(const std::string& name) : name(name)
{
}

std::ostream& Multimedija::output(std::ostream& os) const
{
	return os << name << ':' << Description();
}

std::ostream& operator<<(std::ostream& os, const Multimedija& mm)
{
	return mm.output(os);
}