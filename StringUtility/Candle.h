#pragma once
#ifndef CANDLE_H
#define CANDLE_H
#include "Item.h"
#include "Twine.h"





class Candle : public Item {

public:
	Game* g;
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
			candle.Append("The lamp lights up the benches.\n");
			g->p->flags[0] = true;
			return candle;
		}


		return candle;
	}





};

#endif