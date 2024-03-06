#pragma once
#include "Item.h"


class Painting : public Item {

public:
	Twine Name() override {

		return "Painting";

	}

	Twine Description() override {

		return "A strange, muddy painting sits on the wall.\nYou can't quite make it out.";

	}

	Twine Use() override {

		return "You look into the painting, and it almost seems that the people in are\n staring back...";
	}



};