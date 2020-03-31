#pragma once
#include "Organizm.h"

class Roslina: public Organizm {

public:
	Roslina(Swiat & swiat, const Punkt & polozenie, const char &symbol, const int &sila, const int &inicjatywa);
	void Akcja(Organizm *roslina, Swiat &s) override;
	void Kolizja(Organizm *zwierze, Organizm* roslina, Swiat &s) override;
	double GetPrawd() const;
	void SetPrawd(double prawd);
	void Siej(Organizm *roslina, Swiat &s) override;

private:
	double prawd;

};

