#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Twine.h"

class Entity {
public:
	Twine name;
	Twine description;
	int hp;


	Entity();
	~Entity();
	Entity(Twine t, Twine t2, int mHP);

private:
	int maxHP;

};



#endif // !ENTITY_H
