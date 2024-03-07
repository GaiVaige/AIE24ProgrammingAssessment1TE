#pragma once
#ifndef CUSTOM_TWINE_HEADER
#define CUSTOM_TWINE_HEADER
#include <cstddef>
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
		//void SetTwine(Twine c);
		void SetTwine(const Twine c);

		//the other can be called seperatley to
		//an object
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

		//replaces instance of const char* current in char* sC with const char* newc and resizes the array
		void Replace(const Twine& current, const Twine& newc);

		//adds char* c to the start of char* curC
		void Prepend(const Twine& c);
		void Prepend(char c);

		//adds char* c to the end of char* curC
		void Append(const Twine& c);
		void Append(char c);

		//OPERATORS

		friend std::ostream& operator << (std::ostream& out, const Twine& t);
		friend std::istream& operator >> (std::istream& in, Twine& t);
		Twine& operator = (const Twine& t);
		bool operator == (const Twine& t) const;
		bool operator != (const Twine& t) const;
		Twine& operator += (Twine& t);
		Twine operator + (Twine& t);
		char& operator [] (size_t n) const;
		bool operator < (const Twine& t) const;
		bool operator > (const Twine& t) const;


	public:
		//Below here are my utility functions for the text adventure/functions I made for fun!
		size_t LengthNoSpace() const;

		size_t ParseForInt();

		bool FindExclusive(const Twine& c);
		bool FindExclusive(const Twine& c, int sIn);

		Twine Capital();

		//Wobbles, it is destructive. It will overwrite the existing string.
		void Wobble();


		//Inserts char* newC at index insertIndex of twine
		void Insert(const Twine& c, size_t insertIndex);

		//erases number of chars delInt starting at startIndex, then resizes array
		void Erase(int delInt, size_t startIndex);
		void Caesar(int displaceVal);

		Twine& Colour(int r, int g, int b, bool fg = true);

	private:
		char* twine;


	};






#endif // !
