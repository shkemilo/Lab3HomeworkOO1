#include <iostream>
#include "Korisnik.h"
#include "Lista.h"
#include "Multimedija.h"
#include "Slika.h"
#include "Evidencija.h"

using namespace std;

int main()
{
	Lista<Korisnik> list;
	Korisnik k1("Bobek", "bobbbbek1"), k2("Jusuf", "dzedajjjj1"), k3("Kaiba", "plavaccc5"), k4("mirko64", "zezzzzzz32");
	list += k1; list += k2; list += k3; list += k4;

	list += Korisnik("brt", "brtttttttttttttttttt123");

	Evidencija e;
	try
	{
		e += k1; e += k2; e += k3; e += k4;
		cout << e["Bobek"] << endl;
		cout << e["Jusuf"] << endl;
		cout << e["Kaiba"] << endl;
		e.ChangePassword("Bobek", "bobbbbek1", "bobicnobic1312");
		e("Bobek");
		e("mirko64");
		cout << e["Jusuf"].GetPassword() << endl;
		cout << k1.GetPassword() << endl;

		Slika s1 = Slika("Mile", 100, 100, 1);
		Slika s2 = Slika("Cile", 10, 10, 2);
		Slika s3 = Slika("Mirko", 5, 5, 10);

		Lista<Multimedija&> ml;
		ml += s1;
		ml += s2;
		ml += s3;

		for (int i = 0; i < ml.Count(); i++)
			cout << ml[i] << endl;
	}
	catch (Exception & e)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}