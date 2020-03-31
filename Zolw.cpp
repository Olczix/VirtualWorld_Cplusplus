#include "Zolw.h"
#include "Swiat.h"
#include "Def.h"



Zolw::Zolw(Swiat & swiat)
	: Zwierze(swiat, polozenie, SYMBOL_ZOLW, SILA_ZOLW, INICJATYWA_ZOLW)
{
	wiek = 0;
	sila = SILA_ZOLW;
	inicjatywa = INICJATYWA_ZOLW;
	symbol = SYMBOL_ZOLW;
	//polozenie = polozenie.Losuj(swiat.GetM(), swiat.GetN());
}

void Zolw::Wypisz()
{
	std::cout << "ZOLW" ;
}

bool Zolw::OdbijAtak(Organizm* atakujacy)
{
	if (atakujacy->GetSila() < 5) //dam rade odbic atak
	{
		return true;
		cout << "ZOLW ODBI£ ATAK" << endl;
	}
	else { //za silny przeciwnik
		return false;
	}
}


void Zolw::Akcja(Organizm * org, Swiat & s)
{
	int a = rand() % 100;
	if (a > 75) //w 25% przypadkow zmieni swoje po³ozenie
	{
		org->SetCel(SzukajMiejsca(org)); //nowa destynacja zwierzecia, w zaleznoœci od zwierzoka
		org->Decyduj(org, s.mapa[GetCel().GetY()][GetCel().GetX()], s); // decyduje czy tylko sie przenosi, czy jest bójka, czy kopulacja

	}
}


Zolw::~Zolw() {
}
