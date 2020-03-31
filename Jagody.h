#pragma once
#include "Roslina.h"

class Jagody : public Roslina {

public:
	void Wypisz() override;
	Jagody(Swiat & swiat);
	~Jagody();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;

};