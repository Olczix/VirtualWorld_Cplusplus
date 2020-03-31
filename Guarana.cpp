#include "Guarana.h"
#include "Swiat.h"
#include "Def.h"
#include <iostream>

void Guarana::Kolizja(Organizm * zwierze, Organizm * roslina, Swiat & s)
{
	zwierze->SetSila(zwierze->GetSila() + 3); //guarana daje +3 do sily
	zwierze->Wypisz(); cout << " ZJADA ";roslina->Wypisz();cout << endl;
	cout << "SILA  ";zwierze->Wypisz();cout <<": "<< zwierze->GetSila() << endl;
	roslina->UsunOrganizm(roslina, s);
	zwierze->Przesun(zwierze, s);
	//s.DodajOrganizm(zwierze);
}

void Guarana::Wypisz()
{
	cout << "GUARANA";
}

Guarana::Guarana(Swiat & swiat)
	: Roslina(swiat, polozenie, SYMBOL_GUARANA, SILA_GUARANA, INICJATYWA_GUARANA)
{
	wiek = 0;
	sila = SILA_GUARANA;
	inicjatywa = INICJATYWA_GUARANA;
	symbol = SYMBOL_GUARANA;

}

Guarana::~Guarana() {}
