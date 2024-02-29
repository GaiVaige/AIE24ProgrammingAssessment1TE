#pragma once
#ifndef PLAYHER_H
#define PLAYER_H
#include "Twine.h"
#include "Spool.h"
#include "Item.h"
#include "Room.h"
#include "Spell.h"
#include "Stats.h"

static Twine validUtilityCommands[3]{
		"help",
		"stats",
		"list",
};

static Twine validItemCommands[3]{
	"use",
	"look",
	"examine",
};

static Twine validRoomCommands[5]{
	"search",
	"inspect",
	"open",
	"investigate",
	"turn on",
};

static Twine validMoveCommands[5]{
	"move",
	"go to",
	"head",
	"go",
	"move to",
};

static Twine validCombatCommands[5]{
	"cast",
	"search",
	"check",
	"spell",
	"attack",
};

static Twine validDialougeCommands[4]{
	"talk",
	"speak",
	"talk to",
	"speak to",
};

static Twine Directions[4]{
	"north",
	"east",
	"south",
	"west",
};




class Player {
public:

	Room* currentRoom = nullptr;
	Stats s;
	Item** playerInventory;
	Spell** spells;
	Spool spellBook;
	Twine inputTwine;
	Twine name;
	int spellCount;
	int displaceVal;
	int xCord = 0;
	int yCord = 0;
	int numberOfItems = 0;
	int health;
	bool flags[10]{
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	};



	
	Player();
	~Player();

	void CheckForValidCommand(Twine& searchT);
	void AddItem(Item& c);
	Twine SearchItem(Twine& searchT);
	void MovePlayer(int i);
	void SpellLookUp(Twine searchT);
	void LearnSpell(Spell* sp);
	void Attack(Twine searchT);
	void ApplyDam(Entity* e, bool crit);
	void CastSpell(Twine searchT);
	void InitPlayer();
	void FullSpellList();
	void PlayerStats();
	void SpellSort();
	void CommandOutput();

};





#endif // !PLAYHER_H
