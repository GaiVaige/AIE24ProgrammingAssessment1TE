#pragma once
#ifndef KITCH_HEADER
#define KITCH_HEADER
#include "Room.h"
#include "Twine.h"




class Kitchen : public Room {

public:
	
	Kitchen() {
		mapChar = "K";
		name = "Kitchen";
		description = "Well, this is strange...\n\nThis kitchen is covered from head to toe in disgusting, old blood...\nThough evidence of prepared food remains on its counters.\nPeople seem to only care about bloodshed, when it's their blood...\nin their shed...";

		extraDescriptions = new Twine[5]{
			"The knife is dirty, stabbed into the chopping board.\nIt seems rusty, not the safest to touch.",
			"The cabinets are filled with old, mouldy vegetables.\nNot the most pleasant smell...\nThough there is a small stone in the back.",
			"The cabinets are filled with old, mouldy vegetables.\nNot the most pleasant smell...\nThough there is a small stone in the back.",
			"The sink is covered in old gunk, blood... well, you hope it's just blood.",
			"Do you really want to open the fridge?",
		};

		keyWords = new Twine[5]{
			"knife",
			"cabinet",
			"cabinets",
			"sink",
			"fridge",
		};
		descLength = 5;

	}

	~Kitchen() {
	}









};



#endif // !KITCH_HEADER
