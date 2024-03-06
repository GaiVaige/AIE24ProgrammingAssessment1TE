#pragma once
#include "Entity.h"
#include "Player.h"

class Butler : public Entity {

public:
	Butler() = default;
	~Butler() = default;
	Butler(Twine t, Twine t2, Twine dia, Twine deadD, int statBon, bool doesSetFlag, int flagToSet) :Entity(t, t2, dia, deadD, statBon, doesSetFlag, flagToSet) {};


public:
	void Interact(Player* p) override{

		if (this->alive) {
			this->Dialogue.DisplayTwine();
			if (this->setsFlag) {
				p->flags[flagToSet] = true;
			}
		}
		else {
			this->deadDesc.DisplayTwine();
			if (this->setsFlag) {
				p->flags[flagToSet] = true;
			}
		}



	}



};