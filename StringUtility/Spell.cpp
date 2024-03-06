#include "Spell.h"
#include "Roll.h"

Spell::Spell() {

}
Spell::~Spell() {

}



Spell::Spell(Twine n, Twine de) {
	this->name.SetTwine(n);
	this->description = de;
	this->damage = 0;
}

Spell::Spell(Twine n, Twine de, int dAm, int dMax, bool hasTarget, DamageType dm) {
	this->name.SetTwine(n);
	this->description = de;
	this->hasTarget = hasTarget;
	this->damage = 0;
	this->dFace = dMax;
	this->dAmnt = dAm;
}

void Spell::Cast() {
	std::cout << this->description << '\n';
}

void Spell::Cast(Entity* target) {
	if (target != nullptr) {
		ApplyDamage(target);
	}
}

bool Spell::SpellEqualTo(Spell& a, Spell& b) {
	if (a.name == b.name) {
		return true;
	}
	else {
		return false;
	}
}

bool Spell::Compare(Spell& a, Spell& b) {
	if (a.name > b.name) {
		return true;
	}
	else {
		return false;
	}
}

void Spell::ApplyDamage(Entity* target) {


	if (target->alive) {
		this->damage = Roll::RollDice(this->dAmnt, this->dFace);
		target->hp -= this->damage;
		this->damage = 0;
		if (target->hp <= 0) {
			target->hp = 0;
			target->alive = false;
			std::cout << target->name << " has been defeated!" << '\n';
		}
		return;
	}
	else {
		std::cout << target->deadDesc << '\n';
	}
	return;


}