#pragma once
#ifndef ROOM_HEADER
#define ROOM_HEADER
#include "Twine.h"
#include "Entity.h"
class Player;


class Room {

protected:

	Twine description;
	Twine ASCII;
	Twine* extraDescriptions;
	Twine* keyWords;
	Twine validInspectCommands;
	Twine validInspectPrompts;
	Entity** roomEntities;
	int entityNum;
	int descLength;


public:
	bool doDesc = true;
	Twine name;
	Twine mapChar;
	Room();
	~Room();
	virtual void DescribeRoom();
	virtual Twine InspectRoom(Twine& t);
	virtual void CheckForDialogue(Twine& t, Player* p);
	Entity* CheckEntityNames(Twine& searchT);





};






#endif