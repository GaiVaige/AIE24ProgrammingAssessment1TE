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
	Spell(Twine n, Twine de);
	Spell(Twine n, Twine de, int dAm, int dMax, bool hasTarget, DamageType dm);
	virtual void Cast();
	virtual void Cast(Entity* target);
	static bool SpellEqualTo(Spell& a, Spell& b);
	static bool Compare(Spell& a, Spell& b);
	void ApplyDamage(Entity* target);
};




