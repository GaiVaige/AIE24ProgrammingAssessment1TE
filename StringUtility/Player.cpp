#include "Player.h"
#include "Item.h"
#include "Twine.h"
#include "Room.h"
#include "Stats.h"
#include "Roll.h"
#include "random"
#include <iostream>
#include "Windows.h"


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

		if (searchT.ToLower().FindExclusive(validItemCommands[i].ToLower().TStr())) {
			SearchItem(searchT).DisplayTwine();
			displaceVal = 2;
			return;
		}

	}

	for (int i = 0; i < 5; i++) {

		if (searchT.ToLower().FindExclusive(validRoomCommands[i].ToLower().TStr())) {
			currentRoom->InspectRoom(searchT).DisplayTwine();
			displaceVal = 2;
			return;
		}

	}
	for (int i = 0; i < 4; i++) {
		if (searchT.ToLower().FindExclusive(validDialougeCommands[i].ToLower().TStr())) {
			currentRoom->CheckForDialogue(searchT, this);
			displaceVal = 2;
			return;
		}
	}

	for (int i = 0; i < 4; i++) {

		if (searchT.ToLower().FindExclusive(validCombatCommands[i].ToLower().TStr())) {
			
			switch (i) {
			case 0:
				CastSpell(searchT);
				break;
			case 1:
				this->SpellLookUp(searchT);
				displaceVal = 1;
				break;
			case 2:
				this->SpellLookUp(searchT);
				displaceVal = 1;
				break;
			case 3:
				this->Attack(searchT);
				break;

			}
			return;
		}

	}

	for (int i = 0; i < 4; i++) {

		if (searchT.ToLower().FindExclusive(validUtilityCommands[i].ToLower().TStr())) {

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
			case 3:
				Inventory();
				displaceVal = numberOfItems + 1;
				break;


			}

			return;
		}

	}


	for (int i = 0; i < 5; i++) {
		if (searchT.ToLower().FindExclusive(validMoveCommands[i].ToLower().TStr())) {

			for (int y = 0; y < 4; y++) {
				if (searchT.ToLower().FindExclusive(Directions[y].ToLower().TStr())) {
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
		if (searchT.ToLower().Find(playerInventory[i]->Name().ToLower().TStr()) != -1) {
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
	isMoving = true;
	CreateThread(NULL, NULL, [](LPVOID lpThreadParameter){
		Beep(100, 200);
		Beep(50, 200);
		Beep(100, 200);
		Beep(50, 200);
		return (DWORD)TRUE;
		
		}, NULL, NULL, NULL);

}

void Player::SpellLookUp(Twine searchT) {

	int search = spellCount/ 2;
	size_t highest = spellCount;
	size_t lowest = 0;
	searchT.Replace("search ", "");
	searchT.Replace("spell ", "");

	if (searchT[searchT.Length() - 1] == ' ') {
		for (int i = searchT.Length() - 1; searchT[i] == ' '; i--) {
			searchT.Erase(1, i);
		}
	}

	while (lowest != highest) {

				if (spells[search]->name.ToLower() < searchT.ToLower()) {

					lowest = search + 1;

				}
				else{
					highest = search;
				}
				search = lowest + ((highest - lowest) / 2);		
	}

	if (spells[search]->name.ToLower() == searchT.ToLower()) {
		std::cout << "Name: " << spells[search]->name << '\n';
		std::cout << "Description: " << spells[search]->description << '\n';
		return;
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

	std::cout << Twine("I currently know: ").TStr() << '\n';

	for (int i = 0; i < spellCount; i++) {
		Twine t = spells[i]->name;
		std::cout << "\t" << t.Colour(255,0,255,true) << '\n';
	}
}

void Player::Inventory() {

	std::cout << Twine("I have in my pockets: ").TStr() << '\n';

	for (int i = 0; i < numberOfItems; i++) {
		Twine t = playerInventory[i]->Name();
		std::cout << "\t" << t.Colour(0, 255, 255, true) << '\n';
	}
}

void Player::CastSpell(Twine searchT) {
	for (int i = 0; i < this->spellCount; i++) {

		if (searchT.ToLower().FindExclusive((spells[i]->name.ToLower().TStr()))) {
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
	this->name = name.Capital().TStr();

	Twine checkTwine = "";
	int checkInt = 0;
	std::cout << "Well... how has your experience in life been?\nAre you " << Twine("Social").Colour(0, 0, 255, true) << ", " << Twine("Strong").Colour(255, 0, 0, true) << ", or " << Twine("Smart").Colour(0, 255, 0, true) << "?\n";


	while (true) {
		checkTwine.GetTwine();
		if (checkTwine.ToLower().Find(Twine("Strong").ToLower().TStr()) != -1) {
			checkInt = 1;
			break;
		}
		else if (checkTwine.ToLower().Find(Twine("Social").ToLower().TStr()) != -1) {
			checkInt = 2;
			break;
		}
		else if (checkTwine.ToLower().Find(Twine("Smart").ToLower().TStr()) != -1) {
			checkInt = 3;
			break;
		}
		else if (checkTwine.ToLower().Find(Twine("None").ToLower().TStr()) != -1) {
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
		std::cout << Twine("Oh my... well, if you truly are that pitiable...\n").TStr();

	}

	this->health = s.Constitution;

	std::cout << "Now... open your eyes...\n";

	checkTwine = "";
	while (true) {
		checkTwine.GetTwine();

		if (checkTwine.ToLower().Find("open") != -1){
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
			std::cout << Twine("CRITICAL HIT!! ").TStr();
		}

		roll += ((this->s.Strength - 10) / 2);
		std::cout << Twine("Rolled ").TStr() << roll << "! ";
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
		std::cout << Twine("That's a hit! Dealt ").TStr() << (5 + ((this->s.Strength - 10))) << " damage!" << '\n';
		e->hp -= 5 + ((this->s.Strength - 10));
		return;
	}
	else {
		std::cout << Twine("That's a hit! Dealt ").TStr() << (5 + ((this->s.Strength - 10) / 2)) << " damage!" << '\n';
		e->hp -= 5 + ((this->s.Strength - 10) / 2);
		return;
	}


}


