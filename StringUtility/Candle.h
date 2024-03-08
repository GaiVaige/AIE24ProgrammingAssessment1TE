#pragma once
#ifndef CANDLE_H
#define CANDLE_H
#include "Item.h"
#include "Twine.h"
#include "Knife.h"


class Candle : public Item {

private:
	int CandleTrack = 1;
	

public:
	Game* g;
	Candle() {
		g = nullptr;
	}

	Twine Name() override {
		return "Candle";
	}

	Twine Description() override {
		return "A nice candle.";
	}


	Twine Use() override {
		Twine candle = "The candle in your hand burns ";
		int level = CandleTrack;
		switch (level) {
		case 1:
			candle.Append("bright");
			break;
		case 2:
			candle.Append("dim");
			break;
		case 3:
			candle.Append("dull");
			break;

		}


		candle.Append("ly.\n");
		if (CandleTrack < 2) {
			CandleTrack++;
		}

		if (g->p->currentRoom->name == "Kitchen") {

			if (g->p->flags[0] != true) {
				candle.Append("The candle lights up the benches.\nYou collect a knife!\n");
				Knife* k = new Knife;
				g->p->AddItem(*k);
				k->g = this->g;
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