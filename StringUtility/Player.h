#pragma once
#ifndef PLAYHER_H
#define PLAYER_H
#include "Twine.h"
#include "Item.h"
#include "Candle.h"


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
	int numberOfItems = 0;
	Player();
	~Player();

	void CheckForValidCommand(Twine& searchT);
	void AddItem(Item& c);
	void RemoveItem(Item& it);
	void RefactorInventory(int newSize);
	void SearchItem(Twine& searchT);



};





#endif // !PLAYHER_H
