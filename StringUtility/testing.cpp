#include <iostream>
#include "Twine.h"



int main() {

	Twine t1 = "Antyyyyu";
	Twine t2 = "I am stinky";

	Twine::Copy(t1, t2);
	t1.DisplayTwine();
	std::cout << t2.LengthNoSpace();
	}





