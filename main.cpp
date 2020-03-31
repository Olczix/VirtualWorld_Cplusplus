#include <iostream>
#include <windows.h>
#include "Organizm.h"
#include "Swiat.h"
#include "Punkt.h"
#include "Def.h"

using namespace std;

BOOL WINAPI SetConsoleTitle(LPCTSTR lpConsoleTitle) {
SetConsoleTitleA("ALEKSANDRA BARSKA 175862 INF grupa 6");
return 0;
}

int main()
{
	int szerokosc, wysokosc;
	cout << "   WITAJ W WIRTUALNYM SWIECIE!" << endl;
	cout << "---------------------------------" << endl;
	cout << " PODAJ WYMIARY PLANSZY NA KTOREJ BEDZIE TOCZYLA SIE ROZGRYWKA : " << endl;
	cout << "	-> SZEROKOSC: "; cin >> szerokosc;
	cout << "	-> WYSOKOSC:  "; cin >> wysokosc;

	Swiat s(wysokosc, szerokosc);
	s.GetWys();
	s.GetSzer();
	s.SetWys(wysokosc);
	s.SetSzer(szerokosc);
	s.SetLiczba(wysokosc*szerokosc);
	s.UstawOrganizmy(s);
	char wybor = 'A';

	s.Choice(s);

	system("pause");
	return 0;
}

