#include "Entity.h"
#include "Player.h"

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

Entity::Entity(Twine t, Twine t2, Twine dia, Twine deadD, int statBon, bool doesSetFlag, int flagToSet) {
	alive = true;
	setsFlag = doesSetFlag;
	this->flagToSet = flagToSet;
	this->s.InitStats(10 + statBon, 10 + statBon, 10 + statBon, 10 + statBon, 10 + statBon, 10 + statBon);
	this->name.SetTwine(t);
	this->description.SetTwine(t2);
	this->Dialogue.SetTwine(dia);
	this->deadDesc.SetTwine(deadD);
	this->maxHP = this->s.Constitution;
	this->hp = maxHP;
	currentRoom = nullptr;
}

void Entity::Interact(Player* p) {

	if (this->alive) {
		this->Dialogue.DisplayTwine();
		if (this->setsFlag) {
			p->flags[flagToSet] = true;
		}
	}
	else {
		this->deadDesc.DisplayTwine();
	}



}