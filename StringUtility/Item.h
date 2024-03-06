#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "Twine.h"
#include <iostream>


class Item {
public:



	Item() = default;
	virtual ~Item() = default;

	virtual Twine Name();

	virtual Twine Description();

	virtual Twine Use();


};

#endif
