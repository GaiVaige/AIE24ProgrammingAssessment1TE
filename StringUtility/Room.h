#pragma once
#include "Twine.h"
#include "Entity.h"
class Player;
#include "Item.h"


class Room {

protected:

	Twine description;
	//ascii for the art of the room
	Twine ASCII;
	Twine* extraDescriptions;
	Twine* keyWords;
	Twine validInspectCommands;
	Twine validInspectPrompts;
	Entity** roomEntities;

	//trackers for loops to check rooms entities and descriptions
	int entityNum;
	int descLength;


public:
	//checks if a room has been entered, will replace map char with the char above if it has been
	bool doDesc = true;
	Twine name;
	Twine mapChar;
	Item* roomItem;
	Room();
	~Room();
	//returns the rooms descritpion
	virtual void DescribeRoom();
	virtual Twine InspectRoom(Twine& t);
	//checks if dialogue exists on the entity
	virtual void CheckForDialogue(Twine& t, Player* p);
	//checks through the entity names to see if the entity exists
	Entity* CheckEntityNames(const Twine& searchT);





};