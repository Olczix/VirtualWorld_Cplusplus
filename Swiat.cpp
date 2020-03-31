#include "Swiat.h"
#include "Organizm.h"
#include "Punkt.h"
#include "Def.h"
#include "Human.h"

using namespace std;
Swiat::Swiat(int wys, int szer)
	:wys(wys), szer(szer)
{
	srand(time(NULL));
	mapa = new Organizm**[wys];
	for (int x = 0; x < wys; x++)
		mapa[x] = new Organizm*[szer];


	for (int i = 0;i < wys;i++)
		for (int j = 0;j < szer;j++)
			mapa[i][j] = nullptr;
}


void Swiat::Menu()
{
	cout << endl << "  DOSTEPNE OPCJE:" << endl;
	cout << "-> N - nowa gra" << endl;
	cout << "-> T - nowa tura" << endl;
	cout << "-> E - Twoj specjany skill " << endl;
	cout << "-> S - zapis do pliku" << endl;
	cout << "-> L - zaladowanie gry z pliku" << endl;
	cout << "-> Q - wyjscie" << endl;
	cout << endl;
	cout << "WCISNIJ KLAWISZ: ";

}

void Swiat::NewGame(Swiat &s)
{
	cout << "NOWA GRA O TYCH SAMYCH WYMIARACH" << endl << endl;
	for (int i = 0;i < wys;i++)
		for (int j = 0;j < szer;j++)
			if (mapa[i][j] != nullptr)
				mapa[i][j] = nullptr;


	this->UstawOrganizmy(s);
	s.tura = 0;
}

void Swiat::Choice(Swiat &s)
{
	char wybor = 'A';

	while (wybor != 'Q')
	{
		Menu();
		cin >> wybor;

		switch (wybor)
		{
		case 'N':
		case 'n':
		{
			this->NewGame(s);
			this->rysujSwiat();
			break;
		}
		case 'T':
		case 't':
		{
			s.wykonajTure(s);
			break;
		}

		case 'E':
		case 'e':
		{
			s.h->Skill(); //WLACZA UMIEJETNOSC, LUB  INFORMUJE O 5/mniej KOLEJKACH CZEKANIA
			break;
		}

		case 'S':
		case 's':
		{
			s.Save();
			break;
		}
		case 'L':
		case 'l':
		{
			s.Load(s);
			break;
		}
		case 'Q':
		case 'q':
			break;

		default:
		{
			cout << "NIE OBSLUGUJE TAKIEGO KLAWISZA - SPROBUJ PONOWNIE!" << endl;
			break;
		}

		}
	}
}

int Swiat::GetSzer() const {
	return szer;
}

void Swiat::SetSzer(int N) {
	this->szer = szer;
}

int Swiat::GetWys() const {
	return wys;
}

void Swiat::SetWys(int wys) {
	this->wys = wys;
}

int Swiat::GetLiczba() const {
	return Liczba;
}

void Swiat::SetLiczba(int Liczba) {
	this->Liczba = Liczba*0.4;
}

void Swiat::UstawOrganizmy(Swiat &s)
{
	Punkt p;
	h = new Human(s);
	p.SetX(s.GetSzer() / 2);
	p.SetY(s.GetWys() / 2);
	h->SetPozycja(p);
	mapa[h->GetPozycja().GetY()][h->GetPozycja().GetX()] = h;
	int ustawionych = 1;
	while (ustawionych < Liczba)
	{
		p = p.Losuj(wys, szer);
		if (mapa[p.GetY()][p.GetX()] == nullptr)
		{
			mapa[p.GetY()][p.GetX()]->SetOrganizm(p, s,false,' ');
			ustawionych++;
		}
	}
}

void Swiat::PosortujKolejke()
{
	std::stable_sort(Kolejka.begin(), Kolejka.end(), porownajInicjatywe);
}

bool Swiat::porownajInicjatywe(Organizm * org, Organizm * org2)
{
	if (org->GetInicjatywa() == org2->GetInicjatywa()) return ((org->GetWiek()) < (org2->GetWiek()));
	return (org->GetInicjatywa() > org2->GetInicjatywa());
}

void Swiat::DodajOrganizm(Organizm *org)
{
	Punkt p = org->GetPozycja();
	mapa[p.GetY()][p.GetX()] = org;
}

void Swiat::UsunZKolejki(Organizm * org)
{
	
	for (int i = 0;i < Kolejka.size();i++)
		if (Kolejka[i]->GetPozycja() == org->GetPozycja())
		{
			if (org->GetSymbol() == HUMAN_SYMBOL) //USUWAM CZLOWIEKA
			{
				this->End();
			}

			Kolejka.erase(Kolejka.begin() + i);
			i = Kolejka.size();
		}
}


Organizm *Swiat::GetOrganizm(Punkt p)
{
	return mapa[p.GetY()][p.GetX()];
}


