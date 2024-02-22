#pragma once
#ifndef CUSTOM_SPELL_H
#define CUSTOM_SPELL_H
#include "Twine.h"
#include "Entity.h"

class Spell {

public:


	Twine name;
	Twine description;
	int damage;
	bool hasTarget;


	Spell();
	~Spell();
	Spell(Twine n, Twine de, int da);
	Spell(Twine n, Twine de, int da, bool hasTarget);
	virtual void Cast();
	virtual void Cast(Entity* target);
	static bool Compare(Spell a, Spell b);
	void ApplyDamage(Entity* target);
};



#endif // !CUSTOM_SPELL_H
