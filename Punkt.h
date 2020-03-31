#pragma once

class Punkt
{

public:
	int GetX() const;
	int GetY() const;

	void Set(const int &x, const int &y);
	void SetX(const int &x);
	void SetY(const int &y);
	//bool CzyNaMapie(Punkt p,Swiat &s);
	Punkt Losuj(int M, int N);

	Punkt();
	~Punkt();

	bool operator==(const Punkt & other);
	bool operator!=(const Punkt & other);

private:
	int x;
	int y;


};