#include <iostream>
#include "Game.h"
#include "Twine.h"
#include "Windows.h"
#include "Roll.h"
int main() {


	DWORD mode;
	GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode);
	SetConsoleTitleA(Twine("Ghost House").TStr());
	
	
	
	Game g;
	
	system("cls");
	g.Run();
	
	
	////system("start https://aie.edu.au/course_category/programming/");


}


