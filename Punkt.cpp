#include "Punkt.h"
#include "Swiat.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Punkt::Punkt()
	:x(x), y(y)
{}

Punkt::~Punkt()
{
}

int Punkt::GetX() const
{
	return x;
}

int Punkt::GetY() const
{
	return y;
}

void Punkt::Set(const int & x, const int & y)
{
	this->x = x;
	this->y = y;
}

void Punkt::SetX(const int & x)
{
	this->x = x;
}

void Punkt::SetY(const int & y)
{
	this->y = y;
}
/*
bool Punkt::CzyNaMapie(Punkt p, Swiat &s)
{
	if (p.GetX() >= 0 && p.GetX() <= s.GetSzer() - 1 && p.GetY() >= 0 && p.GetY() <= s.GetWys() - 1)
		return true;

	else{ return false;
	}

}*/

Punkt Punkt::Losuj(int M, int N)
{
	Punkt p;
	p.x = rand() % N;
	p.y = rand() % M;;
	return p;
}

bool Punkt::operator==(const Punkt & other)
{
	return x == other.x && y == other.y;
}

bool Punkt::operator!=(const Punkt & other)
{
	return !(*this == other);
}