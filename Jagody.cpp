#include "Jagody.h"
#include "Swiat.h"
#include "Def.h"
#include <iostream>

void Jagody::Wypisz()
{
	cout << "WILCZE JAGODY";
}

Jagody::Jagody(Swiat & swiat)
	: Roslina(swiat, polozenie, SYMBOL_JAGODY, SILA_JAGODY, INICJATYWA_JAGODY)
{
	wiek = 0;
	sila = SILA_JAGODY;
	inicjatywa = INICJATYWA_JAGODY;
	symbol = SYMBOL_JAGODY;

}

Jagody::~Jagody() {}
