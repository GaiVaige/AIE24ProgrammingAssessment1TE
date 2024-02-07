#include <iostream>
#include "Twine.h"



int main() {

	bool gameShouldRun = true;
	Twine pTwine;
	Twine validTwine[4];
	Twine errorTwine = "Invalid Command. Fuckface.";
	validTwine[0] = "use";
	validTwine[1] = "dance";
	validTwine[2] = "sing";
	validTwine[3] = "fight";



	while (gameShouldRun) {


		pTwine.GetTwine();
		if (!pTwine.FindInSpool(validTwine, 4)) {
			std::cout << errorTwine << '\n';
			
		}

	}



	

	}	





