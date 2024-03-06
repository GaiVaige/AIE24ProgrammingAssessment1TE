#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include "Windows.h"


#include "Game.h"
#include "Twine.h"
#include "Roll.h"

void DoTest() {

	//Twine test function:
//Each twine function is given parameters to create a string, and to confirm validity of test, checks against a const char reference of that string
//A test rate of less than 100% will be considered a failure
//These are written to the file 'TwineTest.txt', and begins with an entry of the current date and time via Chrono, and a test number.
	std::fstream tFile;
	int testPass = 0;

	tFile.open("TwineTest.txt", std::ios::out | std::ios::app);
	if (tFile.is_open()) {



		std::cout << "File read successfully!" << '\n';
		const auto now = std::chrono::system_clock::now();
		const std::time_t nowT = std::chrono::system_clock::to_time_t(now);
		tFile << "\n";
		tFile << Twine("Tested at: ").TStr() << std::ctime(&nowT) << '\n';
		Twine test;
		if (test == "") {
			tFile << "Test 1: Empty Construction Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 1: Empty Construction Failed!" << '\n';
		}

		test.SetTwine("Hello, World!");

		if (test == "Hello, World!") {
			tFile << "Test 2: In IDE Overwrite Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 2: In IDE Overwrite Failed!" << '\n';
		}

		test.GetTwine();

		if (test == "I entered this") {
			tFile << "Test 3: Read From Console Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 3: Read From Console Failed!" << '\n';
		}

		test.SetTwine("Test");

		if (test.Length() == 4) {
			tFile << "Test 4: Length Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 4: Length Failed!" << '\n';
		}

		if (test.CharAt(1) == 'e') {
			tFile << "Test 5: CharAt Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 5: CharAt Failed!" << '\n';
		}

		if (test.EqualTo("Test")) {
			tFile << "Test 6: Compare Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 6: Compare Failed!" << '\n';
		}

		test.Append("HI");

		if (test.EqualTo("TestHI")) {
			tFile << "Test 7: Append Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 7: Append Failed!" << '\n';
		}

		test.Prepend("HI");

		if (test.EqualTo("HITestHI")) {
			tFile << "Test 8: Prepend Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 8: Prepend Failed!" << '\n';
		}

		if (test.ToUpper() == "HITESTHI") {
			tFile << "Test 9: To Upper Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 9: To Upper Failed!" << '\n';
		}

		if (test.ToLower() == "hitesthi") {
			tFile << "Test 10: To Lower Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 10: To Lower Failed!" << '\n';
		}

		if (test.Find("Test") == 2) {
			tFile << "Test 11: Find Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 11: Find Failed!" << '\n';
		}

		if (test.Find("Test", 4) == -1) {
			tFile << "Test 12: Find From Index Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 12: Find From Index Failed!" << '\n';
		}

		test.Replace("Test", "Hell Yeah!");
		if (test == "HIHell Yeah!HI") {
			tFile << "Test 13: Replace Successful!" << '\n';
			testPass++;
		}
		else {
			tFile << "Test 13: Replace Failed!" << '\n';
		}

	}
	else {
		std::cout << "Failure to open file!";
	}

	double x = (testPass / (double)13) * 100;
	tFile << "FINAL RESULT: " << x << "%" << "\n";
	if (x != 100) {
		tFile << "TEST FAILED!";
	}
	else {
		tFile << "TEST SUCCESSFUL!";
	}
	tFile << "\n";
	tFile << "END OF TEST" << "\n";
	tFile.close();
}

int main() {

	//DoTest();
	//
	//return 0;

	DWORD mode;
	GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode);
	SetConsoleTitleA(Twine("Ghost House").TStr());
	
	
	
	Game g;
	
	system("cls");
	g.Run();
	




}







