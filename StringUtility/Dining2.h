#pragma once
#include "Room.h"

class Dining2 : public Room {

public:
	Dining2() {
		mapChar = "d";
		ASCII =
" =============================\n\
      |                        \n\
    _[0]_                      \n\
     / \\                       \n\
                               \n\
 ___u_____u_____u____          \n\
                    |          \n\
 ___________________|__________\n";
		name = "Foot of the Dining Room";
		description = "No chairs sit in the half of the dining room, simply a chandelier hanging over a long, long table.\nThe room stinks, as if whoever eats in here is almost beastly.";
		keyWords = new Twine[3]{
			"chandelier",
			"table",
			"stench",
		};
		extraDescriptions = new Twine[3]{
			"The chandelier's bulbs are all but burnt out. It clearly isn't needed.",
			"The table is sratched, with foot and hand prints all over it, indenting into the wood.",
			"Smells like a zoo in here...",
		};
		descLength = 3;

	}

	~Dining2() {
	}



};