#include "Room.h"


Room::Room() {

}

Room::~Room() {

}


void Room::DescribeRoom() {
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

		if (t.ToLower().TFindOnly(this->keyWords[i].ToLower()))
		{
			return this->extraDescriptions[i];
		}

	}

	for (int i = 0; i < this->entityNum; i++) {
		if (t.ToLower().TFindOnly(this->roomEntities[i]->name.ToLower())) {
			return this->roomEntities[i]->description;
		}
	}
	
	Twine failedTwine = "There's nothing like that in here...";
	return failedTwine;
}

Twine Room::CheckForDialogue(Twine& t) {
	for (int i = 0; i < this->entityNum; i++) {
		if (t.ToLower().TFindOnly(this->roomEntities[i]->name.ToLower())) {
			if (this->roomEntities[i]->Dialogue != nullptr) {
				return *this->roomEntities[i]->Dialogue;
			}
		}
	}

	Twine fail = "Doesn't seem to want to talk...";
	return fail;
}

Entity* Room::CheckEntityNames(Twine& searchT) {
	for (int i = 0; i < entityNum; i++) {
		if (searchT.ToLower().TFindOnly(roomEntities[i]->name.ToLower())) {
			return roomEntities[i];
		}
	}
	return nullptr;
}