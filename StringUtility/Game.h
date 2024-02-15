#pragma once
#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include "Player.h"

class Game {

public:
	Room* Mansion[3][3];
	Player* p;
	bool doGame = true;

	Game();
	~Game() = default;


	void Run();


};








#endif // !GAME_H
