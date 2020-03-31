#pragma once
#include "Organizm.h"
#include "Komentator.h"
#include "Punkt.h"
#include <vector>

class Swiat
{

public:
	void Menu();
	void NewGame(Swiat &s);
	void Choice(Swiat &s);
	int GetSzer() const;
	void SetSzer(int szer);
	int GetWys() const;
	void SetWys(int wys);
	int GetLiczba() const;
	void SetLiczba(int Liczba);

	Organizm* h;
	void UstawOrganizmy(Swiat &s);
	Organizm ***mapa;
	std::vector < Organizm*> Kolejka;
	void PosortujKolejke();
	static bool porownajInicjatywe(Organizm* org, Organizm*org2);

	void DodajOrganizm(Organizm *org);
	void UsunZKolejki(Organizm* org);
	Organizm *GetOrganizm(Punkt p);
	void wykonajTure(Swiat &s);
	void rysujSwiat();
	
	bool HumanAlive();
	void End();
	void Win();

	void Save();
	void Load(Swiat &s);
	void Czysc();
	Swiat(int wys, int szer);
	~Swiat();

private:
	int szer,wys, Liczba;
	int tura;

};



