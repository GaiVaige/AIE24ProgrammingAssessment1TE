#include "Spool.h"
#include "Twine.h"





Spool::Spool() {
	spool = new Twine*[0];
	count = 0;
}

Spool::~Spool() {
	for (int i = 0; i < count; i++) {
		delete spool[i];
	}
	delete[] spool;
}

Spool::Spool(int twCo, Twine* twAr) {
	spool = new Twine*[twCo];
	for (int i = 0; i < twCo; i++) {
		spool[i] = new Twine(twAr[i]);
	}
	count = twCo;
}

void Spool::Add(Twine& t) {
	Twine** tempSp = new Twine*[count + 1];
	for (int i = 0; i < count; i++) {
		tempSp[i] = spool[i];
	}
	tempSp[count] = new Twine(t);
	count += 1;
	delete[] spool;
	spool = tempSp;
	delete[] tempSp;
}

Twine Spool::GetAt(int index) {
	if (index < count && index >= 0) {
		return *spool[index];
	}
	else if (index > count) {
		return *spool[count - 1];
	}
	else {
		return *spool[0];
	}
}


