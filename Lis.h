#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {

public:
	void Wypisz() override;
	void Kolizja(Organizm * atakujacy, Organizm* ofiara, Swiat & s) override;
	Lis(Swiat & swiat);
	~Lis();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;

};