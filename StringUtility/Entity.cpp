#include "Entity.h"

Entity::Entity() {
	hp = 0;
	maxHP = 0;
	s.InitStats(0, 0, 0, 0, 0, 0);
	Dialogue = nullptr;
	alive = true;
	currentRoom = nullptr;
}

Entity::~Entity() {
}

Entity::Entity(Twine t, Twine t2, int conScore) {
	alive = true;
	this->name.SetTwine(t);
	this->description.SetTwine(t2);
	s.InitStats(0, 0, conScore, 0, 0, 0);
	this->maxHP = s.Constitution;
	this->hp = maxHP;
	currentRoom = nullptr;
}