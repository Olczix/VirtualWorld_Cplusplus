#pragma once
#include "Roslina.h"

class Trawa : public Roslina {

public:
	void Wypisz() override;
	Trawa(Swiat & swiat);
	~Trawa();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;
	int prawd;

};