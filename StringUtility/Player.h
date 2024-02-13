#pragma once
#ifndef PLAYHER_H
#define PLAYER_H
#include "Twine.h"
#include "Item.h"
#include "Room.h"


class Player {
public:
	Twine name;
	Item** playerInventory;
	Twine validItemCommands[5]{
		"use",
		"look",
		"look at",
		"examine",
		"inspect",
	};

	Twine validRoomCommands[10]{
		"move",
		"go",
		"head",
		"go to the",
		"search",
		"look at",
		"open",
		"close",
		"go to",
		"turn on",
	};

	Twine validSpellCommands[5]{
		"cast",
		"summon",
		"look up",
		"check",
		"spell",
	};

	int numberOfItems = 0;

	Player();
	~Player();

	void CheckForValidCommand(Twine& searchT);
	void AddItem(Item& c);
	void SearchItem(Twine& searchT);


};





#endif // !PLAYHER_H
