#pragma once
#include "Lista.h"
#include "Stajaliste.h"

#include <iostream>
#include <string>

class GradskaLinija
{
public:
	GradskaLinija(const std::string& tag, const Lista<Stajaliste&>& stops);
	
	std::string GetTag() const;

	const Lista<Stajaliste&>& GetStops() const;
	Lista<Stajaliste&>& GetStops();
	
	friend int operator&(const GradskaLinija& line1, const GradskaLinija& line2);

	friend std::ostream& operator<<(std::ostream& os, const GradskaLinija& line);

private:
	std::string tag;

	Lista<Stajaliste&> stops;
};

