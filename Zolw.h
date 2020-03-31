#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {

public:
	void Wypisz() override;
	bool OdbijAtak(Organizm* atakujacy) override;
	void Akcja(Organizm* org, Swiat &s) override;
	Zolw(Swiat & swiat);
	~Zolw();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;
};
