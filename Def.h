#pragma once
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Lis.h"
#include "Guarana.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Jagody.h"
#include "Barszcz.h"
#include "Punkt.h"
#include "Human.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <fstream>

using namespace std;

#define INICJATYWA_OWCA 4
#define INICJATYWA_WILK 5
#define INICJATYWA_ZOLW 1
#define INICJATYWA_ANTYLOPA 4
#define INICJATYWA_LIS 7
#define INICJATYWA_TRAWA 0
#define INICJATYWA_MLECZ 0
#define INICJATYWA_JAGODY 0
#define INICJATYWA_GUARANA 0
#define INICJATYWA_BARSZCZ 0

#define SILA_OWCA 4
#define SILA_WILK 9
#define SILA_LIS 3
#define SILA_ZOLW 2
#define SILA_ANTYLOPA 4
#define SILA_TRAWA 0
#define SILA_MLECZ 0
#define SILA_GUARANA 0
#define SILA_JAGODY 99
#define SILA_BARSZCZ 100

#define SYMBOL_OWCA 'O'
#define SYMBOL_WILK 'W'
#define SYMBOL_LIS 'L'
#define SYMBOL_ZOLW 'Z'
#define SYMBOL_ANTYLOPA 'A'
#define SYMBOL_TRAWA 'T'
#define SYMBOL_MLECZ 'M'
#define SYMBOL_GUARANA 'G'
#define SYMBOL_JAGODY 'J'
#define SYMBOL_BARSZCZ 'B'

#define PRAWD_TRAWA 0.6
#define PRAWD_GUARANA 0.3
#define PRAWD_MLECZ 0.4
#define PRAWD_JAGODY 0.2
#define PRAWD_BARSZCZ 0.15


#define HUMAN_SYMBOL '#'
#define HUMAN_SILA 5
#define HUMAN_INICJATYWA 4


enum Kierunek
{
	NORTH = 0,	//^
	EAST = 1,		//>
	SOUTH = 2,	//v
	WEST		//<
};


