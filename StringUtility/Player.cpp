#include "Player.h"
#include "Item.h"
#include "Twine.h"
#include "Room.h"
#include "Stats.h"
#include "Roll.h"
#include "random"
#include <iostream>


Player::Player() {
	playerInventory = new Item*[0];
	spells = new Spell*[0];
	spellCount = 0;
	for (int i = 0; i < 10; i++) {
		flags[i] = false;
	}
	InitPlayer();
}

Player::~Player() {
	delete[] playerInventory;
	delete[] spells;
}

void Player::CheckForValidCommand(Twine& searchT) {
	int moveCheck = 0;
	for (int i = 0; i < 3; i++) {

		if (searchT.ToLower().TFindOnly(validItemCommands[i].ToLower().TStr())) {
			SearchItem(searchT).DisplayTwine();
			return;
		}

	}

	for (int i = 0; i < 5; i++) {

		if (searchT.ToLower().TFindOnly(validRoomCommands[i].ToLower().TStr())) {
			currentRoom->InspectRoom(searchT).DisplayTwine();
			return;
		}

	}
	for (int i = 0; i < 4; i++) {
		if (searchT.ToLower().TFindOnly(validDialougeCommands[i].ToLower())) {
			currentRoom->CheckForDialogue(searchT, this);
			return;
		}
	}

	for (int i = 0; i < 5; i++) {

		if (searchT.ToLower().TFindOnly(validCombatCommands[i].ToLower().TStr())) {
			
			switch (i) {
			case 0:
				CastSpell(searchT);
				break;
			case 1:
				CastSpell(searchT);
				break;
			case 2:
				this->SpellLookUp(searchT);
				break;
			case 3:
				this->SpellLookUp(searchT);
				break;
			case 4:
				this->Attack(searchT);
				break;

			}

			return;
		}

	}

	for (int i = 0; i < 3; i++) {

		if (searchT.ToLower().TFindOnly(validUtilityCommands[i].ToLower().TStr())) {

			switch (i) {
			case 0:
				CommandOutput();
				break;
			case 1:
				PlayerStats();
				displaceVal = 2;
				break;
			case 2:
				FullSpellList();
				displaceVal = spellCount + 1;
				break;

			}

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

Twine Player::SearchItem(Twine& searchT) {

	

	for (int i = 0; i < this->numberOfItems; i++) {
		if (searchT.ToLower().TFind(playerInventory[i]->Name().ToLower().TStr()) != -1) {
			return playerInventory[i]->Use();
		}


	}
	Twine itemFailedTwine = "I don't think I have that in my pouch...";
	return itemFailedTwine;
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
		if (xCord > 0) {
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
		if (sp->SpellEqualTo(*sp, *spells[i])) {
			std::cout << "I already know this spell!" << '\n';
		}
	}
	spellBook.Add(sp->name);
	this->spellCount++;
	Spell** tempArr = new Spell*[spellCount];
	for (int i = 0; i < spellCount - 1; i++) {
		tempArr[i] = this->spells[i];
	}

	tempArr[spellCount - 1] = sp;
	delete[] spells;
	spells = new Spell*[spellCount];

	for (int i = 0; i < spellCount; i++) {
		this->spells[i] = tempArr[i];
	}


	delete[] tempArr;

}

void Player::FullSpellList() {

	std::cout << Twine("I currently know: ") << '\n';

	for (int i = 0; i < spellCount; i++) {
		Twine t = spells[i]->name;
		std::cout << "\t" << t.Colour(255,0,255,true) << '\n';
	}
}

void Player::CastSpell(Twine searchT) {
	for (int i = 0; i < this->spellCount; i++) {

		if (searchT.ToLower().TFindOnly((spells[i]->name.ToLower().TStr()))) {
			if (spells[i]->hasTarget) {
				Entity* e = currentRoom->CheckEntityNames(searchT);
				if (e != nullptr) {
					spells[i]->Cast(e);
					return;
				}
				else {
					std::cout << "Not a valid target!" << '\n';
					return;
				}
			}
			else {
				spells[i]->Cast();
				return;
			}


		}
	}
	std::cout << "Not here..." << '\n';
	return;
}

void Player::InitPlayer() {


	std::cout << "Ah... yes. You're coming to. Tell me...\nWhat is your name: ";
	std::cin >> this->name;
	this->name = name.Capital();

	Twine checkTwine = "";
	int checkInt = 0;
	std::cout << "Well... how has your experience in life been?\nAre you " << Twine("Social").Colour(0, 0, 255, true) << ", " << Twine("Strong").Colour(255, 0, 0, true) << ", or " << Twine("Smart").Colour(0, 255, 0, true) << "?\n";


	while (true) {
		checkTwine.GetTwine();
		if (checkTwine.ToLower().TFind(Twine("Strong").ToLower()) != -1) {
			checkInt = 1;
			break;
		}
		else if (checkTwine.ToLower().TFind(Twine("Social").ToLower()) != -1) {
			checkInt = 2;
			break;
		}
		else if (checkTwine.ToLower().TFind(Twine("Smart").ToLower()) != -1) {
			checkInt = 3;
			break;
		}
		else if (checkTwine.ToLower().TFind(Twine("None").ToLower()) != -1) {
			checkInt = 4;
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
	case 4:
		s.InitStats(4, 4, 4, 4, 4, 4);
		std::cout << Twine("Oh my... well, if you truly are that pitiable...\n");

	}

	this->health = s.Constitution;

	std::cout << "Now... open your eyes...\n";

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

void Player::PlayerStats() {

	std::cout << Twine("\tStr: ").Colour(255, 0, 0) << s.Strength;
	std::cout << Twine("\tDex: ").Colour(0, 255, 255) << s.Dexterity;
	std::cout << Twine("\tCon: ").Colour(255, 255, 0) << s.Constitution << '\n';
	std::cout << Twine("\tInt: ").Colour(0, 0, 255) << s.Intelligence;
	std::cout << Twine("\tWis: ").Colour(0, 255, 0) << s.Wisdom;
	std::cout << Twine("\tCha: ").Colour(255, 0, 255) << s.Charisma;


}

void Player::SpellSort() {
	bool swapped = false;

	for (int i = 0; i < spellCount - 1; i++) {
		swapped = false;

		for (int y = 0; y < spellCount - i - 1; y++) {
			if (Spell::Compare(*spells[y], *spells[y + 1])) {
				std::swap(this->spells[y], this->spells[y + 1]);
				swapped = true;
			}
		}

		if (swapped == false) {
			break;
		}

	}


}

void Player::CommandOutput() {

	std::cout << "Utility commands:\n";
	for (int i = 0; i < 3; i++) {
		validDialougeCommands[i].DisplayTwine();
	}
	std::cout << '\n';
	std::cout << "Item commands:\n";
	for (int i = 0; i < 3; i++) {
		validItemCommands[i].DisplayTwine();
	}
	std::cout << '\n';
	std::cout << "Room commands:\n";
	for (int i = 0; i < 5; i++) {
		validRoomCommands[i].DisplayTwine();
	}
	std::cout << '\n';
	std::cout << "Move commands:\n";
	for (int i = 0; i < 5; i++) {
		validMoveCommands[i].DisplayTwine();
	}
	std::cout << '\n';
	std::cout << "Combat commands:\n";
	for (int i = 0; i < 4; i++) {
		validCombatCommands[i].DisplayTwine();
	}
	std::cout << '\n';
	std::cout << "Dialogue commands:\n";
	for (int i = 0; i < 4; i++) {
		validDialougeCommands[i].DisplayTwine();
	}
	std::cout << '\n';

	displaceVal = 37;
}

void Player::Attack(Twine searchT) {
	Entity* e = currentRoom->CheckEntityNames(searchT);
	if (e != nullptr) {
		bool crit = false;;
		int roll = Roll::RollDice(1, 20);
		if (roll == 20) {
			crit = true;
			std::cout << Twine("CRITICAL HIT!! ");
		}

		roll += ((this->s.Strength - 10) / 2);
		std::cout << Twine("Rolled ") << roll << "! ";
		if (!crit) {
			roll -= e->ac;
		}

		if (roll > -1){
			if (e->alive) {
				ApplyDam(e, crit);
				
				if (e->hp <= 0) {
					e->hp = 0;
					e->alive = false;
					std::cout << e->name << " has been defeated!" << '\n';
				}
			}
			else {
				std::cout << e->deadDesc << '\n';
			}
		}
		return;
	}
	else {
		std::cout << "Not a valid target!" << '\n';
		return;
	}
}
void Player::ApplyDam(Entity* e, bool crit) {

	if (crit) {
		std::cout << Twine("That's a hit! Dealt ") << (5 + ((this->s.Strength - 10))) << " damage!" << '\n';
		e->hp -= 5 + ((this->s.Strength - 10));
		return;
	}
	else {
		std::cout << Twine("That's a hit! Dealt ") << (5 + ((this->s.Strength - 10) / 2)) << " damage!" << '\n';
		e->hp -= 5 + ((this->s.Strength - 10) / 2);
		return;
	}


}


