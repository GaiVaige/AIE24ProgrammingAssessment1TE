#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "Twine.h"
#include <iostream>


class Item {
public:
	Twine name;
	bool hasItem;
	int itemSlot = 0;

	Item();
	~Item();
	virtual void SetName(Twine& c);
	virtual void SetName(const char* c);
	virtual void GiveItem();
	virtual void RemoveItem();
	virtual void UseItem();




};

#endif
