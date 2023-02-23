#pragma once
using namespace std;
class Monster
{
	std::string Name;

	int Damage;
	int Defence;
	int Level;

	std::vector<std::string> FN;
	std::vector<std::string> SN;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	void SetCursor(int x, int y);




public:	
	enum Color {
		Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
		DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
	};
private:
	void SetColor(Color text, Color background);
public:
	string GetName();
	int getDamage();
	int getDefence();

	int currentHP;
	void ReShowHP(int posx, int posy);
	void Show(int posx, int posy, Color color);
	Monster(int lvl);
	~Monster();
};

