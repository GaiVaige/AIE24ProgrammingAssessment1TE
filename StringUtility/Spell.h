#pragma once
#include "Twine.h"
#include "Entity.h"

class Spell {

protected:

	int damage;
	int dFace;
	int dAmnt;

public:

	Twine name;
	Twine description;
	bool hasTarget;

	//unused, cut for time
	enum DamageType {
		FIRE,
		ICE,
		PSYCHIC,
		PHYSICAL,
		GUN,
		NECROTIC,
	};




	Spell();
	~Spell();
	//can initialise a spell to either do damage or not
	Spell(Twine n, Twine de);
	Spell(Twine n, Twine de, int dAm, int dMax, bool hasTarget, DamageType dm);
	//returns spell description at this point, further diversity cut for time
	virtual void Cast();
	virtual void Cast(Entity* target);
	//checks if two spells are identical
	static bool SpellEqualTo(Spell& a, Spell& b);
	//compares the name of two spells for the purpose of binary search
	static bool Compare(Spell& a, Spell& b);
	void ApplyDamage(Entity* target);
};




