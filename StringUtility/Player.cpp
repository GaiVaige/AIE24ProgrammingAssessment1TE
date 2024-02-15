#include "Player.h"
#include "Item.h"
#include "Twine.h"
#include "Room.h"
#include <iostream>




Player::Player() {
	playerInventory = new Item*[0];
}

Player::~Player() {
	delete[] playerInventory;
}

void Player::CheckForValidCommand(Twine& searchT) {
	int moveCheck = 0;
	for (int i = 0; i < 3; i++) {

		if (searchT.ToLower().TFindOnly(validItemCommands[i].ToLower().TStr())) {
			SearchItem(searchT);
			return;
		}

	}

	for (int i = 0; i < 5; i++) {

		if (searchT.ToLower().TFindOnly(validRoomCommands[i].ToLower().TStr())) {
			currentRoom->InspectRoom(searchT).DisplayTwine();
			return;
		}

	}

	for (int i = 0; i < 5; i++) {
		if (searchT.ToLower().TFindOnly(validMoveCommands[i].ToLower().TStr())) {

			for (int y = 0; y < 4; y++) {
				if (searchT.ToLower().TFindOnly(Directions[y].ToLower().TStr())) {
					MovePlayer(y);
					moveCheck++;
				}
			}

		}

	}
	if (moveCheck != 0) {
		return;
	}

	Twine invalidCommandTwine = "I don't understand that command...";
	invalidCommandTwine.DisplayTwine();


}

void Player::AddItem(Item& c) {
	numberOfItems++;
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

void Player::SearchItem(Twine& searchT) {

	

	for (int i = 0; i < this->numberOfItems; i++) {
		if (searchT.TFind(playerInventory[i]->name.ToLower().TStr()) != -1) {
			playerInventory[i]->UseItem();
			return;
		}


	}
	Twine itemFailedTwine = "I don't think I have that in my pouch...";
	itemFailedTwine.DisplayTwine();
}

void Player::MovePlayer(int i) {
	switch (i)
	{
	default:
		break;
	case 0:
		if (yCord < 2) {
			yCord++;
		}
		break;

	case 1:
		if (xCord < 2) {
			xCord++;
		}
		break;
	case 2:
		if (yCord > 0) {
			yCord--;
		}
		break;
	case 3:
		if (yCord > 0) {
			xCord--;
		}
		break;
	}

}


