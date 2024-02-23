#pragma once
#include "time.h"
#include "random"

struct Stats {

	int Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma;



	void InitStats(int Str, int Dex, int Con, int Int, int Wis, int Cha) {
		Strength = Str;
		Dexterity = Dex;
		Constitution = Con;
		Intelligence = Int;
		Wisdom = Wis;
		Charisma = Cha;
	}


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

	int Roll(int ID) {

		srand((unsigned int)(time(NULL)));
		int rollRaw = rand()%20;

		switch (ID) {
		default:
			break;
		case 1:
			return rollRaw + this->Strength;
		case 2:
			return rollRaw + this->Dexterity;
		case 3:
			return rollRaw + this->Constitution;
		case 4:
			return rollRaw + this->Intelligence;
		case 5:
			return rollRaw + this->Wisdom;
		case 6:
			return rollRaw + this->Charisma;
		}

	}
};