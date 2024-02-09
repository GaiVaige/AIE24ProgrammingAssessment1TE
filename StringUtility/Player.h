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
	int numberOfItems = 0;
	Player();
	~Player();

	void AddItem(Item& c);
	void RemoveItem(Item& it);
	void RefactorInventory(int newSize);
	void SearchItem(Twine& searchT);



};





#endif // !PLAYHER_H
