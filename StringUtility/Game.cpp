#include "Game.h"
#include "Item.h"
#include "Candle.h"
#include "Windows.h"

//room includes
#include "Room.h"
#include "Kitchen.h"
#include "Library.h"


Game::Game() {
	p = new Player;
	Spell* fireball = new Spell(Twine("Fireball"), Twine("Make fireball!"), 20000);
	p->LearnSpell(fireball);
	Mansion[0][0] = new Kitchen;
	Mansion[0][1] = new Kitchen;
	Mansion[0][2] = new Kitchen;
	Mansion[0][3] = new Kitchen;
	Mansion[0][4] = new Kitchen;
	Mansion[1][0] = new Kitchen;
	Mansion[1][1] = new Kitchen;
	Mansion[1][2] = new Kitchen;
	Mansion[1][3] = new Kitchen;
	Mansion[1][4] = new Kitchen;
	Mansion[2][0] = new Kitchen;
	Mansion[2][1] = new Kitchen;
	Mansion[2][2] = new Kitchen;
	Mansion[2][3] = new Kitchen;
	Mansion[2][4] = new Kitchen;
	Mansion[3][0] = new Kitchen;
	Mansion[3][1] = new Kitchen;
	Mansion[3][2] = new Kitchen;
	Mansion[3][3] = new Kitchen;
	Mansion[3][4] = new Kitchen;
	Mansion[4][0] = new Kitchen;
	Mansion[4][1] = new Kitchen;
	Mansion[4][2] = new Kitchen;
	Mansion[4][3] = new Kitchen;
	Mansion[4][4] = new Kitchen;
	for (int i = 0; i < 10; i++) {
		flags[i] = false;
	}
}

Game::~Game() {

	delete p;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			delete Mansion[x][y];
		}
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

			if (x == pPos.X && (5 - yPos) == pPos.Y) {
				Twine p = " & ";
				p.Colour(255, 0, 0, true);
				std::cout << p;
			}
			else {

				if (Mansion[x][(5-cursorPos.Y)] != nullptr) {
					
					Twine t = Mansion[x][(5-cursorPos.Y)]->mapChar;

					if (Mansion[x][(5-cursorPos.Y)]->doDesc) {
						std::cout << " " << t.Colour(0, 0, 0, true) << " ";
					}
					else {
						std::cout << " " << t.Colour(255, 255, 255, true) << " ";
					}
					
				}
				else {

					std::cout << Twine(" X ");
				}

			}

		}
		std::cout << "}";
		yPos--;
	}
	
	std::cout << '\n';

}

