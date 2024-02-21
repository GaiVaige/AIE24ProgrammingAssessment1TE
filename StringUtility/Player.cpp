#include "Player.h"
#include "Item.h"
#include "Twine.h"
#include "Room.h"
#include "Stats.h"
#include "random"
#include <iostream>




Player::Player() {
	playerInventory = new Item*[0];
	spells = new Spell*[0];
	spellCount = 0;
}

Player::~Player() {
	delete[] playerInventory;
	delete[] spells;
	delete currentRoom;
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

		if (searchT.ToLower().TFindOnly(validSpellCommands[i].ToLower().TStr())) {
			this->SpellLookUp(searchT);
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
		if (searchT.ToLower().TFind(playerInventory[i]->name.ToLower().TStr()) != -1) {
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
		if (yCord < 4) {
			yCord++;
		}
		break;

	case 1:
		if (xCord < 4) {
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

void Player::SpellLookUp(Twine searchT) {
	for (int i = 0; i < this->spellCount; i++) {

		if (searchT.ToLower().TFindOnly((spells[i]->name.ToLower().TStr()))) {
			std::cout << "Name: " << spells[i]->name << '\n';
			std::cout << "Description: " << spells[i]->description << '\n';
			return;
		}
	}
	std::cout << "I don't know that spell..." << '\n';
	return;
}

void Player::LearnSpell(Spell* sp) {
	for (int i = 0; i < this->spellCount; i++) {
		if (sp->Compare(*sp, *spells[i])) {
			std::cout << "I already know this spell!" << '\n';
		}
	}
	spellBook.Add(sp->name);
	this->spellCount++;
	Spell** tempArr = new Spell * [spellCount];
	for (int i = 0; i < spellCount - 1; i++) {
		tempArr[i] = this->spells[i];
	}

	tempArr[spellCount - 1] = sp;
	delete[] spells;
	spells = new Spell * [spellCount];

	for (int i = 0; i < spellCount; i++) {
		this->spells[i] = tempArr[i];
	}


	delete[] tempArr;

}

void Player::CastSpell(Twine searchT) {
	std::cout << "You shouldnt be here" << '\n';
}

void Player::InitPlayer() {
	std::cout << "Ah... yes. You're awake. Tell me...\nWhat is your name: ";
	std::cin >> this->name;

	Twine checkTwine = "";
	int checkInt = 0;
	std::cout << "Well... how has your experience in life been?\nAre you " << Twine("Social").Colour(0, 0, 255, true) << ", " << Twine("Strong").Colour(255, 0, 0, true) << ", or " << Twine("Smart").Colour(0, 255, 0, true) << "?\n";


	while (true) {
		checkTwine.GetTwine();
		if (checkTwine.ToLower() == Twine("Strong").ToLower()) {
			checkInt = 1;
			break;
		}
		else if (checkTwine.ToLower() == Twine("Social").ToLower()) {
			checkInt = 2;
			break;
		}
		else if (checkTwine.ToLower() == Twine("Smart").ToLower()) {
			checkInt = 3;
			break;
		}
		else {
			std::cout << "That... is not what I expected. I do not understand. Please, speak again.\n";
		}
	}

	switch (checkInt) {
	default:
		std::cout << "THIS SHOULDNT HAPPENT";
	case 1:
		s.InitStats(16, 12, 14, 8, 10, 8);
		break;
	case 2:
		s.InitStats(8, 12, 8, 16, 14, 10);
		break;
	case 3:
		s.InitStats(8, 8, 12, 10, 14, 16);
		break;

	}

	this->health = s.Constitution;

	std::cout << "Wonderful... now... open your eyes...\n";

	checkTwine = "";
	while (true) {
		checkTwine.GetTwine();

		if (checkTwine.ToLower().TFind("open") != -1){
			break;
		}
		else {
			std::cout << "I said, " << Twine("OPEN").Colour(100, 100, 100) << " your eyes." << '\n';
		}
	}

}

