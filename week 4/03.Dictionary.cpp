
#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

const size_t initCap = 64;

class Dictionary
{
private:
	char**bgWords;
	char**enWords;
	size_t capacity;
	size_t wordsCount;
public:
	Dictionary();
	Dictionary(const char** eWords, const char**bWords, size_t n);
	~Dictionary();

	void AddWord(const char*bg, const char* en);
	void DeleteWord(const char*word);
	void SearchWord(const char*word)const;
};

Dictionary::Dictionary()
{
	capacity = initCap;

	bgWords = new char*[capacity];
	enWords = new char*[capacity];
	wordsCount = 0;
}

Dictionary::Dictionary(const char** eWords, const char**bWords, size_t n)
{
	capacity = 2 * n;

	enWords = new char*[capacity];
	bgWords = new char*[capacity];

	for (size_t i = 0; i < n; ++i)
	{
		enWords[i] = new char[strlen(eWords[i]) + 1];
		strcpy_s(enWords[i], strlen(eWords[i]) + 1, eWords[i]);
		bgWords[i] = new char[strlen(bWords[i]) + 1];
		strcpy_s(bgWords[i], strlen(bWords[i]) + 1, bWords[i]);
	}

	wordsCount = n;
}

Dictionary::~Dictionary()
{
	for (size_t i = 0; i < wordsCount; ++i)
	{
		delete[]bgWords[i];
		delete[]enWords[i];
	}

	delete[]bgWords;
	delete[]enWords;
}

void Dictionary :: AddWord(const char*bg, const char*en)
{
	if (capacity < wordsCount)
	{
		cout << "Not enough space!!!" << endl;
		return;
	}
	
	bgWords[wordsCount] = new char[strlen(bg) + 1];
	strcpy_s(bgWords[wordsCount], strlen(bg) + 1, bg);
	enWords[wordsCount] = new char[strlen(en) + 1];
	strcpy_s(enWords[wordsCount], strlen(en) + 1, en);

	++wordsCount;
}

void Dictionary::DeleteWord(const char*word)
{
	for (size_t i = 0; i < wordsCount; i++)
	{
		if (strcmp(bgWords[i], word) == 0 || strcmp(enWords[i], word) == 0)
		{
			delete[]bgWords[i];
			delete[]enWords[i];

			for (size_t j = i; j < wordsCount - 1; j++)
			{
				bgWords[j] = bgWords[j + 1];
				enWords[j] = enWords[j + 1];
			}
			--wordsCount;
			return;
		}
	}
}

void Dictionary::SearchWord(const char*word)const 
{
	bool flag = false;

	for (size_t i = 0; i < wordsCount; i++)
	{
		if (strcmp(bgWords[i], word) == 0)
		{
			cout << "Your word is on " << i << " place and it's tranlation is " << enWords[i] << "."<< endl;
			flag = true;
			return;
		}
		else if (strcmp(enWords[i], word) == 0)
		{
			cout << "Your word is on " << i << " place and it's tranlation is " << bgWords[i] << "."<< endl;
			flag = true;
			return;
		}
	}
	
	if (!flag)
	{
		cout << "Word not found!" << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

