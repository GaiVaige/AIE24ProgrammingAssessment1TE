#pragma once
#include "Room.h"

class Dining1 : public Room {
	
public:
	Dining1() {
		mapChar = "D";
		ASCII =
" =============================\n\
                               \n\
                               \n\
                               \n\
    I0                         \n\
    |      ___u_____u_____u____\n\
    |____  |                   \n\
 ___|___|__|___________________\n";
		name = "Head of the Dining Room";
		description = "Ooooooooooo spooky. Gorilla?";
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

	~Dining1() {
	}

	

};