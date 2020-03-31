#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {


public:

	bool Unik(Organizm* org) override;
	void Wypisz() override;
	Punkt SzukajMiejsca(Organizm* org) override;
	Antylopa(Swiat & swiat);
	~Antylopa();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	Punkt polozenie;

};