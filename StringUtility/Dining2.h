#pragma once
#include "Room.h"

class Dining2 : public Room {

public:
	Dining2() {
		mapChar = "D";
		ASCII =
" =============================\n\
                           |   \n\
                           |   \n\
         DINING2        ___|_  \n\
                       |     | \n\
 ____~o6____           |    9| \n\
 |   [|]   |           |  % &| \n\
 |__[|][|]_|______~o6__|__%&_|_\n";
		name = "Foot of the Dining Room";
		description = "Ooooooooooo spooky. Monkey?";
		keyWords = new Twine[3]{
			"gorilla",
			"shrine",
			"lanterns",
		};
		extraDescriptions = new Twine[3]{
			"Ooga booga ah ah ah",
			"A dark shrine, ooooo...",
			"Damn this gorilla got good lighting",
		};
		descLength = 3;

	}

	~Dining2() {
	}



};