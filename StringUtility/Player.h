#pragma once
#ifndef PLAYHER_H
#define PLAYER_H
#include "Twine.h"
#include "Spool.h"
#include "Item.h"
#include "Room.h"
#include "Spell.h"
#include "Stats.h"

class Player {
public:

	Twine validUtilityCommands[3]{
		"help",
		"stats",
		"list",
	};

	Twine validItemCommands[3]{
		"use",
		"look",
		"examine",
	};

	Twine validRoomCommands[5]{
		"search",
		"inspect",
		"open",
		"investigate",
		"turn on",
	};

	Twine validMoveCommands[5]{
		"move",
		"go to",
		"head",
		"go",
		"move to",
	};

	Twine validCombatCommands[5]{
		"cast",
		"search",
		"check",
		"spell",
		"attack",
	};

	Twine validDialougeCommands[4]{
		"talk",
		"speak",
		"talk to",
		"speak to",
	};

	Twine Directions[4]{
		"north",
		"east",
		"south",
		"west",
	};






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
	void SearchItem(Twine& searchT);
	void MovePlayer(int i);
	void SpellLookUp(Twine searchT);
	void LearnSpell(Spell* sp);
	void Attack(Twine searchT);
	void ApplyDam(Entity* e);
	void CastSpell(Twine searchT);
	void InitPlayer();
	void FullSpellList();
	void PlayerStats();
	void SpellSort();
	void CommandOutput();

};





#endif // !PLAYHER_H
