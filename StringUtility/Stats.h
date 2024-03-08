#pragma once
#include "time.h"
#include "random"

struct Stats {

	int Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma;


	//initialises stats at set values
	void InitStats(int Str, int Dex, int Con, int Int, int Wis, int Cha) {
		Strength = Str;
		Dexterity = Dex;
		Constitution = Con;
		Intelligence = Int;
		Wisdom = Wis;
		Charisma = Cha;
	}

	//updates a stat (ID from 1-6) by adding a value
	void UpdateStat(int ID, int addVal) {
		switch (ID) {
		default:
			break;
		case 1:
			Strength += addVal;
		case 2:
			Dexterity += addVal;
		case 3:
			Constitution += addVal;
		case 4:
			Intelligence += addVal;
		case 5:
			Wisdom += addVal;
		case 6:
			Charisma += addVal;
		}
	}
};