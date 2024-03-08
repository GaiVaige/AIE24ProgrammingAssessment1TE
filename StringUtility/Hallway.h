#pragma once
#include "Room.h"

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


	}

	~Hallway() {
	}




};