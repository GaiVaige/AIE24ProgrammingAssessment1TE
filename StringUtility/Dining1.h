#pragma once
#include "Room.h"
#include "Gorilla.h"

class Dining1 : public Room {
	
public:
	Dining1() {
		mapChar = "D";
		ASCII =
" =============================\n\
               ________        \n\
              | o  mn  |       \n\
              |   \\o/  |       \n\
    I0        |________|       \n\
    |      ___u_____u_____u____\n\
    |____  |                   \n\
 ___|___|__|___________________\n";
		name = "Head of the Dining Room";
		description = "Old plates and dishes line the table. A painting of some clouds and birds sits on the wall.\nIt is clear that a meal was eaten here recently.\n\nA gorilla in a suit sits at the head of the table.\n";
		keyWords = new Twine[3]{
			"painting",
			"dishes",
			"chair",
		};
		extraDescriptions = new Twine[3]{
			"A mostly standard image of some birds in the sky.",
			"The dishes are entirely empty, as if picked clean.",
			"The chair is grimey, and covered in oil and blood. Who, or what, ate here must have been a slob.",
		};
		descLength = 3;

		delete[] roomEntities;
		entityNum = 1;

		Entity* G = new Gorilla("Gorilla", "A gorilla!", "OO OO AA AA", "NULL", 50, false, 100);
		G->hp += 500;
		roomEntities = new Entity * [1] {
			G,
		};

	}

	~Dining1() {
	}

	

};