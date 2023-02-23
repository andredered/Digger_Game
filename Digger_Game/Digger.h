#pragma once
#include "Hero.h"
#include "Monster.h"
#include "Field.h"
#include "Pfrases.h"

using namespace std;

struct mas {
	int arr[30][60];
};

class Digger
{
	Pfrases pfrases;

	int level = 0;
	vector<mas> fields;
	Hero hero;
	void menu();
	enum { W = 72, A = 75, S = 80, D = 77 };
	enum Color {
		Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
		DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
	};

	void SetColor(Color text, Color background);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	
	void SetCursor(int x, int y);

	int MenuChoise();
	void Strela(int kx, int ky, int height, int width, Color color);

	void something(Field temp);
	
	int HeroInterfaceposx = 77;
	int HeroInterfaceposy = 3;

	void HeroConsole(string str, int posy);
	void ClearHeroConsole();

	void Finding(Helmet*item);
	void Finding(Cuirass*item);
	void Finding(Gloves*item);
	void Finding(Pants*item);
	void Finding(Boots*item);
	void Finding(Shield*item);
	void Finding(OneHandleWeapon*item);
	void Finding(TwoHandleWeapon*item);

	void Finding();
	void Fight(Monster*monster);


	int constHeroConsole = 40;

	int posFindx = 117;
	int posFindy = 5;

	bool Attack(Monster * monster);
	void Heal();
	bool TryToRun();
	bool Defence(Monster * monster);
public:
	void game();

	Digger();
};

