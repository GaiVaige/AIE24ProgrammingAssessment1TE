#include <iostream>
#include "Twine.h"



int main() {

	Twine t1 = "Antyyyyu";
	Twine t2 = "antiii";
	Twine t3 = t1 + t2;

	t1.Erase(4, 3);
	t1.DisplayTwine();
	t3.DisplayTwine();

	}





