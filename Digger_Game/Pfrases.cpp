#include "stdafx.h"
#include "Pfrases.h"
Pfrases::Pfrases()
{
	AttackPfrases.push_back("Foot in the face!");
	AttackPfrases.push_back("Punch, punch, another punch!");
	AttackPfrases.push_back("Taste the fist, fucker.");
	AttackPfrases.push_back("Wow, bitch, you’ll get the dagger in the body now!");
	AttackPfrases.push_back("Taste my sword!");
	AttackPfrases.push_back("Oik! So deadly punch. How are you?");
	AttackPfrases.push_back("And I can bite!");
	AttackPfrases.push_back("Give up, snot!");
	AttackPfrases.push_back("Dont trying, fucker.");
	AttackPfrases.push_back("You have no chanses!");
	AttackPfrases.push_back("Someone’s blood flowed...");

	KillPfrases.push_back("Oh, where did you lose your head? Ah, here it is lying!");
	KillPfrases.push_back("And I'm a winner again.");
	KillPfrases.push_back("I-Bitch : One-Zero");
	KillPfrases.push_back("Glorious day for your death.");
	KillPfrases.push_back("You lost a rib! It will be mine!");
	KillPfrases.push_back("You will make a great dinner.");
	KillPfrases.push_back("Go away! Ah, you can’t...");
	KillPfrases.push_back("And don’t get up.");
	KillPfrases.push_back("Why did you die?! I just warmed up.");
	KillPfrases.push_back("*spitting on a corpse and meaningful silence*");

	RunSucessPfrases.push_back("Hehe, and I’m quicker!");
	RunSucessPfrases.push_back("Woo bitch! Next time will be your last!");
	RunSucessPfrases.push_back("What, did the laces get loose?");
	RunSucessPfrases.push_back("Oh oh oh. Fucking. Bitch. Fucked up. Barely snuffed.");
	RunSucessPfrases.push_back("Almost ass burned.");
	RunSucessPfrases.push_back("You are fast. But I'm faster.");

	RunFailurePfrases.push_back("FUCK! FUCK! FUCK! FUCK!");
	RunFailurePfrases.push_back("Fuck you nasty fag!");
	RunFailurePfrases.push_back("Too close, TOO close, TOO CLOSEEEE!!!");
	RunFailurePfrases.push_back("Do you even have a rest?");
	RunFailurePfrases.push_back("ASS BURNS");
	RunFailurePfrases.push_back("NO-NO-NO! DEAD END!");
	RunFailurePfrases.push_back("Ah fucking. I stumbled.");

	DefencePfrases.push_back("OJK! FUCK!");
	DefencePfrases.push_back("Arrgh!");
	DefencePfrases.push_back("Hurts.");
	DefencePfrases.push_back("So painfull...");
	DefencePfrases.push_back("Urrgh!");
	DefencePfrases.push_back("OJK!");
	DefencePfrases.push_back("My head!");
	DefencePfrases.push_back("I’M BLEEDEENG!");
	DefencePfrases.push_back("*illegible grunts*");
	DefencePfrases.push_back("I WILL CUT YOU IN PIECES!");
	DefencePfrases.push_back("My revenge will be so sweet.");

	DodgePfrases.push_back("That was so close.");
	DodgePfrases.push_back("Ough. Barely dodged.");
	DodgePfrases.push_back("You are fast. But I’m faster.");
	DodgePfrases.push_back("Accuracy you do not take.");
	DodgePfrases.push_back("Well, you almost hit me. Loser.");

	HealPfrases.push_back("For lack of bandages I applied electrical tape.");
	HealPfrases.push_back("It’ll get better now.");
	HealPfrases.push_back("And without bleeding I feel great!");
	HealPfrases.push_back("I sewed the severed leg back.");
	HealPfrases.push_back("GOD HELP ME!");
	HealPfrases.push_back("WHERE IS MY BANDAGE?");
	HealPfrases.push_back("Ohhh, my drugs, mmmmm...");

	FindPfrases.push_back("Look what is lying around here!");
	FindPfrases.push_back("What a value!");
	FindPfrases.push_back("A bauble... But maybe it will help?");
	FindPfrases.push_back("So. Dead body. With this garbage.");
	FindPfrases.push_back("Wait! What is this?");
	FindPfrases.push_back("Woohoo! Something new! Ah, no. It’s not a ring.");
	FindPfrases.push_back("I’m so lucky!");

	DeadingPfrases.push_back("too... cold...");
	DeadingPfrases.push_back("I’m so weak... I take a rest... I want to sleep...");
	DeadingPfrases.push_back("that's the end...");
	DeadingPfrases.push_back("how heavy my head is...");
	DeadingPfrases.push_back("how warm...");
	DeadingPfrases.push_back("it can’t end like this...");
	DeadingPfrases.push_back("I can’t feel my legs...");

	TrapPfrases.push_back("WHERE FROM HERE A FUCKING DRAWER?!");
	TrapPfrases.push_back("I hope these darts were not poisonous.");
	TrapPfrases.push_back("This trap impressed me in the wall. Thank God, not with axe.");
	TrapPfrases.push_back("From today, I officially declare: I hate rain from spiders.");
	TrapPfrases.push_back("Escaped with a couple of snake bites. If it gets bad, I’ll cut off this damn leg.");
	TrapPfrases.push_back("Oh, well, very original, of course. The goblin ran and splashed acid on my face. Now it itches.");
	TrapPfrases.push_back("Yes, I’ll shove this lance in you!");
	TrapPfrases.push_back("How could spears be hidden under stones so that I would step on them?");
	TrapPfrases.push_back("Plus poisoning, minus leg.");
	TrapPfrases.push_back("I just didn’t have enough bleeding.");
	TrapPfrases.push_back("I bit my tongue. It hurts me.");

	MeetingPfrases.push_back("Woa! Who is this pretty monster?");
	MeetingPfrases.push_back("This time I won’t run away.");
	MeetingPfrases.push_back("Well, well, well... Anoter fight for a great hero.");
	MeetingPfrases.push_back("Who is so cute here? Get ready for death!");
	MeetingPfrases.push_back("Will we dance?");
	MeetingPfrases.push_back("How do you feel about... well, say, to eternal torment in hell?");
	MeetingPfrases.push_back("Nice day for a deadly battle.");
	MeetingPfrases.push_back("Is it a monster for the great me? Well, it's time to cut and run.");
	MeetingPfrases.push_back("Oh no! I’m looking at something disgusting!");
}
string Pfrases::Meet()
{
	return MeetingPfrases.at(rand()% MeetingPfrases.size());
}

string Pfrases::Attack()
{
	return AttackPfrases.at(rand()% AttackPfrases.size());
}

string Pfrases::Kill()
{
	return KillPfrases.at(rand()% KillPfrases.size());
}

string Pfrases::RunSucess()
{
	return RunSucessPfrases.at(rand()% RunSucessPfrases.size());
}

string Pfrases::RunFailure()
{
	return RunFailurePfrases.at(rand()% RunFailurePfrases.size());
}

string Pfrases::Defence()
{
	return DefencePfrases.at(rand()% DefencePfrases.size());
}

string Pfrases::Heal()
{
	return HealPfrases.at(rand()% HealPfrases.size());
}

string Pfrases::Find()
{
	return FindPfrases.at(rand()% FindPfrases.size());
}

string Pfrases::Trap()
{
	return TrapPfrases.at(rand()% TrapPfrases.size());
}

string Pfrases::Deading()
{
	return DeadingPfrases.at(rand()% DeadingPfrases.size());
}

string Pfrases::Dodge()
{
	return DodgePfrases.at(rand()% DodgePfrases.size());
}




Pfrases::~Pfrases()
{
}
