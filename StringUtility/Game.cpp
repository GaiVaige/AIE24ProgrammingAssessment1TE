#include "Game.h"
#include "Item.h"
#include "Candle.h"
#include "Windows.h"



Game::Game() {
	for (int i = 0; i < 10; i++) {
		flags[i] = false;
	}
}

void Game::Run() {
	Candle* c = new Candle;
	c->SetName("Candle");
	c->g = this;
	p->AddItem(*c);

	p->currentRoom = Mansion[3][3];
	p->xCord = 3;
	p->yCord = 3;

	std::cout << p->name << ": " << p->health << "HP" << '\n';
	while (doGame) {

		this->DrawMap();
		std::cout << '\n';
		p->currentRoom->DescribeRoom();
		p->inputTwine.GetTwine();
		if (p->inputTwine.ToLower() == "quit game") {
			doGame = false;
			system("CLS");
			std::cout << "rude, bye.";
			break;
		}
		system("CLS");
		std::cout << p->name << ": " << p->health << "HP" << '\n';
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


	int yPos = 5;
	COORD pPos = { p->xCord, p->yCord };
	for (int y = roomYDim - 1; y > -1; y--) {
		COORD cursorPos = { 70, yPos };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);

		for (int x = 0; x < roomXDim; x++) {


			if (x == 0) {
				std::cout << Twine("{");
			}

			if (x + 1 == pPos.X && (5 - cursorPos.Y) + 1 == pPos.Y) {
				Twine p = " # ";
				p.Colour(255, 20, 50, true);
				std::cout << p;
			}
			else {
				std::cout << Twine(" X ");
			}

		}
		std::cout << "}";
		yPos--;
	}
	
	std::cout << '\n';

}

