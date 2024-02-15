#pragma once
#ifndef SPOOL_H
#define SPOOL_H
#include "Twine.h"



class Spool {
public:
	Spool();
	~Spool();
	
	Spool(int twCo, Twine* tw);

	void Add(Twine& t);

	Twine GetAt(int index);

private:
	Twine** spool;
	int count;





};






#endif // !SPOOL_H
