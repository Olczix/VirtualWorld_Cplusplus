#include "Mlecz.h"
#include "Swiat.h"
#include "Def.h"
#include <iostream>

void Mlecz::Wypisz()
{
	cout << "MLECZ";
}

void Mlecz::Akcja(Organizm * roslina, Swiat & s)
{
	for (int i = 0;i < 3;i++)
		roslina->Siej(this, s);
}

Mlecz::Mlecz(Swiat & swiat)
	: Roslina(swiat, polozenie, SYMBOL_MLECZ, SILA_MLECZ, INICJATYWA_MLECZ)
{
	wiek = 0;
	sila = SILA_MLECZ;
	inicjatywa = INICJATYWA_MLECZ;
	symbol = SYMBOL_MLECZ;

}

Mlecz::~Mlecz() {}
