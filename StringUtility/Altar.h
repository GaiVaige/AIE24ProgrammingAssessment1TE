#pragma once
#include "Room.h"

class Altar : public Room {
	
public:
	Altar() {
		name = "Altar";
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

	~Altar() {
	}

	

};