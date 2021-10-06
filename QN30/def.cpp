#define _CRT_SECURE_NO_WARNINGS
#include "def.h"
#include <string.h>
#include <iostream>
using namespace std;

Definition::Definition(const char* word, const char* def[])
{
	int n = strlen(word) + 1;
	this->word = new char[n];
	strcpy(this->word, word);
	nMeanings = 0;
	for (; def[nMeanings] && nMeanings != MAXMEANS; nMeanings ++) {
		meanings[nMeanings] = new char[strlen(def[nMeanings]) + 1];
		strcpy(meanings[nMeanings], def[nMeanings]);
	}
}

Definition& Definition::operator=(Definition& def)
{
	// word
	word = new char[strlen(def.word) + 1];
	strcpy(word, def.word);
	// nMeanings
	nMeanings = def.nMeanings;
	// meanings
	for (int i = 0; i < nMeanings; i++) {
		meanings[i] = new char[strlen(def.meanings[i]) + 1];
		strcpy(meanings[i], def.meanings[i]);
	}
	return *this;
}

void Definition::PutWord(char* s)
{
	word = new char[strlen(s) + 1];
	strcpy(word, s);
	nMeanings = 0;
}

void Definition::AddMeaning(char* s)
{
	if (nMeanings >= MAXMEANS) return;

	meanings[nMeanings] = new char[strlen(s) + 1];
	strcpy(meanings[nMeanings++], s);
}

char* Definition::GetMeaning(int level)
{
	if (0 <= level && level < nMeanings) {
		return meanings[level];
	} else {
		return nullptr;
	}
}

void Definition::Print()
{
	cout << endl << word << ":" << endl;
	for (int i = 0; i < nMeanings; i++) {
		cout << " " << meanings[i] << endl;
	}
}

Definition::~Definition()
{
	delete[] word;
	for (int i = 0; i < nMeanings; i++) {
		delete[] meanings[i];
	}
	// liuyang问题：光这样行么？
}

