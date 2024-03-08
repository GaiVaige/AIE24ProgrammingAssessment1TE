#pragma once
#include "time.h"
#include "random"
struct Roll {
	static int RollDice(int amnt, int maxFace) {
		
		int retVal = 0;
		for (int i = 0; i < amnt; i++) {
			//ensures different seeds for multi-dice rolls (eg. rolling 4 d6s)
			srand((unsigned int)time(NULL) + (i * maxFace-amnt));
			retVal += rand() % (maxFace) + 1;
		}
		return retVal;
	}



};