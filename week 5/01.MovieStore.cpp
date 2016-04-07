#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

class Movie
{
private:
	char*name;
	char*author;
	int price;

public:
	Movie();
	~Movie();
	Movie(char*name, char*author, int price);

	char*getName()const;
	char*getAuthor()const;
	int getPrice()const;
	void setPrice(int price);
};

Movie::Movie()
{
	char*name = NULL;
	char*author = NULL;
	price = 0;
}

Movie::~Movie()
{
	if (this->name != NULL)
	{
		delete[]this->name;
	}
	if (this->author != NULL)
	{
		delete[]this->author;
	}
}

Movie::Movie(char*name, char*author, int price)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);

	this->price = price;
}

char*Movie::getName()const
{
	return this->name;
}

char*Movie::getAuthor()const
{
	return this->author;
}

int Movie::getPrice()const
{
	return this->price;
}

void Movie::setPrice(int price)
{
	this->price = price;
}


class MovieStore
{
private:
	Movie*movies;
	int budget;
	int capMovies;
	int sizeMovies;

public:
	MovieStore();
	~MovieStore();
	MovieStore(int budget);
	MovieStore(Movie*movies, int budget, int sizeMovies, int capMovies);
	void resize(size_t newSize);

	Movie*getMovies()const;
	int getBudget()const;
};

MovieStore::MovieStore()
{
	this->movies = NULL;
	this->budget = 0;
	this->capMovies = 128;
	this->sizeMovies = 0;
}

MovieStore::~MovieStore()
{
	if (this->movies != NULL)
	{
		delete[]this->movies;
	}
}

MovieStore::MovieStore(Movie*movies, int budget, int sizeMovies, int capMovies)
{

}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

