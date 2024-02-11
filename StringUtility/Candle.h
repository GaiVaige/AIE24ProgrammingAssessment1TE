#pragma once
#ifndef CANDLE_H
#define CANDLE_H
#include "Item.h"
#include "Twine.h"





class Candle : public Item {

public:

	Twine candleLevels[3]{
	"\x1B[38;2;220;120;120mbright\x1b[0m",
	"dim",
	"dul",

	};
	Twine name = "\x1B[38;2;255;0;0mCandle\x1b[0m";
	bool hasItem = false;
	int CandleTrack = 0;
	int itemSlot = 0;
	

public:
	Candle() {

	}

	void UseItem() override {
		std::cout << "The candle in your hand burns " << candleLevels[CandleTrack] << "ly." << '\n';
		if (CandleTrack < 2) {
			CandleTrack++;
		}
	}





};

#endif