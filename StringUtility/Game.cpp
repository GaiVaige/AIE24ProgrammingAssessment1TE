#include "Game.h"
#include "Windows.h"
#include "Roll.h"

//items
#include "Item.h"
#include "Candle.h"
#include "Knife.h"


//room includes
#include "Room.h"
#include "Kitchen.h"
#include "Library.h"
#include "Dining1.h"
#include "Dining2.h"
#include "Hallway.h"
#include "Piano.h"
#include "ButlersRoom.h"


//bool doNoPlay = false;
//bool isCreated = false;

//items for random
#include "Painting.h"
#include "BoxODons.h"
#include "Shoelace.h"

Game::Game() {
	p = new Player;
	Spell* fireball = new Spell(Twine("Fireball"), Twine("Summon a great blaze of flame."), 8, 6, true, Spell::FIRE);
	p->LearnSpell(fireball);
	Spell* vicmock = new Spell(Twine("Vicious Mockery"), Twine("Hurl mean words at your target."));
	p->LearnSpell(vicmock);
	Spell* gethint = new Spell(Twine("Guidance"), Twine("Call upon a favour from the gods above in these trying times..."));
	p->LearnSpell(gethint);
	Spell* dance = new Spell(Twine("Dance Macabre"), Twine("Make em dance till they're dead!"), 12, 4, true, Spell::NECROTIC);
	p->LearnSpell(dance);
	Spell* ahhh = new Spell(Twine("Maddening Scream"), Twine("Send a horrendous torrent of psychic shock to your target's skull."), 3, 12, true, Spell::PSYCHIC);
	p->LearnSpell(ahhh);
	p->SpellSort();
	Mansion[0][0] = new Hallway;
	Mansion[0][1] = new Hallway;
	Mansion[0][2] = new Hallway;
	Mansion[0][3] = new Kitchen;
	Mansion[0][4] = new Dining1;
	Mansion[1][0] = new Hallway;
	Mansion[1][1] = new Hallway;
	Mansion[1][2] = new Hallway;
	Mansion[1][3] = new Hallway;
	Mansion[1][4] = new Dining2;
	Mansion[2][0] = new Hallway;
	Mansion[2][1] = new Hallway;
	Mansion[2][2] = new Hallway;
	Mansion[2][3] = new Library;
	Mansion[2][4] = new Hallway;
	Mansion[3][0] = new Hallway;
	Mansion[3][1] = new Hallway;
	Mansion[3][2] = new Piano;
	Mansion[3][3] = new Hallway;
	Mansion[3][4] = new Hallway;
	Mansion[4][0] = new ButlersRoom;
	Mansion[4][1] = new Hallway;
	Mansion[4][2] = new Hallway;
	Mansion[4][3] = new Hallway;
	Mansion[4][4] = new Hallway;

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			Mansion[x][y]->roomItem = GenItem(x, y);
		}
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
	c->g = this;
	p->AddItem(*c);
	p->currentRoom = Mansion[2][0];
	p->xCord = 2;
	p->yCord = 0;
	std::cout << p->name << ": " << p->health << "HP" << '\n';
	while (doGame) {
		std::cout << '\n';

		if (Mansion[0][4]->CheckEntityNames("Gorilla")->alive == false) {
			break;
		}

		this->DrawMap();
		for (int i = 0; i < p->displaceVal; i++) {
			std::cout << '\n';
		}
		p->displaceVal = 0;
		p->currentRoom->DescribeRoom();
		if (p->currentRoom->roomItem != nullptr) {
			p->currentRoom->roomItem->Description().DisplayTwine();
		}
		p->inputTwine.GetTwine();
		if (p->inputTwine.ToLower() == Twine("quit game").ToLower()) {
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

void Game::DoCredits()
{
	std::cout << "Done!\n";
	std::cout << "Thank you for playing my game!\n";
}

void Game::SetFlag(int boolID, bool stateID) {

	if (boolID < maxFlagID && boolID > 0) {
		p->flags[boolID] = stateID;

	}


}

void Game::DrawMap() {


	int yPos = 5;
	COORD pPos = { (short)p->xCord, (short)p->yCord };
	for (int y = roomYDim - 1; y > -1; y--) {
		COORD cursorPos = { 70, (short)yPos };

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
						std::cout << " " << Twine("#").Colour(0, 255, 0, true) << " ";
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

Item* Game::GenItem(int x, int y) {
	srand((unsigned int)time(NULL) + x * y);
	if (rand()%2 != 0) {

		int dCheck = rand()%3 + 1;

		switch (dCheck) {

		case 1:
			return new Painting;
			break;
		case 2:
			return new BoxODons;
			break;
		case 3:
			return new Shoelace;
			break;

		}
	}
	return nullptr;
}



