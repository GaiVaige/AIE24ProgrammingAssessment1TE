#pragma once
#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include "Player.h"

class Game {

public:
	bool flags[10];
	int maxFlagID = 10;
    Room* Mansion[5][5];
	int roomXDim = 5;
	int roomYDim = 5;
	Player* p;
	bool doGame = true;

	Game();
	~Game();
	void SetFlag(int boolID, bool stateID);
	void DrawMap();
	void Run();


};








#endif // !GAME_H
