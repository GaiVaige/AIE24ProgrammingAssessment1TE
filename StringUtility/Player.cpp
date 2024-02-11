#include "Player.h"
#include "Item.h"
#include "Twine.h"
#include <iostream>




Player::Player() {
	playerInventory = new Item*[0];
}

Player::~Player() {
	delete[] playerInventory;
	delete[] validItemCommands;
}

void Player::CheckForValidCommand(Twine& searchT) {

	for (int i = 0; i < 5; i++) {

		if (searchT.ToLower().TFindOnly(validItemCommands[i].ToLower().TStr())) {
			SearchItem(searchT);
			return;
		}

	}
	Twine invalidCommandTwine = "I don't understand that command...";
	invalidCommandTwine.DisplayTwine();
	return;


}

void Player::AddItem(Item& c) {
	numberOfItems++;
	c.GiveItem();
	Item** tempArr = new Item*[numberOfItems];

	for (int i = 0; i < numberOfItems - 1; i++) {
			tempArr[i] = this->playerInventory[i];


	}
	tempArr[numberOfItems - 1] = &c;
	delete[] playerInventory;
	playerInventory = new Item*[numberOfItems];

	for (int i = 0; i < numberOfItems; i++) {
		this->playerInventory[i] = tempArr[i];
	}


	delete[] tempArr;
	
}

void Player::RemoveItem(Item& it) {

}

void Player::RefactorInventory(int newSize) {

}

void Player::SearchItem(Twine& searchT) {

	

	for (int i = 0; i < this->numberOfItems; i++) {
		if (searchT.TFind(playerInventory[i]->name.ToLower().TStr()) != -1) {
			playerInventory[i]->UseItem();
			return;
		}


	}
	Twine itemFailedTwine = "I don't think I have that in my pouch...";
	itemFailedTwine.Twine::DisplayTwine();
	return; 
}

