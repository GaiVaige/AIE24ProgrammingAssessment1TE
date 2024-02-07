#include "Twine.h"
#include <iostream>
#include <cstring>
#include <cctype>
#pragma warning (push)
#pragma warning (disable:6386)



using namespace std;



Twine::Twine() {
	//initialise an empty twine 
	twine = new char[1];
	twine[0] = '\0';
}

Twine::Twine(const char* c) {
	//set twine to entered text in ide
	this->SetTwine(c);
}

Twine::Twine(char* c) {
	//set twine to a char array
	this->SetTwine(c);
}

Twine::~Twine() {
	//destroy twine when swapped
	delete[] twine;
}

void Twine::SetTwine(char* c) {
	//confirm length of char array
	size_t l = Length(c);
	//destroy previous twine 
	Twine::~Twine();
	//copy each value in array to new array
	twine = new char[l+1];
	for (int i = 0; i < l; i++) {
			twine[i] = c[i];
	}
	twine[l] = '\0';
}

void Twine::SetTwine(const char* c) {
	//confirm length of char array
	size_t l = Length(c);
	//destroy previous twine 
	Twine::~Twine();
	//copy each value in array to new array
	twine = new char[l + 1];
	for (int i = 0; i < l; i++) {
			twine[i] = c[i];
	}
	twine[l] = '\0';
}

const char* Twine::TStr() {
	//returns twine for use with std::Cout<<
	//redundant as operator overloaded
	return this->twine;
}

void Twine::DisplayTwine() {
    //cleaner method of displaying twine
	cout << twine;
}

void Twine::GetTwine(){
	//initalise a single char to be referenced for taking in characters from input
	char c;
	//place characters immediately into input buffer
	cin.get(c);
	cin.putback(c);
	//std::cin stops when enter is pressed
	//check size of buffer when enter is pressed (cin halts at this point)
	//this is used as a reference to create the new array to ensure that nothing beyond
	//what has been inputted to cin is used
	streamsize size = cin.rdbuf()->in_avail();
	//create a pointer to a new array, newTwi, to have the data copied to from buffer, and size to buffer+1
	// to account for nullchar
	char* newTwine = new char[size + 1];
	//read an amount of characters equal to the read characters from buffer
	cin.readsome(newTwine, size);
	//failsafe to ensure that there is definitely a nullchar
	newTwine[size] = '\0';
	SetTwine(newTwine);
	//flush the memory and input stream to ensure no leakages
	delete[] newTwine;
	&std::ostream::flush;
}

int Twine::Length() {
	for (int i = 0; ; i++) {
		//if end of string detected, return value of i
		if (this->twine[i] == '\0') {
			return i;
		}
	}
}

int Twine::LengthNoSpace() {
	int y = 0;
	for (int i = 0; ; i++) {
		//only increments return value y if there is no space
		if (!isspace(this->twine[i])) {
			//if end of string detected, return current value of y
			if (this->twine[i] == '\0') {
				return y;
			}
			y++;
		}
	}
	return y;
}

int Twine::Length(char* c) {
	for (int i = 0; ; i++) {
		if (c[i] == '\0') {
			return i;
		}
	}
}

int Twine::LengthNoSpace(char* c) {
	int i = 0;
	for (int y = 0; ; y++){
		if (!isspace(c[i])) {
			if (c[i] == '\0') {
				return i;
			}
			i++;
		}
	}
}

int Twine::Length(const char* c) {
	for (int i = 0; ; i++) {
		if (c[i] == '\0') {
			return i;
		}
	}
}

int Twine::LengthNoSpace(const char* c) {
	int i = 0;
	for (int y = 0; ; y++) {
		if (!isspace(c[i])) {
			if (c[i] == '\0') {
				return i;
			}
			i++;
		}
	}
}

void Twine::Copy(char* newTextTwine) {
	this->SetTwine(newTextTwine);
}

void Twine::Copy(Twine& twineA, Twine& twineB) {
	twineA.SetTwine(twineB.twine);
}

char Twine::CharAt(int i) {
	if (this->twine[i] == '\0' || i > this->Length() || i < 0) {
		return '\0';
	}
	else {
		return this->twine[i];
	}
}

int Twine::CharFind(char c) {
	
	for (int i = 0; i < this->Length(); i++) {

		if (this->twine[i] == c) {
			return i;

		}

	}
	return -1;
}

