#include "Roslina.h"
#include "Swiat.h"
#include "Def.h"

Roslina::Roslina(Swiat& swiat, const Punkt& polozenie, const char& symbol, const int& sila, const int& inicjatywa)
	: Organizm(swiat, polozenie, symbol, sila, inicjatywa)
{
}

double Roslina::GetPrawd() const
{
	return prawd;
}

void Roslina::SetPrawd(double prawd)
{
	this->prawd= prawd;
}

void Roslina::Akcja(Organizm * roslina, Swiat & s)
{
	roslina->Siej(this, s);
}

void Roslina::Siej(Organizm * roslina, Swiat &s)
{
	double los = rand() % 100; //liczby <0,99>
	los = los / 100; // liczby <0; 0,99> 

	if (los < roslina->GetPrawd())
	{
		Punkt cel = roslina->SzukajMiejsca(roslina);
		//cout << "BEDZIE SIANE" << endl;
		if (s.mapa[cel.GetY()][cel.GetX()] == nullptr) //wolne miejsce
		{
			roslina->SetPozycja(cel);
			s.DodajOrganizm(roslina);
		}
	}

}

void Roslina::Kolizja(Organizm * zwierze, Organizm * roslina, Swiat & s)
{
	if (zwierze->GetSila() > roslina->GetSila())
	{
		roslina->UsunOrganizm(roslina, s);
		zwierze->Przesun(zwierze, s);
		if (roslina->GetSila() > 0)
		{
			zwierze->Wypisz(); cout << " ZJADA ";roslina->Wypisz();cout << endl;
		}
	
	//	roslina->Wypisz(); cout << " UMIERA " << endl;
		//s.UsunZKolejki(roslina);
	}
	else //roslina silniejsza
	{
		zwierze->UsunOrganizm(zwierze, s);
		s.UsunZKolejki(zwierze);
		roslina->UsunOrganizm(roslina, s);
		roslina->Wypisz(); cout << " ZABIJA ";zwierze->Wypisz();cout << endl;

	}


}

