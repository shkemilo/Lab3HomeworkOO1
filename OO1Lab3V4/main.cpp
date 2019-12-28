#include <iostream>
#include "Lista.h"
#include "Exceptions.h"
#include "Mesto.h"
#include "Deonica.h"
#include "Ruta.h"

using namespace std;

int main()
{
	Mesto m1("Kragujevac", 44 + 51. / 60 / 60, 20 + 54. / 60 + 42. / 60 / 60);
	Mesto m2("Batocina", 44 + 9. / 60 + 8. / 60 / 60, 21 + 4. / 60 + 32. / 60 / 60);
	Mesto m3("Beograd", 44 + 48. / 60 + 57. / 60 / 60, 20 + 27. / 60 + 34. / 60 / 60);
	Mesto m4("Novi sad", 45 + 15. / 60 + 18. / 60 / 60, 19 + 50. / 60 + 41. / 60 / 60);
	Deonica d1(m1, m2, Deonica::MAGISTRALNI);
	Deonica d2(m2, m3, Deonica::AUTOPUT);
	Deonica d3(m3, m4, Deonica::AUTOPUT);

	Lista<Deonica&> list;
	list.AddElement(d1).AddElement(d2).AddElement(d3);

	Ruta r(list);
	cout << r << endl;
	cout << r(TESKO) << endl;
	cout << r(5) << endl;

	system("pause");
	return 0;
}