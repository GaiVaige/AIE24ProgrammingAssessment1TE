#include "Spell.h"

Spell::Spell() {

}
Spell::~Spell() {

}



Spell::Spell(Twine n, Twine de, int da) {
	this->name.SetTwine(n);
	this->description = de;
	this->damage = da;
}

Spell::Spell(Twine n, Twine de, int da, bool hasTarget) {
	this->name.SetTwine(n);
	this->description = de;
	this->hasTarget = hasTarget;
	this->damage = da;
}

void Spell::Cast() {
	std::cout << this->description << '\n';
}

void Spell::Cast(Entity* target) {
	if (target != nullptr) {
		ApplyDamage(target);
	}
}

bool Spell::Compare(Spell a, Spell b) {
	if (a.name == b.name) {
		return true;
	}
	else {
		return false;
	}
}

void Spell::ApplyDamage(Entity* target) {


	if (target->alive) {
		target->hp -= this->damage;
		if (target->hp <= 0) {
			target->hp = 0;
			target->alive = false;
		}
		std::cout << target->hp << '\n';
		return;
	}
	else {
		std::cout << "STOP! He's already dead..." << '\n';
	}
	return;


}