#pragma once
#ifndef LIB_HEADER
#define LIB_HEADER
#include "Room.h"
#include "Twine.h"




class Library : public Room {

public:

	Library() {
		Name();
		Description();
		ExtraDescriptions();
		extraDescriptions[0] = "Gun! Bang! Dead!";
		extraDescriptions[1] = "Oh lol this is just smut...";
		extraDescriptions[2] = "The fuck is a pizza oven doing in this thing";
		extraDescriptions[3] = "WHY IS THERE A GODDAMN GORILLA IN HERE";
		extraDescriptions[4] = "Do you really want to open the fridge?";

		KeyWords();
		keyWords[0] = "gun";
		keyWords[1] = "book";
		keyWords[2] = "pizza";
		keyWords[3] = "gorilla";
		keyWords[4] = "fridge";
		DescLength();
	}

	~Library() {
	}



	Twine Name() override {
		this->name = "Library";
		return this->name;
	}
	Twine Description() override {
		this->description = "This is a library. There are books and stuff.";
		return this->description;
	}
	Twine* ExtraDescriptions() override {
		extraDescriptions = new Twine[5];
		return this->extraDescriptions;
	}
	Twine* KeyWords() override {
		keyWords = new Twine[5]{};
		return this->keyWords;
	}
	int DescLength() override {
		this->descLength = 5;
		return this->descLength;
	}
	Twine ValidInspectCommands() override {
		return this->validInspectCommands;
	}
	Twine ValidInspectPrompts() override {
		return this->validInspectPrompts;
	}









};



#endif // !LIB_HEADER
