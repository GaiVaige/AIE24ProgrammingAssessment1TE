#pragma once
#ifndef PLAYHER_H
#define PLAYER_H
#include "Twine.h"
#include "Spool.h"
#include "Item.h"
#include "Room.h"
#include "Spell.h"
#include "Stats.h"

static Twine validUtilityCommands[4]{
		"help",
		"stats",
		"spells",
		"items",
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

static Twine validCombatCommands[4]{
	"cast",
	"search",
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




private:
	Stats s;
	//searches for an item by name and calls its Use() function
	Twine UseItem(Twine& searchT);
	//returns a spell pointer to be used for casting spells, or returns its description
	void CastSpell(Twine& searchT);
	Spell* SpellLookUp(Twine& searchT);
	//finds an entity with the correct name
	void Attack(Twine& searchT);
	//uses the entity found above to apply damage
	void ApplyDam(Entity* e, bool crit);

	//outputs for commands 'items', 'stats', 'spells' and 'help' respectively
	void FullSpellList();
	void Inventory();
	void PlayerStats();
	void CommandOutput();

public:
	Room* currentRoom = nullptr;
	Twine inputTwine;
	Twine name;
	Item** playerInventory;
	Spell** spells;
	int spellCount;
	int displaceVal;
	int xCord = 0;
	int yCord = 0;
	int numberOfItems = 0;
	int health;
	bool flags[1]{
	false,
	};
	Player();
	~Player();
	void AddItem(Item& c);
	void CheckForValidCommand(Twine& searchT);
	void MovePlayer(int i);
	void LearnSpell(Spell* sp);
	void SpellSort();
	void InitPlayer();


};





#endif // !PLAYHER_H
