#include "Lis.h"
#include "Swiat.h"
#include "Def.h"


Lis::Lis(Swiat & swiat)
	: Zwierze(swiat, polozenie, SYMBOL_LIS, SILA_LIS, INICJATYWA_LIS)
{
	wiek = 0;
	sila = SILA_LIS;
	inicjatywa = INICJATYWA_LIS;
	symbol = SYMBOL_LIS;
}

void Lis::Wypisz()
{
	std::cout << "LIS";
}

void Lis::Kolizja(Organizm * atakujacy, Organizm* ofiara, Swiat & s)
{
	if ( atakujacy->GetSila() > ofiara->GetSila()) // slabszy organizm
	{
		atakujacy->UsunOrganizm(this, s);
		s.mapa[atakujacy->GetCel().GetY()][atakujacy->GetCel().GetX()] = nullptr;
		atakujacy->SetPozycja(atakujacy->GetCel());
		s.DodajOrganizm(atakujacy);
	}
	// w przciwnym razie nie rusza siê
}

Lis::~Lis()
{
}
