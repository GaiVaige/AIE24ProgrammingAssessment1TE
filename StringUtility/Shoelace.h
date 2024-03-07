#pragma once
#include "Item.h"

class Shoelace : public Item {
public:
	Twine Name() override {

		return "Shoelace";

	}

	Twine Description() override {

		return "There is a single shoe lace covered in mud on the floor.";

	}

	Twine Use() override {

		return "The shoelace... it...\n\nDid it just move?\n";
	}


};