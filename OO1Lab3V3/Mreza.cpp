#include "Mreza.h"

Mreza& Mreza::operator+=(GradskaLinija& line)
{
	lines.AddElement(line);

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Mreza& web)
{
	for (web.lines.Begin(); web.lines.CurrentExsist(); web.lines.Advance())
	{
		os << web.lines.Current().GetTag() << ':';

		if (web.lines.Current().GetStops().Count() == 0)
		{
			os << std::endl;
			continue;
		}

		web.lines.Current().GetStops().Begin();
		Stajaliste temp = web.lines.Current().GetStops().Current();
		os << temp << '-';

		for (web.lines.Current().GetStops().Begin(); 
			web.lines.Current().GetStops().CurrentExsist();  
			temp = web.lines.Current().GetStops().Current(), 
			web.lines.Current().GetStops().Advance());
		os << temp << std::endl;
	}

	return os;
}