int Twine::TFind(char* c) {

	int a = this->Length();
	int b = Length(c);
	int cL = 0;
	int t = 0;
	bool doSwap = true;

	for (int i = 0; i < a; i++) {

		if (this->twine[i] == c[cL]) {
			cL++;
			if (t == 0 && doSwap) {
				t = i;
				doSwap = false;
			}

			if (cL == b) {
				return t;
			}


		}
		else {
			t = 0;
			cL = 0;
			doSwap = true;
		}

	}
	t = -1;
	return t;

}

int Twine::TFind(const char* c) {

	int a = this->Length();
	int b = Length(c);
	int cL = 0;
	int t = 0;
	bool doSwap = true;

	for (int i = 0; i < a; i++) {

		if (this->twine[i] == c[cL]) {
			cL++;
			
			
			if (t == 0 && doSwap) {
				t = i;
				doSwap = false;
			}

			if (cL == b) {
				return t;
			}



		}
		else {
			t = 0;
			cL = 0;
			doSwap = true;
		}

	}
	t = -1;
	return t;

}

int Twine::TFind(char* c, int sIn) {

	int a = this->Length();
	int b = Length(c);
	int cL = 0;
	int t = 0;
	bool doSwap = true;

	for (int i = sIn; i < a; i++) {

		if (this->twine[i] == c[cL]) {
			cL++;
			if (t == 0 && doSwap) {
				t = i;
				doSwap = false;
			}


			if (cL == b) {
				return t;
			}

		}
		else {
			t = 0;
			cL = 0;
			doSwap = true;
		}

	}
	t = -1;
	return t;
}

int Twine::TFind(const char* c, int sIn){

	int a = this->Length();
	int b = Length(c);
	int cL = 0;
	int t = 0;
	bool doSwap = true;

	for (int i = sIn; i < a; i++) {

		if (this->twine[i] == c[cL]) {
			cL++;
			if (t == 0 && doSwap) {
				t = i;
				doSwap = false;
			}


			if (cL == b) {

				return t;
			}

		}
		else {
			t = 0;
			cL = 0;
			doSwap = true;
		}

	}
	t = -1;
	return t;

}

bool Twine::TFindOnly(char* c) {

	int curLen = this->Length();
	int checkLen = Length(c);
	int searchIndex = 0;
	int previousWordSpot = 0;

	for (int i = 0; i < curLen + 1; i++) {

		if (isspace(this->twine[i]) || this->twine[i] == '\0') {
			int wordGap = i - previousWordSpot;
			previousWordSpot = i + 1;
			//cout << "Word length is: " << wordGap << '\n';


			if (wordGap != checkLen) {
				//cout << "Word length didn't match" << '\n';
			}
			else {
				searchIndex = i - wordGap;
				for (int x = 0; x < checkLen; x++) {
					if (this->twine[searchIndex] == c[x]) {
						//cout << this->twine[searchIndex] << " & " << c[x] << " are the same!!" << '\n';
					}
					else {
						//cout << this->twine[searchIndex] << " & " << c[x] << " are NOT the same!!" << '\n';
						break;
					}
					searchIndex++;
				}
				if (searchIndex == i) {
					return true;
				}
			}
		}

	}

	return false;

}

bool Twine::TFindOnly(const char* c) {

	int curLen = this->Length();
	int checkLen = Length(c);
	int searchIndex = 0;
	int previousWordSpot = 0;

	for (int i = 0; i < curLen+1; i++) {

		if (isspace(this->twine[i]) || this->twine[i] == '\0') {
			int wordGap = i - previousWordSpot;
			previousWordSpot = i + 1;
			//cout << "Word length is: " << wordGap << '\n';


			if (wordGap != checkLen) {
				//cout << "Word length didn't match" << '\n';
			}
			else{
				searchIndex = i - wordGap;
				for (int x = 0; x < checkLen; x++) {
					if (this->twine[searchIndex] == c[x]) {
						//cout << this->twine[searchIndex] << " & " << c[x] << " are the same!!" << '\n';
					}
					else {
						//cout << this->twine[searchIndex] << " & " << c[x] << " are NOT the same!!" << '\n';
						break;
					}
					searchIndex++;
				}
				if (searchIndex == i) {
					return true;
				}
			}
		}

	}

	return false;

}

