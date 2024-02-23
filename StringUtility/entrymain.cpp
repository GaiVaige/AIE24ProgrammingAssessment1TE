#include <iostream>
#include "Game.h"
#include "Twine.h"
#include "Windows.h"



int main() {

	DWORD mode;
	GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode);
	SetConsoleTitleA(Twine("Ghost House"));
	
	
	
	Game g;
	
	system("cls");
	g.Run();
	



}


