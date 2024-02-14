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


Twine Room::DescribeRoom() {
	return this->description;

}

Twine Room::InspectRoom(Twine& t) {

	for (int i = 0; i < this->descLength; i++) {

		if (t.TFindOnly(this->keyWords[i]))
		{
			std::cout << this->extraDescriptions[i] << '\n';
			return this->extraDescriptions[i];
		}

	}

}