#pragma once
#include "Zwierze.h"


class Human : public Zwierze 
{
public:
	void Akcja(Organizm *org, Swiat &s) override;
	void Wypisz() override;
	Punkt Ruch(int ile);
	bool CzyZywy();
	void SetAlive(bool zywy) override;
	bool GetAlive();
	void Skill() override;
	void SkillChange() override;
	void SetPressed(bool pressed) override;
	bool GetSkill() override;
	Human(Swiat & swiat);
	~Human();

private:
	int wiek;
	int sila;
	int inicjatywa;
	char symbol;
	bool zywy;
	bool skill, pressed;
	int skillOnCounter;
	int skillOffCounter;
	Punkt polozenie, cel;
};