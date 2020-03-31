//#include "Human.h"
#include "Def.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

Human::Human(Swiat & swiat)
	: Zwierze(swiat, polozenie, HUMAN_SYMBOL, HUMAN_SILA, HUMAN_INICJATYWA)
{
	wiek = 0;
	sila = HUMAN_SILA;
	inicjatywa = HUMAN_INICJATYWA;
	symbol = HUMAN_SYMBOL;
	Punkt p; p.SetX(swiat.GetSzer() / 2); p.SetY(swiat.GetWys() / 2);
	SetPozycja(p);
	skillOffCounter = 0;
	skillOnCounter = 0;
	skill = false;
	pressed = false;
	zywy = true;
}



void Human::Akcja(Organizm * org, Swiat & s)
{
	int a = 1;
	if (skillOnCounter > 0) a = 2;
	this->SkillChange();
	org->SetCel(Ruch(a));
	org->Decyduj(org, s.mapa[org->GetCel().GetY()][org->GetCel().GetX()], s);
}

void Human::Wypisz()
{
	cout << "CZLOWIEK";
}

Punkt  Human::Ruch(int ile)
{
	bool ok = false;
	unsigned char znak;
	while (ok == false)
	{
		znak = _getch();
		switch (znak)
		{
		case 0:
		case 224:
			znak = _getch();
			switch (znak)
			{
			case 72:
				if (this->GetPozycja().GetY() >= ile)
				{
					cel.Set(this->GetPozycja().GetX(), this->GetPozycja().GetY() - ile); //UP
					ok = true;
				}
				break;

			case 80:
				if (this->GetPozycja().GetY() <= s.GetWys() - 1- ile)
				{
					cel.Set(this->GetPozycja().GetX(), this->GetPozycja().GetY() + ile); //DOWN
					ok = true;
				}
				break;

			case 75:
				if (this->GetPozycja().GetX() >= ile)
				{
					cel.Set(this->GetPozycja().GetX() - ile, this->GetPozycja().GetY()); //LEFT
					ok = true;
				}
				break; 

			case 77:
				
				if (this->GetPozycja().GetX() <= s.GetSzer() - 1- ile)
				{
					cel.Set(this->GetPozycja().GetX() + ile, this->GetPozycja().GetY()); //RIGHT
					ok = true;
				}
				break;
			}
			znak = 0;
			break;
		}
	}
	
	this->SetCel(cel);
	//cout << "pozycja: " << this->GetPozycja().GetX() << " " << this->GetPozycja().GetY() << endl;
	//cout << "cel: "<<this->GetCel().GetX() << " " << this->GetCel().GetY() << endl;
	return this->GetCel();
}


bool Human::CzyZywy()
{
	if(this->GetAlive()==true) return true;
	else { return false; }
}

void Human::SetAlive(bool zywy)
{
	this->zywy = true;
}

bool Human::GetAlive()
{
	return this->zywy;
}

void Human::Skill()
{
	if (skillOnCounter > 0) //ekstra umiejetnosc dziala
	{
		cout << "UMIEJETNOSC CZLOWIEKA 'SZYBKOSC ANTYLOPY' JEST AKTYWANA JESZCZE PRZEZ "<<skillOnCounter<<" TUR " << endl;
	}

	else if (skillOffCounter >0) //jeszcze nie dzia³a
	{
		cout << "NIE MO¯NA JESZCZE W£¥CZYÆ UMIEJETNOSCI. POZOSTALO " << skillOffCounter << " TUR OCZEKIWANIA" << endl;
	}

	else if(skillOnCounter==0 && pressed==false)//moge w³aczyæ dod. umiejetnosc
	{
		cout << "UMIEJETNOSC CZLOWIEKA 'SZYBKOSC ANTYLOPY' ZOSTALA AKTYWOWANA" << endl;
		SetPressed(true);
		SkillChange();
	}
	//SkillChange();
	
}

void Human::SkillChange()
{
	if (skillOnCounter > 0) //ekstra umiejetnosc dziala
	{
		skillOnCounter--; //zmniejszam o jedna ture
		if (skillOnCounter == 0) //koniec umiejetnosci
		{
			SetPressed(false);
			skill = false;
			skillOffCounter = 5;
		}
	}

	else if (skillOffCounter >0) //jeszcze nie dzia³a
	{
		skillOffCounter--; //zmniejszam o jedna ture czekanie
	}

	else if(pressed==true)//moge w³aczyæ dod. umiejetnosc - jest dostepna
	{
		pressed = false;
		skillOnCounter = 5;
		skill = true;
	}
}

void Human::SetPressed(bool pressed)
{
	if (skillOnCounter == 0 && skill == false) //w³¹czamy skill
	{
		this->pressed = pressed;
	}
}

bool Human::GetSkill()
{
	if(skill==false)
	return false;

	return true;
}



Human::~Human()
{
}
