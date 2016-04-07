
#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

struct City
{
	char *name;
	int population; // в хиляди 
	bool hasMuseum;	
};

void initCity(City &Cit, char* Name, int Population, bool HasMuseum)
{
	Cit.name = new char[strlen(Name) + 1];

	strcpy_s(Cit.name, strlen(Name) + 1, Name);
	Cit.population = Population;
	Cit.hasMuseum = HasMuseum;

	cout << Cit.name << " | " << Cit.population << " | " << Cit.hasMuseum << endl;
}

struct Destination
{
	City cit;
	int kilometers;

};

struct GPS
{
	City currentCity;
	Destination path[10];
};

void initDest(Destination &dest, City Cit, int km, Destination *arr, int &index)
{
	dest.cit = Cit;
	dest.kilometers = km;
	arr[index] = dest;
	index++;
}

void initGPS(GPS &gps, City curr, Destination *arr, int &index)
{
	
	gps.currentCity = curr;
	
	for (int i = 0; i < index; i++)
	{
		gps.path[i] = arr[i];
	}
}

void searchForMuseum(GPS &gps,int index)
{
	for (int i = 0; i < index; i++)
	{
		if (gps.path[i].cit.hasMuseum == true)
		{
			cout << "There is a museum in " << gps.path[i].cit.name << "." << endl;
		}
		else
		{
			cout << "There is no museum in " << gps.path[i].cit.name << "." << endl;
		}
	}
}

void distanceToCity(GPS &gps, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (gps.currentCity.name != gps.path[i].cit.name)
		{
			if (gps.path[i].kilometers <= 100)
			{
				cout << gps.path[i].cit.name << " is close to " << gps.currentCity.name << "." << endl;
			}
			else if (gps.path[i].kilometers > 100 && gps.path[i].kilometers <= 200)
			{
				cout << gps.path[i].cit.name << " is not so close to " << gps.currentCity.name << "." << endl;
			}
			else
			{
				cout << gps.path[i].cit.name << " is far away from " << gps.currentCity.name << "." << endl;
			}
		}
	}
}

void sortCities(GPS &gps, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(gps.path[i].cit.name, gps.path[j].cit.name) > 0)
			{
				Destination temp = gps.path[i];
				gps.path[i] = gps.path[j];
				gps.path[j] = temp;
			}
		}
	}

	cout << "Cities in alphabet order: " << endl;

	for (int p = 0; p < size; p++)
	{
		cout << gps.path[p].cit.name << endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	City Varna = { "Varna", 500, false };
	City Sofia = { "Sofia", 2000, true };
	City Plovdiv = { "Plovdiv", 700, true };
	City Lovech = { "Lovech", 100, true };

	Destination varna, sofia, plovdiv, lovech;

	int index = 0;
	Destination arr[10];

	initDest(varna, Varna, 500, arr, index);
	initDest(sofia, Sofia, 0,arr, index);
	initDest(plovdiv, Plovdiv, 200, arr, index);
	initDest(lovech, Lovech, 220, arr, index);

	GPS gps;

	initGPS(gps, Sofia, arr, index);

	searchForMuseum(gps, index);
	cout << endl;

	distanceToCity(gps, index);
	cout << endl;

	sortCities(gps, index);
	cout << endl;

	delete[] Varna.name;
	delete[] Sofia.name;
	delete[] Lovech.name;
	delete[] Plovdiv.name;


	return 0;
}

