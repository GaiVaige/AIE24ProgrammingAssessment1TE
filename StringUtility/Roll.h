#pragma once
#include "time.h"
#include "random"
struct Roll {
	static int RollDice(int amnt, int maxFace) {
		
		int retVal = 0;
		for (int i = 0; i < amnt; i++) {
			srand((unsigned int)time(NULL) + (i * maxFace-amnt));
			retVal += rand() % (maxFace) + 1;
		}
		return retVal;
	}



};