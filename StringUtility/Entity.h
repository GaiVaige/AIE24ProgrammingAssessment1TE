#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Twine.h"

class Entity {
public:
	Twine name = "Gorilla2";
	Twine description = "This is the 2nd Gorilla";
	int hp;


	Entity();
	~Entity();
	Entity(Twine t, Twine t2, int mHP);

private:
	int maxHP;

};



#endif // !ENTITY_H
