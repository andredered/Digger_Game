#include "stdafx.h"
#include "Digger.h"


using namespace std;

void Digger::something(Field temp)
{
	if (temp.tempMove)
	{
		string str = "";
		int a = 0;
		ClearHeroConsole();
		for (size_t i = 0; i < 10; i++)
		{
			SetCursor(HeroInterfaceposx + 40, HeroInterfaceposy + i);
			cout << "                                              ";
		}
		switch (rand() % 50)
		{
		case 0:
		case 1:
			//trap

			a = 10 + rand() % 21;
			hero.currentHP -= a;
			if (hero.currentHP <= 0)
			{
				hero.currentHP = 0;
			}
			hero.ReShowHP(HeroInterfaceposx, HeroInterfaceposy);
			str = "  > I loose " + to_string(a) + " HP";
			HeroConsole(pfrases.Trap(), constHeroConsole);
			HeroConsole(str, constHeroConsole + 1);
			break;


		case 2:
		case 3:
		case 4:
		case 5:
			//fight
			Fight(new Monster(level));
			break;
		case 6:
			//finding
			Finding();
			break;
		default:

			hero.currentHP += 5;
			if (hero.currentHP >= hero.GetHP())
			{
				hero.currentHP = hero.GetHP();
			}
			hero.ReShowHP(HeroInterfaceposx, HeroInterfaceposy);
		}

		Sleep(500);

	}
}

Digger::Digger()
{
	mas mas1, mas2;
	int m1[30][60] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

	};
	for (size_t i = 0; i < 30; i++)
	{
		for (size_t j = 0; j < 60; j++)
		{
			mas1.arr[i][j] = m1[i][j];
		}
	}
	fields.push_back(mas1);

	int m2[30][60] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	for (size_t i = 0; i < 30; i++)
	{
		for (size_t j = 0; j < 60; j++)
		{
			mas2.arr[i][j] = m2[i][j];
		}
	}
	fields.push_back(mas2);
}


