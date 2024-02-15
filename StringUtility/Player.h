#pragma once
#ifndef PLAYHER_H
#define PLAYER_H
#include "Twine.h"
#include "Item.h"
#include "Room.h"


class Player {
public:
	int xCord = 0;
	int yCord = 0;
	Room* currentRoom = nullptr;
	Twine inputTwine;
	Twine name;
	Item** playerInventory;
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

	Twine validSpellCommands[5]{
		"cast",
		"summon",
		"look up",
		"check",
		"spell",
	};

	Twine Directions[4]{
		"north",
		"east",
		"south",
		"west",
	};

	int numberOfItems = 0;

	Player();
	~Player();

	void CheckForValidCommand(Twine& searchT);
	void AddItem(Item& c);
	void SearchItem(Twine& searchT);
	void MovePlayer(int i);


};





#endif // !PLAYHER_H
