#define _CRT_SECURE_NO_WARNINGS
#include "diction.h"
#include <string.h>
#include <iostream>
using namespace std;

Dictionary::Dictionary(int n)
{
	nWords = 0;
	maxWords = n;
	words = new Definition[n];
}

long Dictionary::FindWord(const char* s)
{
	for (int i = 0; i < nWords; i++) {
		if (strcmp(words[i].GetWord(), s) == 0) {
			return i;
		}
	}
	return -1;
}

void Dictionary::AddWord(Definition& word)
{
	if (nWords >= maxWords) return;

	words[nWords] = word;
	++nWords;
}

// def point to MAXMEANS elements of char* array
int Dictionary::GetDef(char* word, char* def[])
{
	int nM = 0;
	int wordIdx = FindWord(word);
	if (wordIdx != -1) {// ур╣╫ак
		nM = words[wordIdx].GetnMeans();
		for (int i = 0; i < nM; i++) {
			char* pMeaning = words[wordIdx].GetMeaning(i);
			int length = strlen(pMeaning);
			delete def[i];
			def[i] = new char[length + 1];
			strcpy(def[i], pMeaning);
		}
	}
	delete def[nM];
	def[nM] = NULL;
	return nM;
}

void Dictionary::Print(const char* w)
{
	int wordIdx = FindWord(w);
	if (wordIdx != -1) {
		words[wordIdx].Print();
	} else {
		cout << "couldn't find the word" << w << endl;
	}
}

Dictionary::~Dictionary()
{
	delete[] words;
}
