#pragma once
#include "Room.h"

class Piano : public Room {


public:
	Piano() {
		mapChar = "P";
		name = "Piano";
		ASCII =
" =============================\n\
                               \n\
                   §           \n\
              §                \n\
                 §             \n\
      _---------               \n\
     ===========               \n\
 ----|--L-Ll---|---------------\n";
		description = "This is the Piano room.\n\n\
A piano is playing itself in the centre, an eerie glow dances across the keys.\n";
		extraDescriptions = new Twine[2]{
			"A piano, chords are playing without anyone sitting there... \7",
			"Ah... Aria of the Soul...",
		};

		keyWords = new Twine[2]{
			"piano",
			"song",

		};
		descLength = 2;

	}

	~Piano() {
	}



};