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

	void UseItem() override {
		std::cout << "The candle in your hand burns " << candleLevels[CandleTrack] << "ly." << '\n';
		if (CandleTrack < 2) {
			CandleTrack++;
		}

		if (g->p->currentRoom->name == "Kitchen") {
			std::cout << "The lamp lights up the benches." << '\n';
			g->flags[0] = true;
		}


		return;
	}





};

#endif