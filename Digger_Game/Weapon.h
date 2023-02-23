#pragma once
using namespace std;
class Weapon
{
	std::vector<std::string> n1{ "sword", "axe", "nail clipper", "hammer", "dagger" };
	std::vector<std::string> n2{ "grossword", "longsword", "axe", "hammer", "steel eggs", "murderous charisma", "brass knuckles", "crusader sword" };


	enum Color {
		Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
		DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
	};

	void SetColor(Color text, Color background);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


	void SetCursor(int x, int y);
	void Strela(int kx, int ky, int height, int width, Color color);


protected:
	int Damage;
	int Hands;
	std::string Typ;

	std::string Name;
	std::vector<std::string> Names;
	
public:
	string GetName();
	bool ShowItem(int x, int y);
	void Show(int x, int y);
	int GetDamage();
	Weapon(int hands);
	~Weapon();
};

