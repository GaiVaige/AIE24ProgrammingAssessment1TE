#pragma once
#ifndef LIB_HEADER
#define LIB_HEADER
#include "Room.h"
#include "Twine.h"
#include "Entity.h"




class Library : public Room {

public:
	Library() {
		mapChar = "L";
		name = "Library";
		description = "This is a library, there are books and stuff.";
		extraDescriptions = new Twine[5]{
			"Gun! Bang! Dead!",
			"Oh lol this is just smut...",
			"The fuck is a pizza oven doing in this thing",
			"WHY IS THERE A GODDAMN GORILLA IN HERE",
			"Do you really want to open the fridge?",
		};

		keyWords = new Twine[5]{
			"gun",
			"book",
			"pizza",
			"gorilla",
			"fridge",

		};
		delete[] this->roomEntities;
		this->roomEntities = new Entity*[1];
		this->entityNum = 1;
		descLength = 5;
		Entity* Ee = new Entity(Twine("John"), Twine("This is a guy named John"), 20);
		Ee->Dialogue = new Twine("I AM SO FUCKING DUMB AHHHHHHHHHH");
		roomEntities[0] = Ee;

	}

	~Library() {
	}










};



#endif // !LIB_HEADER
