#include <iostream>

#include "Lista.h"
#include "Datum.h"
#include "Automobil.h"
#include "Vozilo.h"
#include "Evidencija.h"

using namespace std;

int main()
{
	try
	{
		Datum d2(29, 2, 2000);
		Datum d1(29, 2, 2020);
		cout << d1 - d2 << endl;
		
		Automobil v("RARI", Datum(2, 1, 2019), 100, Automobil::KUPE, 100);

		cout << v << endl;
		cout << v.Cost(Datum(1, 1, 2022), true) << endl;

		Vozilo& vozilo = v;
		cout << vozilo << endl;
		cout << v.Cost(Datum(1, 1, 2020), false) << endl;

		Lista<Automobil&> list;
		list.AddElement(v);
		list.Begin();
		cout << list.Current() << endl;

		Agencija a;
		a.AddElement(d1);
		a.AddElement(vozilo);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}