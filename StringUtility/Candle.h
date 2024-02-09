#pragma once
#ifndef CANDLE_H
#define CANDLE_H
#include "Item.h"
#include "Twine.h"





class Candle : public Item {

public:

	Twine candleLevels[3]{
	"bright",
	"dim",
	"snuffed",

	};
	Twine name = "Candle";
	bool hasItem = false;
	int CandleTrack = 0;
	int itemSlot = 0;
	

public:
	Candle() {

	}

	void UseItem() override {
		std::cout << candleLevels[CandleTrack];
		if (CandleTrack < 3) {
			CandleTrack++;
		}
	}





};

#endif