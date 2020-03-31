#pragma once
#include "Punkt.h"
//#include "Def.h"
//#include "Headers.h"

class Swiat;

class Organizm
{

public:

	Organizm(Swiat &s, const Punkt & polozenie, const char &symbol, const int &sila, const int &inicjatywa);

	void SetPozycja(const int &x, const int &y);
	void SetPozycja(const Punkt &p);
	Punkt GetPozycja();

	Punkt GetCel() const;
	void SetCel(Punkt cel);
	int GetSila() const;
	void SetSila(int sila);
	int GetInicjatywa() const;
	void SetInicjatywa(const int &inicjatywa);
	char GetSymbol() const;
	void SetSymbol(char symbol);
	int GetWiek();
	void SetWiek(int wiek);
	void SetOrganizm(Punkt p, Swiat &s, bool plik, char znak);
	virtual void SetAlive(bool zywy);
	double GetPrawd() const;
	virtual void SetPressed(bool pressed);

	bool operator < (const Organizm &a) const;
	virtual Punkt SzukajMiejsca(Organizm* org);
	virtual void Wypisz();
	virtual void Przesun(Organizm* org, Swiat &s);
	virtual void Akcja(Organizm *org, Swiat &s);
	virtual void Kolizja(Organizm *atakujacy, Organizm* ofiara, Swiat &s);
	virtual void Siej(Organizm* org, Swiat &s);
	virtual void Dzieci(Organizm* org1, Organizm* org2, Swiat &s);
	void UsunOrganizm(Organizm* org, Swiat &s);
	virtual bool Unik(Organizm* org);
	virtual bool OdbijAtak(Organizm *atakujacy);
	virtual void Decyduj(Organizm* org1, Organizm* org2, Swiat &s);
	virtual void Skill();
	virtual void SkillChange();
	virtual bool GetSkill();

	virtual ~Organizm();


protected:
	int sila;
	int wiek;
	Swiat &s;

private:
	Punkt polozenie, cel;
	int inicjatywa;
	char symbol;

};




