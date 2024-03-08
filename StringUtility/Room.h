#pragma once
#include "Twine.h"
#include "Entity.h"
class Player;
#include "Item.h"


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
	Item* roomItem;
	Room();
	~Room();
	virtual void DescribeRoom();
	virtual Twine InspectRoom(Twine& t);
	virtual void CheckForDialogue(Twine& t, Player* p);
	Entity* CheckEntityNames(const Twine& searchT);





};