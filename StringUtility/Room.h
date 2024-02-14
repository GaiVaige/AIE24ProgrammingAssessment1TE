#pragma once
#ifndef ROOM_HEADER
#define ROOM_HEADER
#include "Twine.h"

class Room {

public:
	Twine name;
	Twine description;
	Twine* extraDescriptions;
	Twine* keyWords;
	int descLength;
	Twine validInspectCommands;
	Twine validInspectPrompts;

	virtual Twine Name();
	virtual Twine Description();
	virtual Twine* ExtraDescriptions();
	virtual Twine* KeyWords();
	virtual int DescLength();
	virtual Twine ValidInspectCommands();
	virtual Twine ValidInspectPrompts();

	virtual Twine DescribeRoom();
	virtual Twine InspectRoom(Twine& t);





};






#endif