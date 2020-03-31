#pragma once
#include "Roslina.h"

class Barszcz : public Roslina {

public:
	void Wypisz() override;
	void Akcja(Organizm* roslina, Swiat &s) override;
	Barszcz(Swiat & swiat);
	~Barszcz();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;

};