#include "Game.h"



Game::Game() {
}

void Game::Run() {

	p->currentRoom = Mansion[1][1];
	p->xCord = 1;
	p->yCord = 1;


	while (doGame) {
		p->currentRoom->DescribeRoom();
		p->inputTwine.GetTwine();
		if (p->inputTwine.ToLower() == "quit game") {
			doGame = false;
			break;
		}
		system("CLS");
		p->CheckForValidCommand(p->inputTwine);
		p->currentRoom = Mansion[p->xCord][p->yCord];
	}
	}
