#include "Organizm.h"
#include <iostream>
#include <time.h>
#include "Swiat.h"
#include "Def.h"
#include <string.h>
using namespace std;

Organizm::Organizm(Swiat & s, const Punkt & polozenie, const char & symbol, const int & sila, const int & inicjatywa)
	:s(s), polozenie(polozenie), symbol(symbol), sila(sila), inicjatywa(inicjatywa)
{
	SetPozycja(rand() % (s.GetSzer()), rand() % (s.GetWys()));
}

void Organizm::SetPozycja(const int & x, const int & y) {
	polozenie.SetX(x);
	polozenie.SetY(y);
}

void Organizm::SetPozycja(const Punkt & polozenie) {
	this->polozenie = polozenie;
}

Punkt Organizm::GetPozycja() {
	return polozenie;
}

int Organizm::GetInicjatywa() const {
	return inicjatywa;
}

Punkt Organizm::GetCel() const {
	return cel;
}

void Organizm::SetCel(Punkt cel)
{
	this->cel = cel;
	//cout << "ustawiono cel na: " << this->cel.GetX() << " " << this->cel.GetY() << endl;
}

int Organizm::GetSila() const {
	return sila;
}

void Organizm::SetSila(int sila)
{
	this->sila = sila;
}

void Organizm::SetInicjatywa(const int & inicjatywa) {
	this->inicjatywa = inicjatywa;
}

char Organizm::GetSymbol() const {
	return symbol;
}

void Organizm::SetSymbol(char sym)
{
	this->symbol = sym;
}

int Organizm::GetWiek()
{
	return 0;
}

void Organizm::SetWiek(int wiek)
{
	this->wiek = wiek;
}

void Organizm::SetOrganizm(Punkt p, Swiat &s, bool plik, char symbol)
{
	char znak;
	Zwierze* z;
	Roslina* r;
	z = nullptr;
	r = nullptr;

	
	if (plik == false) {
		znak = rand() % 26 + 65; //litery od A do Z
	}
	else if (plik == true) {
		znak = symbol;
	}

	switch (znak)
	{
	case(SYMBOL_OWCA):
		z = new Owca(s);
		break;

	case(SYMBOL_WILK):
		z = new Wilk(s);
		break;

	case(SYMBOL_ANTYLOPA):
		z = new Antylopa(s);
		break;

	case(SYMBOL_LIS):
		z = new Lis(s);
		break;

	case(SYMBOL_ZOLW):
		z = new Zolw(s);
		break;

	case(HUMAN_SYMBOL):
		z = new Human(s);
		break;

	case(SYMBOL_GUARANA):
		r = new Guarana(s);
		break;

	case(SYMBOL_BARSZCZ):
		r = new Barszcz(s);
		break;

	case(SYMBOL_TRAWA):
		r = new Trawa(s);
		break;

	case(SYMBOL_MLECZ):
		r = new Mlecz(s);
		break;

	case(SYMBOL_JAGODY):
		r = new Jagody(s);
		break;

	default:
		r = new Trawa(s);
		break;

	}
	

	if (r != nullptr)
	{
		r->SetPozycja(p);
		s.mapa[p.GetY()][p.GetX()] = r;
	}
	else {
		z->SetPozycja(p);
		s.mapa[p.GetY()][p.GetX()] = z;
	}
}

void Organizm::SetAlive(bool zywy)
{

}

double Organizm::GetPrawd() const
{
	return 0.0;
}

void Organizm::SetPressed(bool pressed)
{
}

bool Organizm::operator<(const Organizm & a) const
{
	return inicjatywa > a.GetInicjatywa();
}

Punkt Organizm::SzukajMiejsca(Organizm* org)  // zwraca punkt w sasiedztwie na mapie, gdy jest taka mo¿liwoœæ
{
	Punkt dest = org->GetPozycja();

	for (int i = 0;i < 100;i++) // 100 prob 
	{
		switch (rand() % 4)
		{
		case NORTH: //0
			if (dest.GetY() >= 1) {
				dest.SetY(dest.GetY() - 1);
				i = 100;
			}
			break;

		case EAST://1
			if (dest.GetX() <= s.GetSzer() - 2) {
				dest.SetX(dest.GetX() + 1);
				i = 100;
			}
			break;

		case SOUTH://2
			if (dest.GetY() <= s.GetWys() - 2) {
				dest.SetY(dest.GetY() + 1);
				i = 100;
			}
			break;

		case WEST://3
			if (dest.GetX() >= 1) {
				dest.SetX(dest.GetX() - 1);
				i = 100;
			}
			break;

		default: break;
		}
	}

	if (dest != org->GetPozycja()) //znalz³am wolne miejsce
	{
		return dest;
	}
	else //nie znalaz³am wolnego miejsca, zostaje na swoim 
	{
		return org->GetPozycja();
	}

}

void Organizm::Wypisz()
{
}

void Organizm::Przesun(Organizm * org, Swiat & s)
{
}

void Organizm::Akcja(Organizm * org, Swiat &s)
{
}

void Organizm::Kolizja(Organizm * atakujacy, Organizm* ofiara, Swiat &s)
{
}

void Organizm::Siej(Organizm * org, Swiat & s)
{
}

void Organizm::Dzieci(Organizm * org1, Organizm * org2, Swiat & s)
{
}

void Organizm::Decyduj(Organizm * org1, Organizm * org2, Swiat &s)
{
	bool ruch = false;
	if (org2 == nullptr && ruch == false)
	{
		//org1->Wypisz(); cout << " PRZENOSI SIE NA WOLNE POLE " << endl;
		Przesun(org1, s);
		ruch = true;
	}

	else if (org2 != nullptr && org2->GetInicjatywa() == 0 && org1->GetInicjatywa() != 0 && ruch == false)
	{
		org1->Wypisz();
		cout << " WCHODZI NA ROSLINE" << endl;
		org2->Kolizja(org1, org2, s);
		ruch = true;
	}

	else if (org2 != nullptr)
	{
		if (org2->GetInicjatywa() > 0 && ruch == false)
		{
			if (org1->GetSymbol() == org2->GetSymbol())
			{
				cout << "DZIECKO ORGANIZMOW "; org1->Wypisz();cout << " ";org2->Wypisz(); cout << endl;
				org1->Dzieci(org1, org2, s);
			}

			else org1->Kolizja(org1, org2, s);
		}
		ruch = true;
	}
}

void Organizm::Skill()
{
}

void Organizm::SkillChange()
{
}

bool Organizm::GetSkill()
{
	return false;
}


void Organizm::UsunOrganizm(Organizm * org, Swiat & s)
{
	s.mapa[org->GetPozycja().GetY()][org->GetPozycja().GetX()] = nullptr;
	if (org->GetSymbol() == HUMAN_SYMBOL)
	{
		s.End();
	}
}

bool Organizm::Unik(Organizm * org)
{
	return false;
}

bool Organizm::OdbijAtak(Organizm* atakujacy)
{
	return false;
}



Organizm::~Organizm() {}