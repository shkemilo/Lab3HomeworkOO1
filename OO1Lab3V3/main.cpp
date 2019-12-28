#include <iostream>
#include "Lista.h"
#include "Stajaliste.h"
#include "GradskaLinija.h"
#include "Mreza.h"
#include "Exceptions.h"

using namespace std;

int main()
{
	Stajaliste s1(65, "Pravni fakultet", 1);
	Stajaliste s2(99, "Pijaca zvezdara", 1);
	Stajaliste s3(69, "Mirijevo 69", 3);

	Stajaliste z1(0, "Zvezdara/terminus", 1);
	Stajaliste z2(1, "Milosa Jankovica", 1);
	Stajaliste z3(2, "Gradska Bolnica", 1);
	Stajaliste z4(3, "Cegarska", 1);

	Lista<Stajaliste&> list;
	list.AddElement(s1).AddElement(s2).AddElement(s3).AddElement(z1);
	try
	{
		list.Current();
	}
	catch (Exception & e)
	{
		cout << e;
	}
	Lista<Stajaliste&> list1;
	list1.AddElement(z1).AddElement(z2).AddElement(z3).AddElement(z4);

	GradskaLinija g1("69", list);
	GradskaLinija g2("40", list1);

	cout << g1 << g2 << endl;
	cout << (g1 & g2) << endl;

	GradskaLinija g3("0", Lista<Stajaliste&>());

	Mreza mreza;
	mreza += g1; mreza += g2; mreza += g3;

	cout << mreza << endl;

	Mreza nova;
	nova = mreza;
	nova += g1;
	cout << nova << endl;
	cout << mreza << endl;

	system("pause");
	return 0;
}