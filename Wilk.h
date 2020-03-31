#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {

public:
	void Wypisz() override;
	Wilk(Swiat & swiat);
	~Wilk();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;

};