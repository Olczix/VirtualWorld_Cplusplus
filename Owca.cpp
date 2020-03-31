#include "Owca.h"
#include "Def.h"
#include "Swiat.h"
#include<iostream>


Owca::Owca(Swiat & swiat)
	: Zwierze(swiat, polozenie, SYMBOL_OWCA, SILA_OWCA, INICJATYWA_OWCA)
{
	wiek = 0;
	sila = SILA_OWCA;
	inicjatywa = INICJATYWA_OWCA;
	symbol = SYMBOL_OWCA;
}

void Owca::Wypisz()
{
	std::cout << "OWCA";
}


Owca::~Owca()
{
}
