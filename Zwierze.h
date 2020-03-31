#pragma once
#include "Organizm.h"

class Zwierze : public Organizm
{
public:
	Zwierze(Swiat & swiat, const Punkt & polozenie, const char &symbol, const int &sila, const int &inicjatywa);

	void Przesun(Organizm* org, Swiat &s) override;
	void Akcja(Organizm *org, Swiat &s) override;
	void Kolizja(Organizm *atakujacy, Organizm* ofiara, Swiat &s) override;
	void Dzieci(Organizm* org1, Organizm* org2, Swiat &s) override;

private:
	int wiek;

};

