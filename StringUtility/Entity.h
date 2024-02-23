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
	Twine* Dialogue;
	Stats s;
	int hp;
	bool alive;
	bool setsFlag;
	int flagToSet;
	Room* currentRoom;


	Entity();
	~Entity();
	Entity(Twine t, Twine t2, int conScore);
	virtual void Interact(Player* p);

private:
	int maxHP;

};



#endif // !ENTITY_H
