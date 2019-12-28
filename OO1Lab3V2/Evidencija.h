#pragma once
#include "Lista.h"
#include "Vozilo.h"

class Agencija : public Lista<Vozilo&>
{
public:

private:
	Lista<Datum&> d;
};
