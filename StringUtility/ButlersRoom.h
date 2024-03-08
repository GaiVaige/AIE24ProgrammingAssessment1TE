#pragma once
#include "Room.h"
#include "Butler.h"


class ButlersRoom : public Room {

public:
	ButlersRoom() {

		mapChar = "B";
		name = "Butler's Room";
		ASCII =
			" =============================\n\
 |   ______                   |\n\
 || [_|__|_]                  |\n\
 ||   J  J                    |\n\
 |9                           |\n\
 ||                           |\n\
 ||             __________---_|\n\
 ||-------------|------------||\n";
		description = "This is the butler's room.\n\n\
There is an old, musty bed, the Butler seems to be sitting at its foot.\n\n\
There is a hanging rack with two empty hooks attached.\n";
		keyWords = new Twine[3]{
			"bed",
			"butler",
			"hanger",
		};
		extraDescriptions = new Twine[3]{
	"The bed is made, but mostly dusty. As if it hardly slept in.",
	"The Butler looks exhausted, he is missing his hands.",
	"The hanger is covered in layers of dust. It clearly has never been used. Someone doesn't take breaks...",
		};




		delete[] this->roomEntities;
		entityNum = 1;
		Entity* John = new Butler(Twine("Butler"), Twine("A short, stocky man with a big forehead looks you up and down.\nHe has no hands."), Twine("Please sir... kill Mr. Gorilla Gorillatonne, take my gun.\nI can't get it out of the holster."), Twine("The butler is dead, a gun sits in his pocket."), 1, true, 0);



		this->roomEntities = new Entity * [1] {
			John,
		};
	}

	~ButlersRoom() {
	}


};