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

void Spell::Cast() {
	std::cout << this->description << '\n';
}
bool Spell::Compare(Spell a, Spell b) {
	if (a.name == b.name) {
		return true;
	}
	else {
		return false;
	}
}