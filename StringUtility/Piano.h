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
		description = "This is the library.\n\n\
Atop a small table rests a small candle, it's smoke puffing in the air.\n\n\
The bookshelves to the left are packed full.\n";
		extraDescriptions = new Twine[5]{
			"A piano, chords are playing without anyone sitting there... \7",
			"Oh lol this is just smut...",
			"The fuck is a pizza oven doing in this thing",
			"WHY IS THERE A GODDAMN GORILLA IN HERE",
			"Do you really want to open the fridge?",
		};

		keyWords = new Twine[5]{
			"piano",
			"book",
			"pizza",
			"gorilla",
			"fridge",

		};
		descLength = 5;

	}

	~Piano() {
	}



};