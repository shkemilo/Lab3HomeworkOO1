#include "Deonica.h"

Deonica::Deonica(const Mesto& start, const Mesto& finish, RoadCategory roadCategory) : start(start), finish(finish), roadCategory(roadCategory)
{
}

const Mesto& Deonica::GetStart() const
{
	return start;
}

const Mesto& Deonica::GetFinish() const
{
	return finish;
}

double Deonica::operator~() const
{
	return finish - start;
}

int Deonica::operator()(VehicleCategory category) const
{
	if (roadCategory != AUTOPUT)
		return 0;

	if (category == LAKO)
		return 12;
	if (category == TESKO)
		return 22;
}

std::string Deonica::categoryToString() const
{
	if (roadCategory == AUTOPUT)
		return "AUTOPUT";
	if (roadCategory == MAGISTRALNI)
		return "MAGISTRALNI";
}

std::ostream& operator<<(std::ostream& os, const Deonica& d)
{
	return os << d.categoryToString() << " [" << d.start << " -> " << d.finish << "] - " << ~d << "km";
}