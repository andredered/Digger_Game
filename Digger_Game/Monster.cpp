#include "stdafx.h"
#include "Monster.h"


void Monster::SetCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}
void Monster::SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

string Monster::GetName()
{
	return Name;
}

int Monster::getDamage()
{
	return Damage;
}

int Monster::getDefence()
{
	return Defence;
}

void Monster::ReShowHP(int posx, int posy)
{
	SetColor(LightGreen, Black);
	posy += 2;
	posx += 5;
	SetCursor(posx, posy);
	cout << currentHP << "   ";
}

void Monster::Show(int posx, int posy, Color color)
{
	SetColor(color, Black);
	SetCursor(posx, posy);
	cout << "Monster : ";
	cout << Name << ";";
	posy += 2;
	SetCursor(posx, posy);
	cout << "HP : " << currentHP;
	posy++;
	SetCursor(posx, posy);
	cout << "Attack : " << Damage;
	posy++;
	SetCursor(posx, posy);
	cout << "Defence : " << Defence;


	posy += 3;
	posx += 4;
	SetCursor(posx, posy);
	cout << "Attack";
	posy ++;
	SetCursor(posx, posy);
	cout << "Treat yourself";
	posy++;
	SetCursor(posx, posy);
	cout << "Try to run away";

	SetColor(LightGreen, Black);
}



Monster::Monster(int lvl)
{
	FN.push_back("deadly");
	FN.push_back("horrific");
	FN.push_back("vile");
	FN.push_back("little");
	FN.push_back("huge");
	FN.push_back("demonic");
	FN.push_back("dead");
	FN.push_back("cold");
	FN.push_back("electric");
	FN.push_back("nasty");
	FN.push_back("fat");
	FN.push_back("thin");
	FN.push_back("slender");
	FN.push_back("lazy");
	FN.push_back("voracious");


	SN.push_back("dragon");
	SN.push_back("rat");
	SN.push_back("spider");
	SN.push_back("slime");
	SN.push_back("angel");
	SN.push_back("demon");
	SN.push_back("undead");
	SN.push_back("zombie");
	SN.push_back("kite");
	SN.push_back("snail");
	SN.push_back("snake");
	SN.push_back("goblin");
	SN.push_back("orc");
	SN.push_back("vampire");
	SN.push_back("fiend");
	SN.push_back("spirit");
	SN.push_back("wisp");
	SN.push_back("cyclops");
	SN.push_back("ghost");
	SN.push_back("soul");
	SN.push_back("wraith");
	SN.push_back("phantom");
	SN.push_back("beetle");
	SN.push_back("bull");
	SN.push_back("McDonald's regular");
	SN.push_back("bagle");
	SN.push_back("dog");
	SN.push_back("cerberus");
	SN.push_back("ghoul");
	SN.push_back("skeleton");
	SN.push_back("worm");
	SN.push_back("drinker");
	SN.push_back("disabled");
	SN.push_back("grille");
	SN.push_back("glasses");
	SN.push_back("nail");
	SN.push_back("stick");
	SN.push_back("shawarma");
	SN.push_back("axe");
	SN.push_back("marshmallow");
	SN.push_back("carbon");
	SN.push_back("oxygen");
	SN.push_back("oil");
	SN.push_back("retro car");
	SN.push_back("shadow");
	SN.push_back("boller");
	SN.push_back("water");
	SN.push_back("trap");
	SN.push_back("Santa Claus");
	SN.push_back("Dead Moroze");
	SN.push_back("Privat Bank");
	SN.push_back("killer");
	SN.push_back("slayer");
	SN.push_back("murderer");
	SN.push_back("assassin");
	SN.push_back("thief");
	SN.push_back("archer");
	SN.push_back("swordman");
	SN.push_back("kamikaze");
	SN.push_back("something");
	SN.push_back("rubbish");
	SN.push_back("bird");
	SN.push_back("octopus");
	SN.push_back("piranha");
	SN.push_back("cake");
	SN.push_back("centurion");
	SN.push_back("khajiit");
	SN.push_back("piligrimmus");
	SN.push_back("Andrew AntiDron");
	Name = FN.at(rand() % FN.size()) + " " + SN.at(rand() % SN.size());


	Damage = rand() % 20 + 1 + 10 * lvl - 1;
	Defence = rand() % 80 + 60 * (lvl-1);
	currentHP = rand() % 81 + 50 + 30 * (lvl-2);
}


Monster::~Monster()
{
}
