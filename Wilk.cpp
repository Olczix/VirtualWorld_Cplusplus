#include "Wilk.h"
#include "Swiat.h"
#include "Def.h"
#include <iostream>

void Wilk::Wypisz()
{
	std::cout << "WILK";
}

Wilk::Wilk(Swiat & swiat)
	: Zwierze(swiat, polozenie, SYMBOL_WILK, SILA_WILK, INICJATYWA_WILK)
{
	wiek = 0;
	sila = SILA_WILK;
	inicjatywa = INICJATYWA_WILK;
	symbol=SYMBOL_WILK;
}

Wilk::~Wilk(){}
