#pragma once
#include "Item.h"
#include <string>

class BoxODons : public Item {

private:
	int numOfDons = 5;

public:

	Twine Name() override {

		return "Box of Donuts";
	}

	Twine Description() override {
		return "\nThere is a delicious box of donuts from Runners' on the counter.";
	}

	Twine Use() override {

		if (this->numOfDons != 0) {
			Twine t = "You eat a donut, there are ";
			char b = (char)(numOfDons + 48);
			t.Append(b);
			t.Append(" donuts left.");
			this - numOfDons--;
			return t;
		}
		else {
			return Twine("There's none left...");
		}


	}

};