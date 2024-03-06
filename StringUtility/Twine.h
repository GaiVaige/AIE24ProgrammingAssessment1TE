#pragma once
#ifndef CUSTOM_TWINE_HEADER
#define CUSTOM_TWINE_HEADER

#include <iostream>


	class Twine {
	public:
		//BELOW ARE THE ASSESSED FUNCTIONS:
		// 
		//constructors and destructors
		Twine();
		Twine(const char* c);
		Twine(const Twine& c);
		~Twine();

		//set a Twine objects char* to a new char*
		void SetTwine(const Twine& c);
		void SetTwine(const char* c);

		//two copies, one is 'quick' and overwties the char* twine on the
		//Twine object that clals it, the other can be called seperatley to
		//an object
		void Copy(const Twine& newTextTwine);
		static void Copy(Twine& twineA, const Twine& twineB);


		//get input from std::cin
		void GetTwine();

		//std::cout functions
		const char* TStr() const;
		void DisplayTwine() const;
		
		//length functions for general and length-whitespace
		size_t Length() const;
		static size_t Length(const char* c);

		//search functions.
		//CharAt returns the char at the given index
		//CharFind returns the first index of the requested char.
		//TFind returns the index of the requested SubTwine in the Twin
		//TFind OL 1 returns the index of SubTwine start point sIn, and distance from sIn
		char CharAt(int i) const;
		size_t CharFind(char c) const;
		size_t Find(const Twine& c) const;
		size_t Find(const Twine& c, int sIn) const;

		//Shifts all chars in Twine to lowercase and returns it as a NEW twine object
		Twine ToLower() const;

		//Shifts all chars in Twine to uppercase and returns it as a NEW twine object
		Twine ToUpper() const;

		//Compares two strings to see if they are the same
		bool EqualTo(const Twine& c) const;
		bool EqualTo(const char* c) const;

		//replaces instance of const char* current in char* sC with const char* newc and resizes the array
		void Replace(const Twine& current, const Twine& newc);
		void Replace(const char* current, const char* newc);

		//adds char* c to the start of char* curC
		void Prepend(const Twine& c);
		void Prepend(const char* c);

		//adds char* c to the end of char* curC
		void Append(const Twine& c);
		void Append(const char* c);

		//OPERATORS

		friend std::ostream& operator << (std::ostream& out, Twine& t);
		friend std::istream& operator >> (std::istream& in, Twine& t);
		Twine& operator = (const char* c);
		Twine& operator = (Twine& t);
		bool operator == (const char* c) const;
		bool operator == (const Twine& t) const;
		bool operator != (const char* c) const;
		bool operator != (const Twine& t) const;
		Twine& operator += (Twine& t);
		Twine operator + (Twine& t);
		char& operator [] (int n);
		const char& operator [] (int n) const;
		bool operator < (const Twine& t) const;
		bool operator > (const Twine& t) const;


	public:
		//Below here are my utility functions for the text adventure/functions I made for fun!
		size_t LengthNoSpace() const;

		size_t ParseForInt();

		bool FindExclusive(Twine& c);
		bool FindExclusive(const char* c);
		bool FindExclusive(Twine& c, int sIn);
		bool FindExclusive(const char* c, int sIn);
		bool FindInSpool(Twine tAr[], int size);

		Twine Capital();

		//Wobbles, it is destructive. It will overwrite the existing string.
		void Wobble();


		//Inserts char* newC at index insertIndex of twine
		void Insert(Twine& c, int insertIndex);
		void Insert(const char* c, int insertIndex);

		//erases number of chars delInt starting at startIndex, then resizes array
		void Erase(int delInt, int startIndex);




		void Caesar(int displaceVal);

		Twine& Colour(int r, int g, int b, bool fg = true);

	private:
		char* twine;


	};






#endif // !
