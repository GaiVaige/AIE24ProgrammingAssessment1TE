#include <iostream>
#include "Game.h"
#include "Twine.h"
#include "Spool.h"
#include "Player.h"
#include "Item.h"
#include "Candle.h"
#include "Spell.h"


//room headers
#include "Room.h"
#include "Kitchen.h"
#include "Library.h"


int main() {

	//Twine tTwine = "This should be what I entered in VS";
	//
	//std::cout << tTwine << '\n';
	//
	//tTwine.SetTwine("This is setting with a constant");
	//
	//std::cout << tTwine << '\n';
	//
	//Twine bTwine = "This is setting from another twine";
	//
	//tTwine.SetTwine(bTwine);
	//
	//std::cout << tTwine << '\n';
	//
	//Twine cTwine = "This is copying this twine to tTwine";
	//
	//tTwine.Copy(cTwine);
	//
	//std::cout << tTwine << '\n';
	//
	//tTwine.Insert("actually I meant inserting a const char* at index 6", 6);
	//
	//std::cout << tTwine << '\n';
	//
	//tTwine.Erase(51, 7);
	//
	//std::cout << tTwine << '\n';
	//std::cout << "And then I erased the inserted const char*" << '\n';
	//
	//tTwine.Insert(bTwine, 6);
	//
	//std::cout << tTwine << '\n';
	//
	//tTwine.Erase(34, 7);
	//
	//std::cout << tTwine << '\n';
	//std::cout << "And then I did the same with another Twine" << '\n';
	//
	//tTwine.Prepend("This is a prepend const");
	//Twine dTwine = " and this is an appended Twine";
	//tTwine.Append(dTwine);
	//std::cout << tTwine << '\n';
	//
	//tTwine.Append(" and now I appended this const");
	//Twine eTwine = "And this is a prepended twine ";
	//tTwine.Prepend(eTwine);
	//std::cout << tTwine << '\n';
	//
	//std::cout << tTwine.ToLower().TStr() << '\n';
	//std::cout << tTwine.ToUpper().TStr() << '\n';
	//tTwine.Wobble();
	//tTwine.DisplayTwine();
	//
	//
	//std::cout << "Ok, let's take a breather. How about you choose what tTwine is: ";
	//std::cin >> tTwine;
	//std::cout << tTwine << "? LAME." << '\n';
	//
	//
	//Twine aTwine;
	//Twine aaTwine;
	//std::cout << "Ok. Enter a word: ";
	//std::cin >> aTwine;
	//std::cout << "Enter another word: ";
	//std::cin >> aaTwine;
	//
	//if (aTwine.Compare(aaTwine)) {
	//
	//	std::cout << "Thats the same word, lazy much?" << '\n';
	//}
	//else {
	//	std::cout << aTwine << " and " << aaTwine << " aren't the same? Creative!" << '\n';
	//}
	//
	//
	//std::cout << "Ok. Last thing, I PROMISE. Check this out. My name is Geraldina. But when I use Twine::Replace, my name becomes: " << '\n';
	//std::cout << "..." << '\n';
	//aTwine = "Geraldina";
	//std::cout << "Enter a part of the name Geraldina: ";
	//std::cin >> bTwine;
	//std::cout << "Enter ANYTHING you want: ";
	//std::cin >> cTwine;
	//aTwine.Replace(bTwine, cTwine);
	//std::cout << aTwine << '\n';
	//
	//while (true) {
	//	Twine test = "testtwine";
	//}
	
	//Game g;
	//Player* player = new Player;
	//g.p = player;
	//
	//Kitchen* k = new Kitchen;
	//g.Mansion[1][1] = k;
	//
	//Library* l = new Library;
	//g.Mansion[2][2] = l;
	//
	//g.Run();


	Twine* twAr = new Twine[5]{
	"bursting bladder",
	"Goodbye",
	"custom engine",
	"bustom bingein",
	"buster blader",
	};


	//Player* p = new Player;
	//Spell* fireball = new Spell;
	//fireball->name = "Fireball";
	//fireball->description = "Makes a fire ball";
	//fireball->damage = 200000;
	//p->LearnSpell(fireball);
	//Twine pTwine;
	//pTwine.GetTwine();
	//p->CheckForValidCommand(pTwine);
	//
	//Spool sp = Spool(5, twAr);
	//std::cout << sp.GetAt(1).TStr() << " " << sp.GetAt(0).TStr() << " ";
	//std::cout << sp.GetAt(42).TStr();

	Game g;
	g.DrawMap();

}	



//you left it open, what did we do?

