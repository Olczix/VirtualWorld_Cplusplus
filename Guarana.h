#pragma once
#include "Roslina.h"

class Guarana : public Roslina {

public:
	void Kolizja(Organizm *zwierze, Organizm* roslina, Swiat &s) override;
	void Wypisz() override;
	Guarana(Swiat & swiat);
	~Guarana();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;

};