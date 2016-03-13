
#include "stdafx.h"
#include "iostream"
#include <cstring>

using namespace std;

struct Destination
{
	char city[100];   
	int kilometers; 
};

void readDestination()
{
	Destination dest;
	char city[32];
	cout << "Enter the name of the city: ";
	cin >> city;
	strcpy_s(dest.city, city);
	int distance;
	cout << "Enter distance from the city to Sofia: ";
	cin >> distance;
	dest.kilometers = distance;
}

void initDestination(Destination &dest,char* city, int kilometers)
{
	strcpy_s(dest.city,city);
	dest.kilometers = kilometers;
	cout << dest.city << endl;
	cout << dest.kilometers << endl;
}

//да се напише оператор за цикъл, който инициализира масива,
//дефиниран в предишната точка чрез нулевите за съответните
//типове на поветата на Destination стойности
void initArray(Destination *arr)
{
	for (int i = 0; i < 30; i++)
	{
		*arr[i].city = NULL;
		arr[i].kilometers = 0;
	}
}

//да се дефинира масив от 5 структури Destination и се инициализира чрез следните данни

void initFiveDest(Destination *secArr)
{
	Destination fisrtDest, secondDest, thirdDest, forthDest, fifthDest;

	char Varna[32] = "Varna";
	char Plovdiv[32] = "Plovdiv";
	char Burgas[32] = "Burgas";
	char Vidin[32] = "Vidin";
	char Dobrich[32] = "Dobrich";

	initDestination(fisrtDest, Varna, 469);
	initDestination(secondDest, Plovdiv, 165);
	initDestination(thirdDest, Burgas, 393);
	initDestination(forthDest, Vidin, 199);
	initDestination(fifthDest, Dobrich, 512);

	secArr[0] = fisrtDest;
	secArr[1] = secondDest;
	secArr[2] = thirdDest;
	secArr[3] = forthDest;
	secArr[4] = fifthDest;


}

void printSecArr(Destination *secArr)
{
	for (int i = 0; i < 5; i++)
	{
		cout << secArr[i].city << endl << secArr[i].kilometers << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//да се създадат две дестинации и да се инициализират със следните данни
	//да се изведат на екрана полетата на двете дестинации, дефинирани в предишната точка
	Destination first;
	Destination second;

	initDestination(first, "Plovdiv", 165);
	initDestination(second, "Varna", 469);
	//да се дефинира масив от 30 структури Destination. Да не се инициализира масивът
	Destination arr[30];
	
	//да се дефинира масив от 5 структури Destination и се инициализира чрез следните данни
	Destination secArr[5];

	initFiveDest(secArr);

	cout << secArr[3].city << endl;

	printSecArr(secArr);

	cout << endl;

	return 0;
}

