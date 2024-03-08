#pragma once
#include "Entity.h"

class Gorilla : public Entity {

public:
	Gorilla() = default;
	~Gorilla() = default;

	Gorilla(Twine t, Twine t2, Twine dia, Twine deadD, int statBon, bool doesSetFlag, int flagToSet)
		: Entity(t, t2, dia, deadD, statBon, doesSetFlag, flagToSet)
	{};


};