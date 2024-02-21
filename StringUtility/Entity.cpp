#include "Entity.h"

Entity::Entity() {
	hp = 0;
	maxHP = 0;
}

Entity::~Entity() {
}

Entity::Entity(Twine t, Twine t2, int mHP) {
	this->name.SetTwine(t);
	this->description.SetTwine(t2);
	this->maxHP = mHP;
	this->hp = maxHP;
}