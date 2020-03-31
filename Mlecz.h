#pragma once
#include "Roslina.h"

class Mlecz : public Roslina {

public:
	void Wypisz() override;
	void Akcja(Organizm* roslina, Swiat &s) override;
	Mlecz(Swiat & swiat);
	~Mlecz();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;

};