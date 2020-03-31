#include "Antylopa.h"
#include "Swiat.h"
#include "Def.h"

Antylopa::Antylopa(Swiat & swiat)
	: Zwierze(swiat, polozenie, SYMBOL_ANTYLOPA, SILA_ANTYLOPA, INICJATYWA_ANTYLOPA)
{
	wiek = 0;
	sila = SILA_ANTYLOPA;
	inicjatywa = INICJATYWA_ANTYLOPA;
	symbol = SYMBOL_ANTYLOPA;
}

bool Antylopa::Unik(Organizm * org)
{
	int a = rand() % 100;
	if (a % 2 == 0) //50% szans na ucieczkê
	{
		//uda³o sie zrobic unik
		org->SzukajMiejsca(this);
		s.DodajOrganizm(org);
		return true;

		cout << "ANTYLOPA UCIEK£A" << endl;
	}
	else { //antylopa nie uciek³a:-(
		return false;
	}

}

void Antylopa::Wypisz()
{
	std::cout << "ANTYLOPA";
}

Punkt Antylopa::SzukajMiejsca(Organizm* org)
{
	Punkt dest = org->GetPozycja();

	for (int i = 0;i < 100;i++) // 100 prob 
	{
		switch (rand() % 4)
		{
		case NORTH: //0
			if (dest.GetY() >= 2) {
				dest.SetY(dest.GetY() - 2);
				i = 100;
			}
			break;

		case EAST://1
			if (dest.GetX() <= s.GetSzer() - 3) {
				dest.SetX(dest.GetX() + 2);
				i = 100;
			}
			break;

		case SOUTH://2
			if (dest.GetY() <= s.GetWys() - 3) {
				dest.SetY(dest.GetY() + 2);
				i = 100;
			}
			break;

		case WEST://3
			if (dest.GetX() >= 2) {
				dest.SetX(dest.GetX() - 2);
				i = 100;
			}
			break;

		default: break;
		}
	}

	if (dest != org->GetPozycja()) //znalz³am wolne miejsce
	{
		return dest;
	}
	else //nie znalaz³am wolnego miejsca, zostaje na swoim 
	{
		return org->GetPozycja();
	}
}

Antylopa::~Antylopa()
{
}
