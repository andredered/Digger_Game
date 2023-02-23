#include "stdafx.h"
#include "Field.h"

using namespace std;


void Field::SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void Field::SetCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}

void Field::SetColorField( int j, int i)
{
	if (mas[i][j] == Wall)
	{
		SetColor(Green, Green);
	}
	if (mas[i][j] == Pass)
	{
		SetColor(White, White);
	}
	if (mas[i][j] == NextLevel)
	{
		SetColor(Blue, Blue);
	}
}

void Field::ShowAll()
{
	for (size_t i = 0; i < 30; i++)
	{
		for (size_t j = 0; j < 60; j++)
		{
			SetColorField(j, i);
			SetCursor(tempx - posx + j, tempy-posy + i);
			cout << "+";
		}
	}
}

bool Field::Move(int direction)
{
	mas[posy][posx] = Pass;
	tempMove = false;
	if (direction == W ) //W
	{
		if (mas[posy - 1][posx] != Wall)
		{
			posy--;
			tempy--;
			tempMove = true;
		}
	}
	if (direction == A ) //A
	{
		if (mas[posy][posx - 1] != Wall)
		{
			posx--;
			tempx--;
			tempMove = true;
		}
	}
	if (direction == S) //S
	{
		if (mas[posy + 1][posx] != Wall)
		{
			posy++;
			tempy++;
			tempMove = true;
		}
	}
	if (direction == D ) //D
	{
		if (mas[posy][posx + 1] != Wall)
		{
			posx++;
			tempx++;
			tempMove = true;
		}
		
	}
	if (mas[posy][posx] == NextLevel)
	{
		tempMove = true;
		return false;

	}
	mas[posy][posx] = Hero;
	Show();
	return true;
}

void Field::Show()
{	

	SetColorField(posx + 1, posy);
	SetCursor(tempx + 1, tempy);
	cout << "+";
	
	SetColorField(posx - 1, posy);
	SetCursor(tempx - 1 , tempy);
	cout << "+";
	
	SetColorField(posx, posy + 1);
	SetCursor(tempx, tempy + 1);
	cout << "+";
	
	SetColorField(posx, posy - 1);
	SetCursor(tempx, tempy - 1);
	cout << "+";


	SetColor(LightRed, LightRed);
	SetCursor(tempx, tempy);
	cout << "+";
	SetColor(LightGreen, Black);
}

Field::Field(int Mas[30][60])
{
	for (size_t i = 0; i < 30; i++)
	{
		for (size_t j = 0; j < 60; j++)
		{
			mas[i][j] = 0;
		}
	}

	for (size_t i = 1; i < 29; i++)
	{
		for (size_t j = 1; j < 59; j++)
		{
			if (Mas[i][j] == 0 && rand()%9 < 4)
			{
				mas[i][j] = 1;
			}
			else
			{
				mas[i][j] = Mas[i][j];
			}
			if (mas[i][j] == 2)
			{
				posy = i;
				posx = j;
				tempy += posy;
				tempx += posx;
			}
		}
	}
}



Field::~Field()
{
}