bool Twine::TFindOnly(char* c, int sIn) {

	int curLen = this->Length();
	int checkLen = Length(c);
	int searchIndex = 0;
	int previousWordSpot = 0;

	for (int i = sIn; i < curLen + 1; i++) {

		if (isspace(this->twine[i]) || this->twine[i] == '\0') {
			int wordGap = i - previousWordSpot;
			previousWordSpot = i + 1;
			//cout << "Word length is: " << wordGap << '\n';


			if (wordGap != checkLen) {
				//cout << "Word length didn't match" << '\n';
			}
			else {
				searchIndex = i - wordGap;
				for (int x = 0; x < checkLen; x++) {
					if (this->twine[searchIndex] == c[x]) {
						//cout << this->twine[searchIndex] << " & " << c[x] << " are the same!!" << '\n';
					}
					else {
						//cout << this->twine[searchIndex] << " & " << c[x] << " are NOT the same!!" << '\n';
						break;
					}
					searchIndex++;
				}
				if (searchIndex == i) {
					return true;
				}
			}
		}

	}

	return false;
}

bool Twine::TFindOnly(const char* c, int sIn) {

	int curLen = this->Length();
	int checkLen = Length(c);
	int searchIndex = 0;
	int previousWordSpot = 0;

	for (int i = sIn; i < curLen + 1; i++) {

		if (isspace(this->twine[i]) || this->twine[i] == '\0') {
			int wordGap = i - previousWordSpot;
			previousWordSpot = i + 1;
			//cout << "Word length is: " << wordGap << '\n';


			if (wordGap != checkLen) {
				//cout << "Word length didn't match" << '\n';
			}
			else {
				searchIndex = i - wordGap;
				for (int x = 0; x < checkLen; x++) {
					if (this->twine[searchIndex] == c[x]) {
						//cout << this->twine[searchIndex] << " & " << c[x] << " are the same!!" << '\n';
					}
					else {
						//cout << this->twine[searchIndex] << " & " << c[x] << " are NOT the same!!" << '\n';
						break;
					}
					searchIndex++;
				}
				if (searchIndex == i) {
					return true;
				}
			}
		}

	}

	return false;

}

bool Twine::FindInSpool(Twine tAr[], int size) {

	for (int i = 0; i < size; i++) {

		if (this->TFindOnly(tAr[i].twine)) {
			return true;
		}
	}
	return false;
}

Twine Twine::ToLower() {

	size_t l = Length(this->twine);
	Twine newT;
	char* newArr = new char[l + 1];

	for (int i = 0; i < l; i++) {


		newArr[i] = tolower(this->twine[i]);


	}
	newArr[l] = '\0';

	newT.SetTwine(newArr);
	delete[] newArr;
	return newT;
}

Twine Twine::ToLower(char* c) {

	size_t l = Length(c);
	Twine newT;
	char* newArr = new char[l + 1];

	for (int i = 0; i < l; i++) {


		newArr[i] = tolower(c[i]);


	}
	newArr[l] = '\0';

	newT.SetTwine(newArr);
	delete[] newArr;
	return newT;
	
}

Twine Twine::ToLower(const char* c) {

	size_t l = Length(c);
	Twine newT;
	char* newArr = new char[l + 1];

	for (int i = 0; i < l; i++) {


		newArr[i] = tolower(c[i]);


	}
	newArr[l] = '\0';

	newT.SetTwine(newArr);
	delete[] newArr;
	return newT;
}

Twine Twine::ToUpper() {


	size_t l = Length(this->twine);
	Twine newT;
	char* newArr = new char[l + 1];

	for (int i = 0; i < l; i++) {


		newArr[i] = toupper(this->twine[i]);


	}
	newArr[l] = '\0';

	newT.SetTwine(newArr);
	delete[] newArr;
	return newT;
}
	  
Twine Twine::ToUpper(char* c) {

	return this->ToUpper((const char*)c);

	size_t l = Length(c);
	Twine newT;
	char* newArr = new char[l + 1];

	for (int i = 0; i < l; i++) {


		newArr[i] = toupper(c[i]);


	}
	newArr[l] = '\0';

	newT.SetTwine(newArr);
	delete[] newArr;
	return newT;

}
	  
Twine Twine::ToUpper(const char* c) {

	size_t l = Length(c);
	Twine newT;
	char* newArr = new char[l + 1];

	for (int i = 0; i < l; i++) {


		newArr[i] = toupper(c[i]);


	}
	newArr[l] = '\0';

	newT.SetTwine(newArr);
	delete[] newArr;
	return newT;
}

void Twine::Wobble() {

	size_t l = Length(this->twine);

	for (int i = 0; i < l; i++) {


		if (isspace(this->twine[i])) {
			i++;
		}

		if (!isspace(this->twine[i])) {
			this->twine[i] = tolower(this->twine[i]);
			i++;

		}

		if (isspace(this->twine[i])) {
			i++;
		}

		if (!isspace(this->twine[i])) {
			this->twine[i] = toupper(this->twine[i]);
		}



	}

}

