#include "Game.h"
#include "Windows.h"



Game::Game() {
}

void Game::Run() {
	p->currentRoom = Mansion[3][3];
	p->xCord = 3;
	p->yCord = 3;


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

void Game::SetFlag(int boolID, bool stateID) {

	if (boolID < maxFlagID && boolID > 0) {
		flags[boolID] = stateID;

	}


}

void Game::DrawMap() {

	int xPos = 0;
	int yPos = 0;
	COORD cursorPos = { 50 + xPos, 50 + yPos };

	for (int x = 0; x < roomXDim; x++) {
		if (x == 0) {
			std::cout << Twine("{");
		}
		std::cout << Twine(" X ");
	}


}

