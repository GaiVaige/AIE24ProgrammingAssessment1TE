#pragma once
#ifndef KITCH_HEADER
#define KITCH_HEADER
#include "Room.h"
#include "Twine.h"




class Kitchen : public Room {

public:
	
	Kitchen() {
		Name();
		Description();
		ExtraDescriptions();
		extraDescriptions[0] = "The knife is dirty, stabbed into the chopping board. It seems rusty, not the safest to touch.";
		extraDescriptions[1] = "The cabinets are filled with old, mouldy vegetables. Not the most pleasant smell... though there is a small stone in the back.";
		extraDescriptions[2] = "The cabinets are filled with old, mouldy vegetables. Not the most pleasant smell... though there is a small stone in the back.";
		extraDescriptions[3] = "The sink is covered in old gunk, blood... well, you hope it's just blood.";
		extraDescriptions[4] = "Do you really want to open the fridge?";

		keyWords = new Twine[5]{

		};
		keyWords[0] = "knife";
		keyWords[1] = "cabinet";
		keyWords[2] = "cabinets";
		keyWords[3] = "sink";
		keyWords[4] = "fridge";
		DescLength();
	}

	~Kitchen() {
	}



	Twine Name() override{
		this->name = "Kitchen";
		return this->name;
	}
	Twine Description() override {
		this->description = "Well, this is strange. This kitchen is covered from head to toe in disgusting, old blood... though evidence of prepared food remains on its counters. People seem to only care about bloodshed, when it's their blood, in their shed...";
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



#endif // !KITCH_HEADER
