#pragma once
#ifndef ROOM_HEADER
#define ROOM_HEADER
#include "Twine.h"
#include "Entity.h"
class Player;


class Room {

protected:

	Twine description;
	Twine* extraDescriptions;
	Twine* keyWords;
	int descLength;
	Twine validInspectCommands;
	Twine validInspectPrompts;
	int entityNum;


public:
	Room();
	~Room();
	Twine name;
	Twine mapChar;
	Entity** roomEntities;
	bool doDesc = true;
	virtual void DescribeRoom();
	virtual Twine InspectRoom(Twine& t);
	virtual void CheckForDialogue(Twine& t, Player* p);
	Entity* CheckEntityNames(Twine& searchT);





};






#endif