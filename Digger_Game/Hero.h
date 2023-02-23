#pragma once
#include "Boots.h"
#include "Cuirass.h"
#include "Gloves.h"
#include "Helmet.h"
#include "Pants.h"
#include "Shield.h"
#include "TwoHandleWeapon.h"
#include "OneHandleWeapon.h"

class Hero
{
	std::string Name;
	std::vector<std::string> names;


	int maxHP = 80 + rand()%41;
	int currentDoudge = rand()%30;
	int currentDefence = rand()%20;
	int currentDamage = 10 + rand()%11;
	int MinDamage = currentDamage;


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	void SetCursor(int x, int y);
	


	Helmet* Head = nullptr;
	Cuirass* Body = nullptr;
	Gloves* Arms = nullptr;
	Pants* Legs = nullptr;
	Boots* Foots = nullptr;
	Shield* LeftHand = nullptr;
	OneHandleWeapon* RightHandO = nullptr;
	TwoHandleWeapon* RightHandT = nullptr;
public:
	enum Color {
		Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
		DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
	};
	int GetHP();
	int GetAttack();
	int GetDefence();
	int GetDodge();
	string GetName();
private:
	void SetColor(Color text, Color background);
public:
	int currentHP = maxHP;
	void Equip(Helmet*h);
	void Equip(Cuirass*c);
	void Equip(Gloves*g);
	void Equip(Pants*p);
	void Equip(Boots*b);
	void Equip(Shield*s);
	void Equip(OneHandleWeapon*ohw);
	void Equip(TwoHandleWeapon*thw);

	void ReShowHP(int posx, int posy);
	void Show(int posx, int posy, Color color);
	Hero();
};

