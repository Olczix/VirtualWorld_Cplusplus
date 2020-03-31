#include "Trawa.h"
#include "Swiat.h"
#include "Def.h"

void Trawa::Wypisz()
{
	cout << "TRAWA";
}

Trawa::Trawa(Swiat & swiat)
	: Roslina(swiat, polozenie, SYMBOL_TRAWA, SILA_TRAWA, INICJATYWA_TRAWA)
{
	wiek = 0;
	sila = SILA_TRAWA;
	inicjatywa = INICJATYWA_TRAWA;
	symbol = SYMBOL_TRAWA;
	prawd = PRAWD_TRAWA;

}

Trawa::~Trawa() {}
