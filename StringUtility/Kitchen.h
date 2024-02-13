#pragma once
#ifndef KITCH_HEADER
#define KITCH_HEADER
#include "Room.h"
#include "Twine.h"




class Kitchen : public Room {

public:
	Twine name = "Kitchen";
	Twine description = "Well, this is strange. This kitchen is covered from head to toe in disgusting, old blood... though evidence of prepared food remains on its counters. People seem to only care about bloodshed, when it's their blood, in their shed...";
	Twine extraDescriptions[4]{
		"The knife is dirty, stabbed into the chopping board. It seems rusty, not the safest to touch.",
		"The cabinets are filled with old, mouldy vegetables. Not the most pleasant smell... though there is a small stone in the back.",
		"The sink is covered in old gunk, blood... well, you hope it's just blood.",
		"Do you really want to open the fridge?",
	};
	int descriptionCount = 4;








};



#endif // !KITCH_HEADER
