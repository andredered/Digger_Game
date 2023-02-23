#pragma once

using namespace std;
class Pfrases
{

	vector<string> AttackPfrases;
	vector<string> KillPfrases;
	vector<string> RunSucessPfrases;
	vector<string> RunFailurePfrases;
	vector<string> DefencePfrases;
	vector<string> HealPfrases;
	vector<string> FindPfrases;
	vector<string> TrapPfrases;
	vector<string> DeadingPfrases;
	vector<string> DodgePfrases;
	vector<string> MeetingPfrases;

public:
	string Attack();
	string Kill();
	string RunSucess();
	string RunFailure();
	string Defence();
	string Heal();
	string Find();
	string Trap();
	string Deading();
	string Dodge();
	string Meet();


	Pfrases();
	~Pfrases();
};

