#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {

public:
	void Wypisz() override;
	Owca(Swiat & swiat);
	~Owca();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;

};