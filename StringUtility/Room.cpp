#include "Room.h"


Twine Room::Name() {
	return this->name;
}
Twine Room::Description() {
	return this->description;
}
Twine* Room::ExtraDescriptions() {
	return this->extraDescriptions;
}
Twine* Room::KeyWords() {
	return this->keyWords;
}
int Room::DescLength() {
	return this->descLength;
}
Twine Room::ValidInspectCommands() {
	return this->validInspectCommands;
}
Twine Room::ValidInspectPrompts() {
	return this->validInspectPrompts;
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

		if (t.TFindOnly(this->keyWords[i]))
		{
			return this->extraDescriptions[i];
		}

	}
	
	Twine failedTwine = "There's nothing like that in here...";
	return failedTwine;
}