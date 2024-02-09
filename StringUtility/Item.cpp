#include "Twine.h"
#include <iostream>
#include "Item.h"
#include "Player.h"


	Item::Item() {
	}

	Item::~Item() {
	}

	void Item::SetName(Twine& c) {
		name.SetTwine(c);
	}
	void Item::SetName(const char* c) {
		name.SetTwine(c);
	}
	void Item::GiveItem() {
		hasItem = true;
	}
	void Item::RemoveItem() {
		hasItem = false;
	}

	void Item::UseItem() {
		std::cout << this->name << '\n';
	}