bool Twine::Compare(char* c) {


	int i = this->Length();
	int cI = Length(c);

	if (i == cI) {


		for (int a = 0; a < i; a++) {

			if (this->twine[a] == c[a]) {

				a++;
			}
			else {
				return false;
			}

		}
		return true;
	}
	else {
		return false;
	}

}

bool Twine::Compare(Twine& c) {


	int i = this->Length();
	int cI = c.Length();


	if (i == cI) {


		for (int a = 0; a < i; a++) {

			if (this->twine[a] == c.twine[a]) {

				a++;
			}
			else {
				return false;
			}

		}
		return true;
	}
	else {
		return false;
	}
}

void Twine::Insert(char* c, int insertIndex) {

	int curLen = this->Length();
	int newLen = Length(c);
	int newSize = curLen + newLen;


	int i = 0; //tracker for for loops
	int inserti = 0;
	int finalTracker = 0;


	char* newTwine = new char[newSize + 1];

	for (i; i < insertIndex; i++) {
		newTwine[i] = this->twine[i];
	}
	finalTracker = i;

	for (i;i < insertIndex + newLen;i++) {
		newTwine[i] = c[inserti];
		inserti++;
	}

	for (i;i < Length(newTwine);i++) {
		newTwine[i] = this->twine[finalTracker];
		finalTracker++;
	}

	this->SetTwine(newTwine);
	delete[] newTwine;
}

void Twine::Insert(const char* c, int insertIndex) {

	int curLen = this->Length();
	int newLen = Length(c);
	int newSize = curLen + newLen;


	int i = 0; //tracker for for loops
	int inserti = 0;
	int finalTracker = 0;


	char* newTwine = new char[newSize + 1];

	for (i; i < insertIndex; i++) {
		newTwine[i] = this->twine[i];
	}
	finalTracker = i;

	for (i;i < insertIndex + newLen;i++) {
		newTwine[i] = c[inserti];
		inserti++;
	}

	for (i;i < Length(newTwine);i++) {
		newTwine[i] = this->twine[finalTracker];
		finalTracker++;
	}

	this->SetTwine(newTwine);
	delete[] newTwine;
}

void Twine::Erase(int delInt, int startIndex) {


	startIndex--;

	if (startIndex < 0) {
		startIndex = 0;
	}
	int newsize = this->Length() - delInt;
	char* newTwine = new char[newsize + 1];

	int i = 0; //tracker for for loops

	for (i; i < startIndex;i++) {
		newTwine[i] = this->twine[i];
	}

	for (i;i < Length(newTwine);i++) {
		newTwine[i] = this->twine[i + delInt];
	}

	newTwine[newsize] = '\0';
	this->SetTwine(newTwine);
	delete[] newTwine;

}

void Twine::Replace(const char* current, const char* newc) {


	int replaceStringPos = this->TFind(current);

	if (replaceStringPos == -1) {
		cout << "No replacements found for " << current << ", check your spelling!" << '\n';

	}


	while (replaceStringPos != -1) {

	    int curLen = Length(this->twine);
	    int replaceStringLen = Length(current);
	    int newStringLen = Length(newc);
	    int i = 0;
	    int returnStringLen = (newStringLen - replaceStringLen) + curLen;
	    char* newT = new char[returnStringLen + 1];
	    
	    
	    int newCTracker = 0;
	    int finalTracker = 0;
		int checkTrack = 0;


			for (i; i < replaceStringPos; i++) {

				newT[i] = this->twine[i];
			}



		for (i; i < replaceStringPos + newStringLen; i++) {

			newT[i] = newc[newCTracker];
			newCTracker++;
			checkTrack = i;
		}
		
		for (; i < Length(newT); i++) {

			int j = replaceStringPos + replaceStringLen + finalTracker;
			newT[i] = this->twine[j];
			finalTracker++;
		}

		this->SetTwine(newT);
		replaceStringPos = this->TFind(current, checkTrack);
		delete[] newT;

		
	}





}

void Twine::Append(char* c) {

	int curCSize = this->Length();
	int cSize = Length(c);
	int newSize = cSize + curCSize;
	char* newC = new char[newSize + 1];

	for (int i = 0; i < curCSize; i++) {

		newC[i] = this->twine[i];

	}

	for (int i = 0; i < cSize; i++) {

		newC[curCSize + i] = c[i];

	}
	newC[newSize] = '\0';
	this->SetTwine(newC);
	delete[] newC;

}

