
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Planet{

	char name[100];
	int distanceSun;
	double diameter;
	double weight;
	

	void initPlanet(char *Name, int DistanceSun, double Diameter, double Weight)
	{
		strcpy_s(name, Name);
		distanceSun = DistanceSun;
		diameter = Diameter;
		weight = Weight;
	}

	void printPlanet()
	{
		cout << "The name of the planet is: " << name << endl;
		cout << "The distance from it to the Sun is: " << distanceSun << endl;
		cout << "The diameter of the planet is: " << diameter << endl;
		cout << "The weight of the planet is: " << weight << endl;
	}

	void speedOfLightToPlanet()
	{
		int speedOfLight = 300000;
		cout << "The light of the sun reaches the " << name << " for " << distanceSun / speedOfLight << " seconds." << endl;	
	}
 
};

void addPlanetToArr(Planet *arr, Planet planet, int &index)
{

	arr[index] = planet;
	index++;
}

void printPlanetsFromArr(Planet *arr)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "The name of the planet is: " << arr[i].name << endl;
		cout << "The distance from it to the Sun is: " << arr[i].distanceSun << endl;
		cout << "The diameter of the planet is: " << arr[i].diameter << endl;
		cout << "The weight of the planet is: " << arr[i].weight << endl;
	}
}

Planet biggestDiameter(Planet *arr, int size)
{
	Planet temp = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (temp.diameter < arr[i].diameter)
		{
			temp = arr[i];
		}
	}

	return temp;
}

Planet lowestWeight(Planet *arr, int size)
{
	Planet temp = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (temp.weight > arr[i].weight)
		{
			temp = arr[i];
		}
	}

	return temp;
}

Planet mostFarAwayPlanet(Planet *arr, int size)
{
	Planet temp = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (temp.distanceSun < arr[i].distanceSun)
		{
			temp = arr[i];
		}
	}

	return temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Planet Earth;
	Planet Jupiter;
	Planet Mars;


	Earth.initPlanet("Earth", 150000000, 12700, 5000000000);
	Jupiter.initPlanet("Jupiter", 1500000000, 120700, 30000000000);
	Mars.initPlanet("Mars", 1000000, 7000, 100000000);
	Earth.printPlanet();
	cout << endl;

	Earth.speedOfLightToPlanet();
	cout << endl;

	Planet arr[10];
	int size = 0;

	addPlanetToArr(arr, Earth, size);
	addPlanetToArr(arr, Jupiter, size);
	addPlanetToArr(arr, Mars, size);

	cout << arr[0].name << endl;

	cout << "The planet with the biggest diamets is: " << biggestDiameter(arr, size).name << endl;
	cout << "The planet with the lowest weight is: " << lowestWeight(arr,size).name << endl;
	cout << "The planet most far away from the Sun is: " << mostFarAwayPlanet(arr,size).name << endl;


	return 0;
}