//===================
//=====================================================================================
bool Digger::Attack(Monster * monster)
{
	int monsterDefence = monster->getDefence();
	int heroDamage = hero.GetAttack();
	
	monsterDefence *= 3;
	monsterDefence /= 10;
	monsterDefence = 100 - monsterDefence;
	heroDamage = (((heroDamage - 5)*monsterDefence) / 100) + rand() % 11;
	monster->currentHP -= heroDamage;
	HeroConsole(pfrases.Attack(), constHeroConsole);
	string str = "  > I did " + to_string(heroDamage) + " damage";
	HeroConsole(str, constHeroConsole+1);
	if (monster->currentHP <= 0)
	{
		monster->currentHP = 0;
		return true;
	}
	return false;
}
void Digger::Heal()
{
	int q = 1 + rand() % 40;
	hero.currentHP += q;
	if (hero.currentHP >= hero.GetHP())
	{
		hero.currentHP = hero.GetHP();
	}
	HeroConsole(pfrases.Heal(), constHeroConsole);
	string str = "  > I treated myself on " + to_string(q) + " HP";
	HeroConsole(str, constHeroConsole+1);
}
bool Digger::TryToRun()
{
	if (rand()%10 <=4)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Digger::Defence(Monster * monster)
{
	int HeroDefence = hero.GetDefence();
	int HeroDodge = hero.GetDodge();
	int MonsterDamage = monster->getDamage();

	HeroDefence *= 3;
	HeroDefence /= 10;
	HeroDefence = 100 - HeroDefence;
	MonsterDamage = (((MonsterDamage - 5)*HeroDefence) / 100) + rand() % 11;
	if (HeroDodge > 0 && rand() % 600 <= HeroDodge)
	{
		HeroConsole(pfrases.Dodge(), constHeroConsole + 3);
		string str = "  > I dodged the attack.";
		HeroConsole(str, constHeroConsole + 4);
	}
	else
	{
		hero.currentHP -= MonsterDamage;
		HeroConsole(pfrases.Defence(), constHeroConsole + 3);
		string str = "  > I got " + to_string(MonsterDamage) + " damage";
		HeroConsole(str, constHeroConsole + 4);
	}
	

	if (hero.currentHP <= 0)
	{
		hero.currentHP = 0;
		return true;
	}
	return false;
}
void Digger::game()
{
		menu();
		level = 0;
		do
		{
			if (level != 5)
			{
				level++;
			}
			Field temp(fields.at(rand() % fields.size()).arr);
			system("cls");
			cout << "  > Generation world...";
			Sleep(5000);
			system("cls");
			temp.Show();

			hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.LightGreen);
			int input;
			bool q = true;
			do
			{
				input = _getch();
				switch (input)
				{
				case W://вверх
					q = temp.Move(W);
					something(temp);
					break;
				case S://вниз
					q = temp.Move(S);
					something(temp);
					break;
				case A://влево
					q = temp.Move(A);
					something(temp);
					break;
				case D://вправо
					q = temp.Move(D);
					something(temp);
					break;
				default:
					break;
				}
			} while (q && hero.currentHP > 0);
		} while (hero.currentHP > 0);

		Sleep(2000);
		HeroConsole(pfrases.Deading(), constHeroConsole + 6);

		Sleep(5000);
		string str = "  > " + hero.GetName() + " died.";
		HeroConsole(str, constHeroConsole + 7);
		Sleep(5000);
		system("cls");
}
int Digger::MenuChoise()
{
	int input, punkt = 0;
	int kx = 3, ky = 10;
	int visota = 4, dlina = 114;


	Strela(kx, ky, visota, dlina, White);

	do
	{
		input = _getch();
		switch (input)
		{
		case 72://вверх
			if (punkt == 0)
			{
				break;
			}
			else
			{
				Strela(kx, ky, visota, dlina, Black);
				ky -= 13;
				punkt--;
			}
			switch (punkt)
			{
			case 0:
				dlina = 116;
				break;

			case 1:
				dlina = 50;
				break;
			}
			Strela(kx, ky, visota, dlina, White);
			break;

		case 80://вниз
			if (punkt == 1)
			{
				break;
			}
			else
			{
				Strela(kx, ky, visota, dlina, Black);
				ky += 13;
				punkt++;
			}

			switch (punkt)
			{
			case 0:
				dlina = 116;
				break;

			case 1:
				dlina = 50;
				break;
			}
			Strela(kx, ky, visota, dlina, White);
			break;
		}
	} while (input != 13);//клавиша Enter

	return punkt;
}
void Digger::menu()
{
	system("cls");

	cout << "\n\n";

	SetColor(LightGreen, Black);
	cout << "\t +++     ++  ++++++++++  ++      ++ \t\t ++++++++++          ++++       +++      +++  ++++++++++ \n";
	cout << "\t ++++    ++  ++++++++++  ++      ++ \t\t ++++++++++         ++++++      ++++    ++++  ++++++++++ \n";
	cout << "\t ++ ++   ++  ++          ++      ++ \t\t ++      ++        ++    ++     ++ ++  ++ ++  ++         \n";
	cout << "\t ++ ++   ++  ++          ++      ++ \t\t ++               ++      ++    ++  ++++  ++  ++         \n";
	cout << "\t ++  ++  ++  ++++++++++  ++      ++ \t\t ++              ++        ++   ++   ++   ++  ++++++++++ \n";
	cout << "\t ++  ++  ++  ++++++++++  ++  ++  ++ \t\t ++              ++        ++   ++   ++   ++  ++++++++++ \n";
	cout << "\t ++   ++ ++  ++          ++  ++  ++ \t\t ++   ++++++++  ++++++++++++++  ++        ++  ++         \n";
	cout << "\t ++   ++ ++  ++          ++ ++++ ++ \t\t ++      ++     ++          ++  ++        ++  ++         \n";
	cout << "\t ++    ++++  ++++++++++  ++++  ++++ \t\t ++++++++++     ++          ++  ++        ++  ++++++++++ \n";
	cout << "\t ++     +++  ++++++++++  +++    +++ \t\t ++++++++++     ++          ++  ++        ++  ++++++++++ \n";

	cout << "\n\n\n";

	cout << "\t ++++++++++  ++      ++  +++  ++++++++++ \n";
	cout << "\t ++++++++++  ++      ++  +++  ++++++++++ \n";
	cout << "\t ++           ++    ++   +++      ++     \n";
	cout << "\t ++            ++  ++             ++     \n";
	cout << "\t ++++++++++     ++++     +++      ++     \n";
	cout << "\t ++++++++++     ++++     +++      ++     \n";
	cout << "\t ++            ++  ++    +++      ++     \n";
	cout << "\t ++           ++    ++   +++      ++     \n";
	cout << "\t ++++++++++  ++      ++  +++      ++     \n";
	cout << "\t ++++++++++  ++      ++  +++      ++     \n";

	cout << "\n\n\n";
	SetColor(LightGreen, Black);
	if (MenuChoise() == 0)
	{

	}
	else
	{
		exit(0);
	}

}
void Digger::HeroConsole(string str, int posy)
{
	SetCursor(7, posy);
	cout << str;
}
void Digger::ClearHeroConsole()
{
	SetCursor(7, constHeroConsole);
	cout << "                                                                                                 \n";
	cout << "                                                                                                 \n";
	cout << "                                                                                                 \n";
	cout << "                                                                                                 \n";
	cout << "                                                                                                 \n";
	cout << "                                                                                                 \n";
}
void Digger::Finding(Helmet * item)
{
	string str = "  > I found " + item->GetName();
	HeroConsole(str, constHeroConsole + 1);
	bool temp = item->ShowItem(posFindx, posFindy);
	if (temp)
	{
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.Black);
		hero.Equip(item);
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.LightGreen);
	}
}
void Digger::Finding(Cuirass * item)
{
	string str = "  > I found " + item->GetName();
	HeroConsole(str, constHeroConsole + 1);
	bool temp = item->ShowItem(posFindx, posFindy);
	if (temp)
	{
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.Black);
		hero.Equip(item);
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.LightGreen);
	}
}
void Digger::Finding(Gloves * item)
{
	string str = "  > I found " + item->GetName();
	HeroConsole(str, constHeroConsole + 1);
	bool temp = item->ShowItem(posFindx, posFindy);
	if (temp)
	{
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.Black);
		hero.Equip(item);
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.LightGreen);
	}
}
void Digger::Finding(Pants * item)
{
	string str = "  > I found " + item->GetName();
	HeroConsole(str, constHeroConsole + 1);
	bool temp = item->ShowItem(posFindx, posFindy);
	if (temp)
	{
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.Black);
		hero.Equip(item);
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.LightGreen);
	}
}
void Digger::Finding(Boots * item)
{
	string str = "  > I found " + item->GetName();
	HeroConsole(str, constHeroConsole + 1);
	bool temp = item->ShowItem(posFindx, posFindy);
	if (temp)
	{
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.Black);
		hero.Equip(item);
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.LightGreen);
	}
}
void Digger::Finding(Shield * item)
{
	string str = "  > I found " + item->GetName();
	HeroConsole(str, constHeroConsole + 1);
	bool temp = item->ShowItem(posFindx, posFindy);
	if (temp)
	{
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.Black);
		hero.Equip(item);
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.LightGreen);
	}
}
void Digger::Finding(OneHandleWeapon * item)
{
	string str = "  > I found " + item->GetName();
	HeroConsole(str, constHeroConsole + 1);
	bool temp = item->ShowItem(posFindx, posFindy);
	if (temp)
	{
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.Black);
		hero.Equip(item);
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.LightGreen);
	}
}
void Digger::Finding(TwoHandleWeapon * item)
{
	string str = "  > I found " + item->GetName();
	HeroConsole(str, constHeroConsole + 1);
	bool temp = item->ShowItem(posFindx, posFindy);
	if (temp)
	{
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.Black);
		hero.Equip(item);
		hero.Show(HeroInterfaceposx, HeroInterfaceposy, hero.LightGreen);
	}
}
void Digger::Finding()
{
	HeroConsole(pfrases.Find(), constHeroConsole);
	switch (rand() % 8)
	{
	case 0:
		Finding(new Helmet);
		break;
	case 1:
		Finding(new Cuirass);
		break;
	case 2:
		Finding(new Gloves);
		break;
	case 3:
		Finding(new Shield);
		break;
	case 4:
		Finding(new Pants);
		break;
	case 5:
		Finding(new Boots);
		break;
	case 6:
		Finding(new OneHandleWeapon);
		break;
	case 7:
		Finding(new TwoHandleWeapon);
		break;
	}
	ClearHeroConsole();
}
void Digger::SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void Digger::SetCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}
void Digger::Strela(int kx, int ky, int height, int width, Color color)
{
	SetColor(color, color);
	for (size_t i = 0; i < height; i++)
	{
		SetCursor(kx, ky + i);
		for (size_t j = 0; j < width; j++)
		{
			if (j == 0 || i == height - 1)
			{
				cout << "0";
			}
		}
		cout << "\n";
	}

	for (size_t i = 0; i < height; i++)
	{
		SetCursor(kx + width, ky + i);
		for (size_t j = 0; j < width; j++)
		{
			if (j == 0)
			{
				cout << "0";
			}
		}
		cout << "\n";
	}
	SetColor(LightGreen, Black);

}
void Digger::Fight(Monster * monster)
{
	int constmonster = 40 + HeroInterfaceposx;
	HeroConsole(pfrases.Meet(), constHeroConsole);
	string str = "  > I meet " + monster->GetName();
	HeroConsole(str, constHeroConsole + 1);
	monster->Show(constmonster, HeroInterfaceposy, monster->LightGreen);

	bool CloseFight = false;

	do
	{
		int x = constmonster + 2;
		int y = HeroInterfaceposy + 7;
		int input;
		int punkt = 0;
		SetColor(LightGreen, Black);
		SetCursor(x, y);
		cout << ">";
		do
		{
			input = _getch();
			switch (input)
			{
			case 72://вверх
				if (punkt > 0)
				{
					SetColor(Black, Black);
					SetCursor(x, y);
					cout << ">";
					punkt--;
					y--;
					SetColor(LightGreen, Black);
					SetCursor(x, y);
					cout << ">";
				}
				break;

			case 80://вниз
				if (punkt < 2)
				{
					SetColor(Black, Black);
					SetCursor(x, y);
					cout << ">";
					punkt++;
					y++;
					SetColor(LightGreen, Black);
					SetCursor(x, y);
					cout << ">";
				}
				break;
			case 13:
				SetColor(Black, Black);
				SetCursor(x, y);
				cout << ">";
				SetColor(LightGreen, Black);
				break;
			default:
				break;
			}
		} while (input != 13);//клавиша Enter
		

		ClearHeroConsole();
		string str = "";
		switch (punkt)
		{
		case 0:
			CloseFight = Attack(monster);
			monster->ReShowHP(constmonster, HeroInterfaceposy);
			
			if (CloseFight)
			{
				HeroConsole(pfrases.Kill(), constHeroConsole + 3);
				str = "  > I killed " + monster->GetName();
				HeroConsole(str, constHeroConsole + 4);
				Sleep(3000);
				for (size_t i = 0; i < 10; i++)
				{
					SetCursor(HeroInterfaceposx + 40, HeroInterfaceposy + i);
					cout << "                                              ";
				}
				SetCursor(4, constHeroConsole);
				cout << "                                                                     ";
				SetCursor(4, constHeroConsole+1);
				cout << "                                                                     ";
				Finding();
			}
			break;
		case 1:
			Heal();
			hero.ReShowHP(HeroInterfaceposx, HeroInterfaceposy);
			break;
		case 2:
			CloseFight = TryToRun();
			if (CloseFight)
			{

				HeroConsole(pfrases.RunSucess(), constHeroConsole);
				str = "  > I ran away from " + monster->GetName();
				HeroConsole(str, constHeroConsole + 1);
				monster->Show(constmonster, HeroInterfaceposy, monster->Black);
			}
			else
			{
				HeroConsole(pfrases.RunFailure(), constHeroConsole);
				str = "  > I could not escape from " + monster->GetName();
				HeroConsole(str, constHeroConsole + 1);
			}
			break;
		}
		Sleep(1000);
		if (!CloseFight)
		{
			CloseFight = Defence(monster);
		}
		hero.ReShowHP(HeroInterfaceposx, HeroInterfaceposy);
	} while (!CloseFight);
}

