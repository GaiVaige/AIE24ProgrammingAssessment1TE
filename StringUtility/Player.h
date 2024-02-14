#pragma once
#ifndef PLAYHER_H
#define PLAYER_H
#include "Twine.h"
#include "Item.h"
#include "Room.h"


class Player {
public:
	Room* TheHouse[3][3];
	int xCord = 0;
	int yCord = 0;
	Room* currentRoom = nullptr;
	Twine name;
	Item** playerInventory;
	Twine validItemCommands[3]{
		"use",
		"look",
		"examine",
	};

	Twine validRoomCommands[10]{
		"move to",
		"go",
		"head",
		"go to the",
		"search",
		"inspect",
		"open",
		"investigate",
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
	void MovePlayer();


};





#endif // !PLAYHER_H
