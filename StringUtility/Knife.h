#pragma once
#include "Item.h"



class Knife : public Item {

private:
	Twine name = "Knife";
	bool hasItem = false;
	int itemSlot = 2;



public:
	Game* g;

	Knife() {
		g = nullptr;
	}

	Twine Name() override {
		return "Knife";
	}

	Twine Description() override {
		return "A somewhat bloody knife. The metal is pretty thick.";
	}


	Twine Use() override {
		Twine knife = "You brandish the knife.\n";
		if (g->p->currentRoom->name == "Library") {
			knife.Append(" You cut open the books in a frenzy, you find a key!\n");
			return knife;
		}
		else {
			return knife;
		}

	}






};