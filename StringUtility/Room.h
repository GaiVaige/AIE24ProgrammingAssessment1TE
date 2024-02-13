#pragma once
#ifndef ROOM_HEADER
#define ROOM_HEADER
#include "Twine.h"
#include "Player.h"

class Room {

public:
	Twine name;
	Twine description;
	int descriptionCount = 0;
	Twine extraDescriptions;
	Twine validInspectCommands;
	Twine validInspectPrompts;


	virtual Twine DescribeRoom(Twine& t);
	virtual Twine InspectRoom(Twine& t);





};






#endif