#pragma once
#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include "Player.h"


static int maxFlagID = 10;
static int roomXDim = 5;
static int roomYDim = 5;

class Game {

public:
	Room* Mansion[5][5];
	Player* p;
	bool doGame = true;

	Game();
	~Game();
	void SetFlag(int boolID, bool stateID);
	void DrawMap();
	void Run();



};








#endif // !GAME_H