void Twine::Append(const char* c) {

	int curCSize = this->Length();
	int cSize = Length(c);
	int newSize = cSize + curCSize;
	char* newC = new char[newSize + 1];

	for (int i = 0; i < curCSize; i++) {

		newC[i] = this->twine[i];

	}

	for (int i = 0; i < cSize; i++) {

		newC[curCSize + i] = c[i];

	}
	newC[newSize] = '\0';
	this->SetTwine(newC);
	delete[] newC;

}

void Twine::Prepend(char* c) {

	int curCSize = this->Length();
	int cSize = Length(c);
	int newSize = cSize + curCSize;
	char* newC = new char[newSize + 1];

	for (int i = 0; i < cSize; i++) {

		newC[i] = c[i];

	}

	for (int i = 0; i < curCSize; i++) {

		newC[cSize + i] = this->twine[i];

	}


	newC[newSize] = '\0';
	this->SetTwine(newC);
	delete[] newC;

}
			
void Twine::Prepend(const char* c) {

	int curCSize = this->Length();
	int cSize = Length(c);
	int newSize = cSize + curCSize;
	char* newC = new char[newSize + 1];

	for (int i = 0; i < cSize; i++) {

		newC[i] = c[i];

	}

	for (int i = 0; i < curCSize; i++) {

		newC[cSize + i] = this->twine[i];

	}
	newC[newSize] = '\0';
	this->SetTwine(newC);
	delete[] newC;

}		

std::ostream &operator << (ostream &out, Twine &t) {

	int i = 0;
	char* c = t.twine;

	for (;c[i] != '\0';i++) {
		out << c[i];
	}
	return out;

}

std::istream& operator >> (std::istream& in, Twine& t) {

	t.GetTwine();

	return in;

}

Twine& Twine::operator = (const char* c) {

	if (this->twine == c) {
		return *this;
	}

	this->SetTwine(c);

	return *this;
}

Twine& Twine::operator = (Twine& t1) {

	if (this == &t1) {
		return *this;
	}

	this->SetTwine(t1.twine);

	return *this;
}

bool Twine::operator == (Twine& t) {

	if (this->Compare(t)) {
		return true;
	}
	else {
		return false;
	}


}

Twine& Twine::operator += (Twine& t) {

	if (this == &t) {
		return *this;
	}

	this->Append(t.twine);
	return *this;

}

Twine& Twine::operator + (Twine& t) {

	Twine* tw = new Twine;
	char* newTwine = new char[this->Length() + 1];
	newTwine = this->twine;
	tw->SetTwine(newTwine);
	tw->Append(t.twine);

	

	return *tw;

}

char Twine::operator [] (int i) {

	return this->CharAt(i);

}

bool Twine::operator < (Twine& t) {

	this->ToLower();
	t.ToLower();

	char cA = this->twine[0];
	char cB = t.twine[0];

	for (int i = 0; ; i++) {

		char cA = this->twine[i];
		char cB = t.twine[i];
		cout << cA << '\n';
		cout << cB << '\n';




		if (isspace(cA)) {
			return true;
		}
		else if (isspace(cB)) {
			return false;
		}
		else if (cA < cB) {

			if (this->twine[i+1] == '\0') {

				return true;
			}
			else if (t.twine[i + 1] == '\0') {

				return false;
			}

			return true;
		}
		else if (cB < cA) {

			if (this->twine[i + 1] == '\0') {

				return true;
			}
			else if (t.twine[i + 1] == '\0') {

				return false;
			}
			return false;
		}


	}
}

bool Twine::operator > (Twine& t) {

	this->ToLower();
	t.ToLower();

	char cA = this->twine[0];
	char cB = t.twine[0];

	for (int i = 0; ; i++) {

		char cA = this->twine[i];
		char cB = t.twine[i];

		if (isspace(cA)) {
			return false;
		}
		else if (isspace(cB)) {
			return true;
		}
		else if (cA < cB) {

			if (this->twine[i + 1] == '\0') {

				return false;
			}
			else if (t.twine[i + 1] == '\0') {

				return true;
			}

			return false;
		}
		else if (cB < cA) {

			if (this->twine[i + 1] == '\0') {

				return false;
			}
			else if (t.twine[i + 1] == '\0') {

				return true;
			}
			return true;
		}


	}

#pragma warning (pop)
}


