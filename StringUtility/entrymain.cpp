#include <iostream>
#include <fstream>
#include <string>
#include "Windows.h"

#include "Game.h"


int main() {

	DWORD mode;
	GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode);
	SetConsoleTitleA(Twine("Ghost House").TStr());
	
	
	
	Game g;
	
	system("cls");
	g.Run();
	

	g.DoCredits();


}







