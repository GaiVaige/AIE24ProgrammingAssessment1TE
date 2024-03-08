#pragma once
#include "Room.h"

class Hallway : public Room {
public:
	Hallway() {
		mapChar = "H";
		name = "Hallway";
		ASCII =
" =============================\n\
 |                            |\n\
 ||                          ||\n\
 ||                          ||\n\
 |9          }o{             p|\n\
 ||       ____u______        ||\n\
 ||       |         |        ||\n\
 ||-------|---------|--------||\n";
description = "This is a hallway.\n\n\
There isn't much of note, just a flower on the table..\n";
		extraDescriptions = new Twine[2]{
			"The flower is nice, but wilting...",
			"The doors are open, various other hallways link to it, what a strange, mazelike house...",
		};

		keyWords = new Twine[2]{
			"flower",
			"doors",
		};
		descLength = 2;

	}

	~Hallway() {
	}




};