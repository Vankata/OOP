// labyrinth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Student
{
	char name[100];
	int fn;
	double age;
};

int main()
{
	
	Student Pesho;
	Pesho.age = 21;
	Pesho.fn = 71629;
	int x;
	cin >> x;
	char* darr = new char[x];
	delete []darr;

	

	return 0;
}
