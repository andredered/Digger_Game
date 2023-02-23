#include "stdafx.h"
#include "Weapon.h"


void Weapon::SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void Weapon::SetCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}


void Weapon::Strela(int kx, int ky, int height, int width, Color color)
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



string Weapon::GetName()
{
	return Name;
}

bool Weapon::ShowItem(int x, int y)
{
	int statx = x;
	int staty = y;
	SetCursor(x, y);
	if (Hands == 1)
	{
		cout << "I found this one-handed weapon:";
	}
	if (Hands == 2)
	{
		cout << "I found this two-handed weapon:";
	}
	y++;
	SetCursor(x, y);
	cout << Name;
	y++;
	SetCursor(x, y);
	cout << Damage << " damage";
	x += 4;
	SetCursor(x, y + 3);
	cout << "equip";
	SetCursor(x + 17, y + 3);
	cout << "drop";

	int input, punkt = 0;
	int kx = x - 1, ky = y + 3;
	int height = 2, width = 6;


	Strela(kx, ky, height, width, White);
	do
	{
		input = _getch();
		switch (input)
		{
		case 75://âëåâî

			if (punkt == 0)
			{
				break;
			}
			else
			{
				Strela(kx, ky, height, width, Black);
				kx -= 17;
				punkt--;
			}
			switch (punkt)
			{
			case 0:
				width = 6;
				break;

			case 1:
				width = 5;
				break;
			}
			Strela(kx, ky, height, width, White);
			break;

		case 77://âïðàâî

			if (punkt == 1)
			{
				break;
			}
			else
			{
				Strela(kx, ky, height, width, Black);
				kx += 17;
				punkt++;
			}
			switch (punkt)
			{
			case 0:
				width = 6;
				break;

			case 1:
				width = 5;
				break;
			}
			Strela(kx, ky, height, width, White);
			break;

		}
	} while (input != 13);//êëàâèøà Enter

	for (size_t i = 0; i < 8; i++)
	{
		SetCursor(statx, staty);
		cout << "                                          ";
		staty++;
	}



	if (punkt == 0)
	{
		return true;
	}
	else if (punkt == 1)
	{
		return false;
	}
}

void Weapon::Show(int x, int y)
{
	SetCursor(x, y);
	cout << Name;
	y++;
	SetCursor(x, y);
	cout << Damage << " damage";
}

int Weapon::GetDamage()
{
	return Damage;
}

Weapon::Weapon(int hands)
{
	int dmg = rand() % 21 + 20;
	int s = rand() %50;
	if (s == 0)
	{
		Typ = "Legendary";
		dmg *= 2;
	}
	else if (s <= 2)
	{
		Typ = "Epic";
		dmg *= 1.5;
	}
	else if (s <= 8)
	{
		Typ = "Rare";
		dmg *= 1;
	}
	else
	{
		Typ = "Common";
		dmg *= 0.7;
	}
	Hands = hands;

	Names.push_back("of young Swordman");
	Names.push_back("of great Archers");
	Names.push_back("of acceleration");
	Names.push_back("of dead Slave");
	Names.push_back("of fading Soul");
	Names.push_back("of fallen Àngel");
	Names.push_back("of àgent Overwatch");
	Names.push_back("of Lilare the Great");
	Names.push_back("of loving Granny");
	Names.push_back("of îld Grunt");
	Names.push_back("of missing Person");
	Names.push_back("of underworld Demon");

	std::string a = "";
	if (hands == 1)
	{
		a = n1.at(rand()%n1.size());
	}
	else
	{
		a = n2.at(rand() % n2.size());
		dmg += rand()%16;
	}

	Name = Typ + " " + a + " " + Names.at(rand() % Names.size());
	Damage = dmg;
}


Weapon::~Weapon()
{
}
