// Digger_Game.cpp: определяет точку входа для консольного приложения.
#pragma once
#include "stdafx.h"
#include "Digger.h"
using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	do
	{
		Digger digger;
		digger.game();
	} while (true);
}

