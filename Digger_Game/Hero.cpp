#include "stdafx.h"
#include "Hero.h"

using namespace std;

void Hero::SetCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}
void Hero::SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Hero::ReShowHP(int posx, int posy)
{
	SetColor(LightGreen, Black);
	posy += 2;
	posx += 5;
	SetCursor(posx, posy);
	cout << currentHP << "   ";
}

void Hero::Show(int posx, int posy, Color color)
{
	SetColor(color, Black);
	SetCursor(posx, posy);
	cout << "Hero : ";
	cout << Name << ";";
	posy+=2;
	SetCursor(posx, posy);
	cout << "HP : " << currentHP;
	posy++;
	SetCursor(posx, posy);
	cout << "Attack : " << currentDamage;
	posy++;
	SetCursor(posx, posy);
	cout << "Defence : " << currentDefence;
	posy++;
	SetCursor(posx, posy);
	cout << "Dodge : " << currentDoudge;
	posy+=3;
	SetCursor(posx, posy);
	cout << "Head";
	posy++;
	SetCursor(posx, posy);
	if (Head != nullptr)
	{
		Head->Show(posx, posy);
	}
	else
	{
		cout << "nothing";
	}
	posy+=3;
	SetCursor(posx, posy);
	cout << "Body";
	posy++;
	SetCursor(posx, posy);
	if (Body != nullptr)
	{
		Body->Show(posx, posy);
	}
	else
	{
		cout << "nothing";
	}
	posy+=3;
	SetCursor(posx, posy);
	cout << "Arms";
	posy++;
	SetCursor(posx, posy);
	if (Arms != nullptr)
	{
		Arms->Show(posx, posy);
	}
	else
	{
		cout << "nothing";
	}
	posy+=3;
	SetCursor(posx, posy);
	cout << "Legs";
	posy++;
	SetCursor(posx, posy);
	if (Legs != nullptr)
	{
		Legs->Show(posx, posy);
	}
	else
	{
		cout << "nothing";
	}
	posy+=3;
	SetCursor(posx, posy);
	cout << "Foots";
	posy++;
	SetCursor(posx, posy);
	if (Foots != nullptr)
	{
		Foots->Show(posx, posy);
	}
	else
	{
		cout << "nothing";
	}
	posy+=3;
	SetCursor(posx, posy);
	if (RightHandT != nullptr)
	{

		cout << "Right and Left Hands";
		posy++;
		SetCursor(posx, posy);
		RightHandT->Show(posx, posy);
	}
	else
	{
		cout << "Left Hand";
		posy++;
		SetCursor(posx, posy);
		if (LeftHand != nullptr)
		{
			LeftHand->Show(posx, posy);
		}
		else
		{
			cout << "nothing";
		}
		posy+=3;
		SetCursor(posx, posy);
		cout << "Right Hand";
		posy++;
		SetCursor(posx, posy);
		if (RightHandO != nullptr)
		{
			RightHandO->Show(posx, posy);
		}
		else
		{
			cout << "nothing";
		}
	}
	SetColor(LightGreen, Black);
}



Hero::Hero()
{
	names.push_back("Erl di'Reiny");
	names.push_back("Ashtafort di'Reiny");
	names.push_back("Maus di'Reiny");
	names.push_back("Mern di'Reiny");

	names.push_back("Maus fon Lellenkay");
	names.push_back("Anissa fon Lellenkay");
	names.push_back("Ilerya fon Lellenkay");
	names.push_back("Ernesto fon Lellenkay");
	
	names.push_back("Freejack Gutless");
	names.push_back("Anna");
	names.push_back("Main");
	names.push_back("Mern the Demon");
	names.push_back("Gandzi");
	names.push_back("Lilare the Great");
	names.push_back("Lesley Dron");
	names.push_back("Syndragosa");

	Name = names.at(rand() % names.size());
}


int Hero::GetHP()
{
	return maxHP;
}

int Hero::GetAttack()
{
	return currentDamage;
}

int Hero::GetDefence()
{
	return currentDefence;
}

int Hero::GetDodge()
{
	return currentDoudge;
}

string Hero::GetName()
{
	return Name;
}













//========================================================================================
void Hero::Equip(Helmet*h)
{
	if (Head != nullptr)
	{
		currentDoudge -= Head->GetDodge();
		currentDefence -= Head->GetDefence();
	}
	Head = h;
	currentDoudge += Head->GetDodge();
	currentDefence += Head->GetDefence();
}
void Hero::Equip(Cuirass*c)
{
	if (Body != nullptr)
	{
		currentDoudge -= Body->GetDodge();
		currentDefence -= Body->GetDefence();
	}
	Body = c;
	currentDoudge += Body->GetDodge();
	currentDefence += Body->GetDefence();
}
void Hero::Equip(Gloves*g)
{
	if (Arms != nullptr)
	{
		currentDoudge -= Arms->GetDodge();
		currentDefence -= Arms->GetDefence();
	}
	Arms = g;
	currentDoudge += Arms->GetDodge();
	currentDefence += Arms->GetDefence();
}
void Hero::Equip(Pants*p)
{
	if (Legs != nullptr)
	{
		currentDoudge -= Legs->GetDodge();
		currentDefence -= Legs->GetDefence();
	}
	Legs = p;	
	currentDoudge += Legs->GetDodge();
	currentDefence += Legs->GetDefence();
}
void Hero::Equip(Boots*b)
{
	if (Foots != nullptr)
	{
		currentDoudge -= Foots->GetDodge();
		currentDefence -= Foots->GetDefence();
	}
	Foots = b;
	currentDoudge += Foots->GetDodge();
	currentDefence += Foots->GetDefence();
}
void Hero::Equip(Shield*s)
{
	if (LeftHand != nullptr)
	{
		currentDoudge -= LeftHand->GetDodge();
		currentDefence -= LeftHand->GetDefence();
	}
	if (RightHandT != nullptr)
	{
		currentDamage = MinDamage;
		RightHandT = nullptr;
	}
	LeftHand = s;
	currentDoudge += LeftHand->GetDodge();
	currentDefence += LeftHand->GetDefence();
}
void Hero::Equip(OneHandleWeapon*ohw)
{
	if (RightHandT != nullptr)
	{
		RightHandT = nullptr;
	}
	RightHandO = ohw;
	currentDamage = RightHandO->GetDamage();
}
void Hero::Equip(TwoHandleWeapon*thw)
{
	if (LeftHand != nullptr)
	{
		currentDoudge -= LeftHand->GetDodge();
		currentDefence -= LeftHand->GetDefence();
		LeftHand = nullptr;
	}
	if (RightHandO != nullptr)
	{
		RightHandO = nullptr;
	}
	RightHandT = thw;
	currentDamage = RightHandT->GetDamage();
}
