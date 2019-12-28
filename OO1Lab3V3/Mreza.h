#pragma once
#include "Lista.h"
#include "GradskaLinija.h"

#include <iostream>

class Mreza
{
public:
	Mreza& operator+=(GradskaLinija& line);

	friend std::ostream& operator<<(std::ostream& os, const Mreza& web);

private:
	Lista<GradskaLinija&> lines;
};

