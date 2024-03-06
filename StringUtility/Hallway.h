#pragma once
#include "Room.h"
#include "Butler.h"
class Hallway : public Room {
public:
	Hallway() {
		mapChar = "H";
		name = "Hallway";
		ASCII =
" =============================\n\
 |                            |\n\
 ||                          ||\n\
 ||                          ||\n\
 |9          }o{             p|\n\
 ||       ____u______        ||\n\
 ||       |         |        ||\n\
 ||-------|---------|--------||\n";
description = "This is the library.\n\n\
Atop a small table rests a small candle, it's smoke puffing in the air.\n\n\
The bookshelves to the left are packed full. A ghostly old man places books back on the shelves.\n";
		extraDescriptions = new Twine[3]{
			"Books on the table are old, dusty, and clearly well read. Although many are just strewn about.",
			"The shelves are overflowing. Clearly none of the books are being taken off anymore.",
			"The ghost doesn't respond, his blue glow lighting up the room.",
		};

		keyWords = new Twine[3]{
			"book",
			"shelves",
			"ghost",
		};
		delete[] this->roomEntities;

		Entity* John = new Butler(Twine("Goffry"), Twine("A short, stocky man with a big forehead looks you up and down.\nHe has no hands."), Twine("Please sir... kill Mr. Gorilla Gorillatonne, take my gun.\nI can't get it out of the holster."), Twine("The butler is dead, a gun sits in his pocket."), 1, true, 4);



		this->roomEntities = new Entity * [1] {
			John,
			};

		this->entityNum = 1;
		descLength = 3;

	}

	~Hallway() {
	}




};