#include "Spool.h"
#include "Twine.h"





Spool::Spool() {
	spool = new Twine*[0];
	count = 0;
}

Spool::~Spool() {
	delete[] spool;
}

