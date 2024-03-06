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
		ASCII = 
" =============================\n\
               >>0<<           \n\
 __________________     <>%    \n\
 I[[[[[[[[[[[[[[[[I     %<>    \n\
 I[[[[[[[[[[[[[[[[I      |     \n\
 I[[[[[[[[[[[[[[[[I    __O___  \n\
 I[[[[[[[[[[[[[[[[I     |  |   \n\
 ------------------------------\n";
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

		Entity* John = new Entity(Twine("Ghost"), Twine("A sickly, transparent old man hovers before you. He murmurs as he places books back on the shelves."), Twine("Oh! You must be here for the master... he rests at the moment.\nGoffry, the butler, may be able to help you."), Twine("Why would you hit me, you know that won't work!"), -9, false, 50);



		this->roomEntities = new Entity * [1] {
			John,
			};

		this->entityNum = 1;
		descLength = 3;


	}

	~Library() {
	}

};



#endif // !LIB_HEADER
