#include "Zwierze.h"
#include "Def.h"
#include "Swiat.h"
#include <iostream>
#include <ctime>

Zwierze::Zwierze(Swiat& swiat, const Punkt& polozenie, const char& symbol, const int& sila, const int& inicjatywa)
	: Organizm(swiat, polozenie, symbol, sila, inicjatywa) {}

void Zwierze::Akcja(Organizm * org, Swiat & s)
{
	org->SetCel(SzukajMiejsca(org));
	org->Decyduj(org, s.mapa[org->GetCel().GetY()][org->GetCel().GetX()], s);
}

void Zwierze::Przesun(Organizm * org, Swiat & s)
{
	s.mapa[org->GetPozycja().GetY()][org->GetPozycja().GetX()] = nullptr;
	org->SetPozycja(org->GetCel());
	s.mapa[org->GetPozycja().GetY()][org->GetPozycja().GetX()] = org;
}

void Zwierze::Kolizja(Organizm * atakujacy, Organizm * ofiara, Swiat & s)
{
	if (atakujacy->GetSila() >= ofiara->GetSila()) {
		if (ofiara->OdbijAtak(ofiara) == false) 
		{
			atakujacy->Wypisz();cout << " ZABIJA ";ofiara->Wypisz(); cout << endl;
			if(ofiara->GetInicjatywa()<=atakujacy->GetInicjatywa())
				s.UsunZKolejki(ofiara);
			//ofiara->UsunOrganizm(ofiara, s);
			atakujacy->Przesun(atakujacy, s);
		}
		else {
			ofiara->Wypisz(); cout << " ODBIL ATAK " << endl;
		}
	}

	else
	{
		if (atakujacy->Unik(atakujacy) == true) {
			atakujacy->SetPozycja(SzukajMiejsca(this));
		}

		else { 
			atakujacy->UsunOrganizm(atakujacy, s); //s.UsunZKolejki(atakujacy);
			atakujacy->Wypisz(); cout << " ZAATAKOWA£ "; ofiara->Wypisz();cout << " WIEC UMIERA" << endl;
			
		}
	}
}

void Zwierze::Dzieci(Organizm * org1, Organizm * org2, Swiat & s)
{
	Organizm* dziecko;
	char znak = org1->GetSymbol();
	switch (znak)
	{
	case(SYMBOL_OWCA):
		dziecko = new Owca(s);
		break;

	case(SYMBOL_WILK):
		dziecko = new Wilk(s);
		break;

	case(SYMBOL_ANTYLOPA):
		dziecko = new Antylopa(s);
		break;

	case(SYMBOL_LIS):
		dziecko = new Lis(s);
		break;

	case(SYMBOL_ZOLW):
		dziecko = new Zolw(s);
		break;

	default:
		dziecko = new Trawa(s);
		break;

	}
		bool flaga = false;

		Punkt p = org1->SzukajMiejsca(org1);
		for (int i = 0;i < 10;i++)
		if (s.mapa[p.GetY()][p.GetX()] == nullptr || s.mapa[p.GetY()][p.GetX()]->GetInicjatywa() == 0)
		{
			dziecko->SetPozycja(p);
			s.DodajOrganizm(dziecko);
			i = 10;
			flaga = true;
		}
		else p = org1->SzukajMiejsca(org1);




		if (flaga == false)
		{
			p = org2->SzukajMiejsca(org2);
			for (int i = 0;i < 10;i++)
			{
				if (s.mapa[p.GetY()][p.GetX()] == nullptr || s.mapa[p.GetY()][p.GetX()]->GetInicjatywa() == 0)
				{
					dziecko->SetPozycja(p);
					s.DodajOrganizm(dziecko);
					i = 10;
				}
				else  p = org2->SzukajMiejsca(org2);
			}
		}

		//s.UsunZKolejki(org2);
}



