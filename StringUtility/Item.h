#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "Twine.h"
#include <iostream>


class Item {
public:
	Twine name;
	Twine description;
	int itemSlot = 0;

	Item();
	~Item();
	virtual void SetName(Twine& c);
	virtual void SetName(const char* c);
	virtual void UseItem();




};

#endif
