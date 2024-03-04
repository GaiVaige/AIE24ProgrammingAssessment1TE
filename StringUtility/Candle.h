#pragma once
#ifndef CANDLE_H
#define CANDLE_H
#include "Item.h"
#include "Twine.h"
#include "Knife.h"




class Candle : public Item {

private:

	Twine candleLevels[3]{
	"bright",
	"dim",
	"dul",

	};
	Twine name = "Candle";
	bool hasItem = false;
	int CandleTrack = 0;
	int itemSlot = 0;
	

public:
	Game* g;
	Candle() {
		g = nullptr;
	}

	Twine Name() override {
		return "Candle";
	}

	Twine Desc() override {
		return "A nice candle.";
	}


	Twine Use() override {
		Twine candle = "The candle in your hand burns ";
		Twine level = candleLevels[CandleTrack];
		candle.Append(level);
		candle.Append("ly.\n");
		if (CandleTrack < 2) {
			CandleTrack++;
		}

		if (g->p->currentRoom->name == "Kitchen") {

			if (g->p->flags[0] != true) {
				candle.Append("The candle lights up the benches. You collect a knife!\n");
				Knife* k = new Knife;
				g->p->AddItem(*k);
				k->g = this->g;
				g->p->flags[0] = true;
			}
			else {
				candle.Append("The candle lights up the benches.");
			}

			return candle;
		}


		return candle;
	}





};

#endif