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

		Entity* John = new Entity(Twine("John"), Twine("A guy named John."), Twine("Hi! I'm John!"), Twine("You killed John! You monster!"), 4, true, 0);
		Entity* Jack = new Entity(Twine("Jack"), Twine("A guy named Jack."), Twine("Fuck you! I'm Jack!"), Twine("You killed Jack! You monster!"), 2, false, 0);



		this->roomEntities = new Entity*[2] {
			John,
				Jack,
			};

		this->entityNum = 2;
		descLength = 5;
	
	}

	~Library() {
	}










};



#endif // !LIB_HEADER
