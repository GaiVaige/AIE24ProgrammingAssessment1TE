#include "Room.h"
class Player;

Room::Room() {

}

Room::~Room() {
	delete roomItem;
}


void Room::DescribeRoom() {
	std::cout << ASCII << '\n';

	if (doDesc) {
		std::cout << this->description << '\n';
	}
	else {
		std::cout << "You are in the " << this->name << "." << '\n';
	}
	this->doDesc = false;
}

Twine Room::InspectRoom(Twine& t) {

	for (int i = 0; i < this->descLength; i++) {

		if (t.ToLower().FindExclusive(this->keyWords[i].ToLower()))
		{
			return this->extraDescriptions[i];
		}

	}

	for (int i = 0; i < this->entityNum; i++) {
		if (t.ToLower().FindExclusive(this->roomEntities[i]->name.ToLower())) {
			return this->roomEntities[i]->description;
		}
	}
	
	Twine failedTwine = "There's nothing like that in here...";
	return failedTwine;
}

void Room::CheckForDialogue(Twine& t, Player* p) {
	for (int i = 0; i < this->entityNum; i++) {
		if (t.ToLower().FindExclusive(this->roomEntities[i]->name.ToLower())) {
			roomEntities[i]->Interact(p);
			return;
		}
	}

	Twine fail = "Doesn't seem to want to talk...";
	fail.DisplayTwine();
}

Entity* Room::CheckEntityNames(Twine& searchT) {
	for (int i = 0; i < entityNum; i++) {
		if (searchT.ToLower().FindExclusive(roomEntities[i]->name.ToLower().TStr())) {
			return roomEntities[i];
		}
	}
	return nullptr;
}