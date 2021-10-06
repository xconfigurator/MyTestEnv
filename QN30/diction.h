#pragma once
#include "def.h"
class Dictionary {
public:
	Dictionary(int n = 100);
	long FindWord(const char* s);
	void AddWord(Definition& word);
	int GetDef(char* word, char* def[]);
	void Print(const char*);
	~Dictionary();
private:
	long nWords;
	long maxWords;
	Definition* words;
};