#pragma once
#ifndef ROOM_HEADER
#define ROOM_HEADER
#include "Twine.h"
#include "Entity.h"

class Room {

public:
	Twine name;
	Twine description;
	Twine* extraDescriptions;
	Twine* keyWords;
	int descLength;
	bool doDesc = true;
	Twine validInspectCommands;
	Twine validInspectPrompts;
	Entity** roomEntities;
	int entityNum;
	Twine mapChar;

	Room();
	~Room();

	virtual void DescribeRoom();
	virtual Twine InspectRoom(Twine& t);
	virtual Twine CheckForDialogue(Twine& t);
	Entity* CheckEntityNames(Twine& searchT);





};






#endif