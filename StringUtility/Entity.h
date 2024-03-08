#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Twine.h"
#include "Stats.h"
class Room;
class Player;

class Entity {
public:
	Twine name;
	Twine description;
	Twine deadDesc;
	Twine Dialogue;
	Stats s;
	int hp;
	int ac;
	bool alive;
	bool setsFlag;
	int flagToSet;


	Entity();
	~Entity();
	Entity(Twine t, Twine t2, Twine dia, Twine deadD, int statBon, bool doesSetFlag, int flagToSet);
	//can be used to set the boolean values in the players flags[] variable
	virtual void Interact(Player* p);

private:
	int maxHP;

};



#endif // !ENTITY_H
