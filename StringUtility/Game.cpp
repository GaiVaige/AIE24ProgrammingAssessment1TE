#include "Game.h"
#include "Windows.h"


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


//bool doNoPlay = false;
//bool isCreated = false;



Game::Game() {
	p = new Player;
	Spell* fireball = new Spell(Twine("Fireball"), Twine("Make fireball!"), 8, 6, true, Spell::FIRE);
	p->LearnSpell(fireball);
	Spell* test = new Spell(Twine("Test1"), Twine("Test"));
	p->LearnSpell(test);
	Spell* test2 = new Spell(Twine("Test1"), Twine("Test"));
	p->LearnSpell(test2);
	Spell* dance = new Spell(Twine("Dance Macabre"), Twine("Make em dance till they're dead!"));
	p->LearnSpell(dance);
	Spell* ahhh = new Spell(Twine("Maddening Scream"), Twine("AHHHHHHHHHHHHHHHHHHHH"));
	p->LearnSpell(ahhh);
	Spell* ahhh2 = new Spell(Twine("Maddening Scream2"), Twine("AHHHHHHHHHHHHHHHHHHHH"));
	p->LearnSpell(ahhh2);
	p->SpellSort();
	Mansion[0][0] = new Hallway;
	Mansion[0][1] = new Hallway;
	Mansion[0][2] = new Hallway;
	Mansion[0][3] = new Kitchen;
	Mansion[0][4] = new Dining1;
	Mansion[1][0] = new Hallway;
	Mansion[1][1] = new Library;
	Mansion[1][2] = new Kitchen;
	Mansion[1][3] = new Hallway;
	Mansion[1][4] = new Dining2;
	Mansion[2][0] = new Library;
	Mansion[2][1] = new Hallway;
	Mansion[2][2] = new Hallway;
	Mansion[2][3] = new Library;
	Mansion[2][4] = new Hallway;
	Mansion[3][0] = new Kitchen;
	Mansion[3][1] = new Library;
	Mansion[3][2] = new Kitchen;
	Mansion[3][3] = new Piano;
	Mansion[3][4] = new Hallway;
	Mansion[4][0] = new Library;
	Mansion[4][1] = new Hallway;
	Mansion[4][2] = new Library;
	Mansion[4][3] = new Hallway;
	Mansion[4][4] = new Library;
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
		this->DrawMap();
		for (int i = 0; i < p->displaceVal; i++) {
			std::cout << '\n';
		}
		p->displaceVal = 0;



		



		p->currentRoom->DescribeRoom();
		//music! currently disabled
		//if (!isCreated) {
		//	p->isMoving = false;
		//	//music!
			//CreateThread(NULL, NULL, [](LPVOID lpThreadParameter) {
			//	if (doNoPlay) {
			//		Sleep(1200);
			//	}
		//
		//	//	doNoPlay = false;
			//	// music loop
			//	while (!doNoPlay) {
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(260, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(320, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(380, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(260, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(320, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(380, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(260, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(320, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(380, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(260, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(320, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(380, 80); Sleep(150);
		//
		//	//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(440, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(500, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(560, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(440, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(500, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(560, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(440, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(500, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(560, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(440, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(500, 80); Sleep(150);
			//		if (doNoPlay) {
			//			break;
			//		}
			//		Beep(560, 80); Sleep(150);
			//	} 
		//
		//	//	return (DWORD)TRUE;
		//
		//	//	}, (bool*)&doNoPlay, NULL, NULL);
		//}
		//isCreated = true;
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
		//if (p->isMoving) {
		//	doNoPlay = true;
		//	isCreated = false;
		//}
		p->currentRoom = Mansion[p->xCord][p->yCord];


		
	}
}

void Game::SetFlag(int boolID, bool stateID) {

	if (boolID < maxFlagID && boolID > 0) {
		p->flags[boolID] = stateID;

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
				std::cout << Twine("{").TStr();
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

					std::cout << Twine(" X ").TStr();
				}

			}

		}
		std::cout << "}";
		yPos--;
	}
	
	std::cout << '\n';

}



