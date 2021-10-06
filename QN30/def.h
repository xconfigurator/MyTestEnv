#pragma once
const int MAXMEANS = 10;

class Definition {
public:
	Definition() {}
	Definition(const char* word, const char* def[]);
	Definition& operator = (Definition& def);
	void PutWord(char* s);
	char* GetWord() { return word; }
	void AddMeaning(char* s);
	char* GetMeaning(int level);
	int GetnMeans() { return nMeanings; }
	void Print();
	~Definition();
private:
	char* word;
	char* meanings[MAXMEANS];
	int nMeanings;
};