void Swiat::wykonajTure(Swiat &s)
{
	system("cls");
	s.rysujSwiat();
	for (int i = 0;i < wys;i++)
		for (int j = 0;j < szer;j++)
			if (mapa[i][j] != nullptr)
				Kolejka.push_back(mapa[i][j]);


	this->PosortujKolejke();
	/*cout << " KOLEJNOSC WYKONYWANIA AKCJI NA ORGANIZMACH :" << endl;
	for (int i = 0;i < Kolejka.size();i++)
	{
		Kolejka[i]->Wypisz(); cout << " ";
	}
	cout << endl;*/
	if (Kolejka.size() == 1)//tylko jeden organizm
	{
		if (Kolejka[0]->GetSymbol() == HUMAN_SYMBOL) //to cz³owiek
			this->Win();
	}

	else if (this->HumanAlive() == true)
	{
		for (int i = 0;i < Kolejka.size();i++)
		{
			if (Kolejka[0]->GetSymbol() == HUMAN_SYMBOL && Kolejka[0]->GetSkill() == true) //to cz³owiek
				Kolejka[i]->SkillChange();

			Kolejka[i]->Akcja(Kolejka[i], s);
			Kolejka[i]->SetWiek(Kolejka[i]->GetWiek() + 1);
		}
		tura++;
		s.rysujSwiat();
		Kolejka.clear();
	}
	else { this->End(); }
}

void Swiat::rysujSwiat()
{
	cout << endl;
	cout << "  AKTUALNA TURA: " << tura << endl;
	cout << " -----------------";
	int a = tura;
	while (a > 0) {
		cout << "-";
		a = a / 10;
	}
	cout << "-" << endl << endl;


	for (int i = 0;i < wys;i++)
	{
		for (int j = 0;j < szer;j++)
		{
			if (mapa[i][j] != nullptr) cout << " " << (mapa[i][j])->GetSymbol() << " ";
			else cout << " - ";
		}
		cout << endl;
	}
}

bool Swiat::HumanAlive()
{
	for (int i = 0;i < wys;i++)
		for (int j = 0;j < szer;j++)
			if (mapa[i][j] != nullptr)
				if (mapa[i][j]->GetSymbol() == HUMAN_SYMBOL) //istnieje jeszcze w swiecie cz³owiek
					return true;

	return false;
}

void Swiat::End()
{
	system("cls");
	cout << "GRA SKOÑCZONA! TWOJA POSTAC UMAR£A :-(" << endl;
}

void Swiat::Win()
{
	system("cls");
	cout << "WYGRANA! TYLKO CZLOWIEK POZOSTAL NA SWIECIE! :-)" << endl;
	system("pause");
	exit(0);
}

void Swiat::Save()
{
	cout << "AKTUALNY STAN SWIATA ZAPISANO DO PLIKU 'swiat.txt'" << endl;
	ofstream zapis("swiat.txt");
	zapis << wys << " " << szer << " "<<tura<<endl;
	for (int i = 0;i < wys;i++)
		for (int j = 0;j < szer;j++)
			if (mapa[i][j] != nullptr)
			{
				Organizm* o = mapa[i][j];
				zapis << o->GetPozycja().GetX() << " " << o->GetPozycja().GetY() << " " << o->GetSymbol() << " " << o->GetSila() << " " << o->GetInicjatywa() << " " << o->GetWiek() << endl;
			}
}

void Swiat::Load(Swiat &s)
{
	cout << "LADUJE SWIAT Z PLIKU 'swiat.txt' ..." << endl;
	s.Czysc();
	int wysokosc = 10, szerokosc = 10, ile = 0;
	int x, y, sila, in, wiek, t;
	char symbol;
	ifstream odczyt("swiat.txt");
	while (!odczyt.eof())
	{
		if (ile == 0) 
		{
			odczyt >> wysokosc >> szerokosc>>t;
			tura = t;
			//cout << "WYMIARY ZALADOWANEGO SWIATA: " << wysokosc << " " << szerokosc << endl;
			ile++;
		}

		else 
		{
			odczyt >> x >> y >> symbol >> sila >> in >> wiek;
			Punkt p; p.SetX(x); p.SetY(y);
			Organizm* o;
			o = new Trawa(s);
			o->SetInicjatywa(in);
			o->SetSila(sila);
			o->SetWiek(wiek);
			o->SetSymbol(symbol);
			o->SetOrganizm(p,s,true,symbol);
			//cout << x << " " << y << endl;
		}
	}
	odczyt.close();
	s.rysujSwiat();
	system("pause");
}

void Swiat::Czysc()
{
	for (int i = 0;i < wys;i++)
		for (int j = 0;j < szer;j++)
			if (mapa[i][j] != nullptr)
				mapa[i][j] = nullptr;
}


Swiat::~Swiat() {

	for (int i = 0; i < wys; i++)
		delete[] mapa[i];

	delete[] mapa;

	cout << "DESTRUKTOR ŒWIATA" << endl;
}