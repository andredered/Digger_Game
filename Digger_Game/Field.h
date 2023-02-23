#pragma once

class Field
{


	enum Color {
		Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
		DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
	};

	enum { Wall = 0, Pass = 1, Hero = 2, NextLevel = 3 };
	enum { W = 72, A = 75, S = 80, D = 77 };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int mas[30][60];
	int posx;
	int posy;
	int tempx = 10;
	int tempy = 3;
	void SetColorField(int i, int j);

	void SetColor(Color text, Color background);
	void SetCursor(int x, int y);
public:
	bool tempMove;
	void ShowAll();
	bool Move(int direction);
	void Show();
	Field(int Mas[30][60]);
	~Field();
};

