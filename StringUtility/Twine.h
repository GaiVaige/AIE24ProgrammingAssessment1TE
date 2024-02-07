#pragma once
#ifndef CUSTOM_TWINE_HEADER
#define CUSTOM_TWINE_HEADER

#include <iostream>



	class Twine {


	public:
		char* twine;


	public:

		//constructors and destructors
		Twine();
		Twine(const char* c);
		Twine(char* c);
		~Twine();

		//get input from std::cin
		void GetTwine();

		//set a Twine objects char* to a new char*
		void SetTwine(char* c);
		void SetTwine(const char* c);
		
		//std::cout functions
		const char* TStr();
		void DisplayTwine();

		//length functions for general and length-whitespace
		int Length();
		int Length(char* c);
		static int Length(const char* c);
		int LengthNoSpace();
		int LengthNoSpace(char* c);
		int LengthNoSpace(const char* c);

		//two copies, one is 'quick' and overwties the char* twine on the
		//Twine object that clals it, the other can be called seperatley to
		//an object
		void Copy(char* newTextTwine);
		static void Copy(Twine &twineA, Twine &twineB);


		//search functions.
		//CharAt returns the char at the given index
		//CharFind returns the first index of the requested char.
		//TFind returns the index of the requested SubTwine in the Twin
		//TFind OL 1 returns the index of SubTwine start point sIn, and distance from sIn
		char CharAt(int i);
		int CharFind(char c);
		/// <summary>
		/// 
		/// </summary>
		/// <param name="c"></param>
		/// <returns>integer to represent the index where the substring is found</returns>
		int TFind(char* c);
		int TFind(const char* c);
		int TFind(char* c, int sIn);
		int TFind(const char* c, int sIn);
		int TFindOnly(char* c);
		bool TFindOnly(const char* c);
		int TFindOnly(char* c, int sIn);
		int TFindOnly(const char* c, int sIn);

		//Shifts all chars in Twine to lowercase and returns it as a NEW twine object
		Twine ToLower();
		Twine ToLower(char* c);
		Twine ToLower(const char* c);
		//Shifts all chars in Twine to uppercase and returns it as a NEW twine object
		Twine ToUpper();
		Twine ToUpper(char* c);
		Twine ToUpper(const char* c);
		//Wobbles, it is destructive. It will overwrite the existing string.
		void Wobble();

		//Compares two strings to see if they are the same
		bool Compare(char* c);
		bool Compare(Twine& c);


		//Inserts char* newC at index insertIndex of twine
		void Insert(char* c, int insertIndex);
		void Insert(const char* c, int insertIndex);

		//erases number of chars delInt starting at startIndex, then resizes array
		void Erase(int delInt, int startIndex);

		//replaces instance of const char* current in char* sC with const char* newc and resizes the array
		void Replace(const char* current, const char* newc);

		//adds char* c to the end of char* curC
		void Append(char* c);
		void Append(const char* c);

		//adds char* c to the start of char* curC
		void Prepend(char* c);
		void Prepend(const char* c);

		//OPERATORS

		friend std::ostream& operator << (std::ostream& out, Twine& t);
		friend std::istream& operator >> (std::istream& in, Twine& t);
		Twine& operator = (Twine& t);
		bool operator == (Twine& t);
		Twine& operator += (Twine& t);
		Twine& operator + (Twine& t);
		char operator [] (int n);
		bool operator < (Twine& t);
		bool operator > (Twine& t);


	};






#endif // !
