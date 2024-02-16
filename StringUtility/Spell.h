#pragma once
#ifndef CUSTOM_SPELL_H
#define CUSTOM_SPELL_H
#include "Twine.h"

class Spell {

public:


	Twine name;
	Twine description;
	int damage;


	Spell();
	~Spell();
	Spell(Twine n, Twine de, int da);
	virtual void Cast();
	static bool Compare(Spell a, Spell b);
	void ApplyDamage();
};



#endif // !CUSTOM_SPELL_H
