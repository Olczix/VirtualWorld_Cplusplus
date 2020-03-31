
#include "Barszcz.h"
#include "Swiat.h"
#include "Def.h"

void Barszcz::Wypisz()
{
	cout << "BARSZCZ SOSONOWSKIEGO";
}
/*
void Barszcz::Kolizja(Organizm * zwierze, Organizm * roslina, Swiat & s)
{
	zwierze->UsunOrganizm(this, s);
}*/

void Barszcz::Akcja(Organizm * roslina, Swiat & s)
{
	//USUWAM SASIEDZTWO (4 strony swiata - ZWIERZOKI) BARSZCZU SOSNOWSKIEGO 
	vector <Organizm*> sasiedzi; //prawo lewo góra dó³
	Punkt p = roslina->GetPozycja();
	Organizm* org;


	if (p.GetX() - 1 >= 0 && p.GetX() - 1 <= s.GetSzer() - 1)
	{
		Organizm* org = s.mapa[p.GetY()][p.GetX() - 1];
		if (org != nullptr)
			if (org->GetSymbol() == SYMBOL_ANTYLOPA || org->GetSymbol() == SYMBOL_LIS || org->GetSymbol() == SYMBOL_WILK || org->GetSymbol() == SYMBOL_OWCA || org->GetSymbol() == SYMBOL_ZOLW || org->GetSymbol() == HUMAN_SYMBOL)
			{
				s.UsunZKolejki(s.mapa[p.GetY()][p.GetX() - 1]);
				s.mapa[p.GetY()][p.GetX() - 1] = nullptr;
			}
	}

	if (p.GetX() + 1 >= 0 && p.GetX() + 1 <= s.GetSzer() - 1) {
		Organizm* org = s.mapa[p.GetY()][p.GetX() + 1];
		if (org != nullptr)
			if (org->GetSymbol() == SYMBOL_ANTYLOPA || org->GetSymbol() == SYMBOL_LIS || org->GetSymbol() == SYMBOL_WILK || org->GetSymbol() == SYMBOL_OWCA || org->GetSymbol() == SYMBOL_ZOLW || org->GetSymbol() == HUMAN_SYMBOL)
			{
				s.UsunZKolejki(s.mapa[p.GetY()][p.GetX() + 1]);
				s.mapa[p.GetY()][p.GetX() + 1] = nullptr;
			}
	}


	if (p.GetY() - 1 >= 0 && p.GetY() - 1 <= s.GetWys() - 1) {
		Organizm* org = s.mapa[p.GetY() - 1][p.GetX()];
		if (org != nullptr)
			if (org->GetSymbol() == SYMBOL_ANTYLOPA || org->GetSymbol() == SYMBOL_LIS || org->GetSymbol() == SYMBOL_WILK || org->GetSymbol() == SYMBOL_OWCA || org->GetSymbol() == SYMBOL_ZOLW || org->GetSymbol() == HUMAN_SYMBOL)
			{
				s.UsunZKolejki(s.mapa[p.GetY() - 1][p.GetX()]);
				s.mapa[p.GetY() - 1][p.GetX()] = nullptr;
			}

	}

	if (p.GetY() + 1 >= 0 && p.GetY() + 1 <= s.GetWys() - 1) {
		Organizm* org = s.mapa[p.GetY() + 1][p.GetX()];
		if (org != nullptr)
			if (org->GetSymbol() == SYMBOL_ANTYLOPA || org->GetSymbol() == SYMBOL_LIS || org->GetSymbol() == SYMBOL_WILK || org->GetSymbol() == SYMBOL_OWCA || org->GetSymbol() == SYMBOL_ZOLW || org->GetSymbol() == HUMAN_SYMBOL)
			{
				s.UsunZKolejki(s.mapa[p.GetY() + 1][p.GetX()]);
				s.mapa[p.GetY() + 1][p.GetX()] = nullptr;
			}

	}

	roslina->Siej(roslina, s);
}

Barszcz::Barszcz(Swiat & swiat)
	: Roslina(swiat, polozenie, SYMBOL_BARSZCZ, SILA_BARSZCZ, INICJATYWA_BARSZCZ)
{
	wiek = 0;
	sila = SILA_BARSZCZ;
	inicjatywa = INICJATYWA_BARSZCZ;
	symbol = SYMBOL_BARSZCZ;

}

Barszcz::~Barszcz() {}
