
#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

enum colorFruit { brown, green, orange, red, yellow };
enum typeFruit { annual, perennial, tropical };

struct Fruit
{
	char *name;  
	colorFruit color;   
	typeFruit type;

void initFruit(char *Name, colorFruit Color, typeFruit Type )
	{
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
		color = Color;
		type = Type;
	}
};

void addFruitToArr(Fruit *arr, Fruit fruit, int &sizeArrFruits)
{
	arr[sizeArrFruits] = fruit;
	sizeArrFruits++;
} 

bool compareTwoWords(char *FirstWord, char *SecondWord, int index)
{
	if (FirstWord[index] > SecondWord[index]) return true;

	if (FirstWord[index] < SecondWord[index]) return false;

	return compareTwoWords(FirstWord, SecondWord, index + 1);
}

void sortWords(Fruit *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			int index = 0;
			char temp[100];

			if (arr[i].name[index]>arr[j].name[index])
			{
				strcpy_s(temp, arr[i].name);
				strcpy_s(arr[i].name,strlen(arr[j].name) + 1, arr[j].name);
				strcpy_s(arr[j].name, strlen(temp) + 1, temp);
			}

			if (arr[i].name[index] == arr[j].name[index])
			{
				if (compareTwoWords(arr[i].name, arr[j].name, index + 1))
				{
					strcpy_s(temp, arr[i].name);
					strcpy_s(arr[i].name, strlen(arr[j].name) + 1, arr[j].name);
					strcpy_s(arr[j].name, strlen(temp) + 1, temp);
				}
			}
		}
	}
}

void printSortWords(Fruit *arrFruits, int sizeArrFruits)
{
	cout << "Fruits sorted by name: " << endl << endl;

	for (int i = 0; i < sizeArrFruits; i++)
	{
		cout << arrFruits[i].name << endl;
	}
}

colorFruit EnumOfIndex(int i) { return static_cast<colorFruit>(i); }

void sortByColor(Fruit *arr, Fruit *sortByCol,int sizeArrFruits)
{
	int index = 0;
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < sizeArrFruits; j++)
		{
			if (arr[j].color == EnumOfIndex(i))
			{
				sortByCol[index] = arr[j];
				index++;
			}
		}
	}
}

void printSortByColor(Fruit *sortByCol, int sizeArrFruits)
{
	cout << "Fruits sorted by color: " << endl << endl;

	for (int i = 0; i < sizeArrFruits; i++)
	{
		cout << sortByCol[i].name << " - " << sortByCol[i].color << endl;
	}
}

typeFruit EnumOfIndexx(int i) { return static_cast<typeFruit>(i); }

void sortByType(Fruit *arr, Fruit *sortByCol, int sizeArrFruits)
{
	int index = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < sizeArrFruits; j++)
		{
			if (arr[j].type == EnumOfIndex(i))
			{
				sortByCol[index] = arr[j];
				index++;
			}
		}
	}
}

void printSortByType(Fruit *sortByTyp, int sizeArrFruits)
{
	cout << "Fruits sorted by type: " << endl << endl;

	for (int i = 0; i < sizeArrFruits; i++)
	{
		cout << sortByTyp[i].name << " - " << sortByTyp[i].type << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Fruit banana, peach, strawberry, apple, lemon, grape;

	banana.initFruit("Banana", yellow, tropical);
	apple.initFruit("Apple", red, perennial);
	strawberry.initFruit("Strawberry", red, annual);
	peach.initFruit("Peach", orange, perennial);
	lemon.initFruit("Lemon", yellow, tropical);
	grape.initFruit("Grape", green, annual);


	Fruit arrFruits[20];
	Fruit emptyArr[20];
	Fruit testEmptyArr[20];

	int sizeArrFruits = 0;

	addFruitToArr(arrFruits, banana, sizeArrFruits);
	addFruitToArr(arrFruits, apple, sizeArrFruits);
	addFruitToArr(arrFruits, strawberry, sizeArrFruits);
	addFruitToArr(arrFruits, peach, sizeArrFruits);
	addFruitToArr(arrFruits, lemon, sizeArrFruits);
	addFruitToArr(arrFruits, grape, sizeArrFruits);

	

	sortWords(arrFruits, sizeArrFruits);
	printSortWords(arrFruits, sizeArrFruits);

	sortByColor(arrFruits, emptyArr, sizeArrFruits);
	printSortByColor(emptyArr, sizeArrFruits);

	sortByType(arrFruits, testEmptyArr, sizeArrFruits);
	printSortByType(testEmptyArr, 4);
	

	//delete[] Banana.name;

	return 0;
}

