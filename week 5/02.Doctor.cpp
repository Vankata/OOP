
#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year);

	int getDay()const;
	int getMonth()const;
	int getYear()const;
};

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1970;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDay()const
{
	return this->day;
}

int Date::getMonth()const
{
	return this->month;
}

int Date::getYear()const
{
	return this->year;
}

class Patient
{
private:
	char*name;
	Date dateBirth;
	int visits;

public:
	Patient();
	~Patient();
	Patient(char*name, Date &dateBirth, int visits);
	Patient& operator = (const Patient& other);

	char*getName()const;
	Date getDateBirth()const;
	int getVisits()const;
};

Patient::Patient()
{
	this->name = NULL;
	this->dateBirth = Date();
	this->visits = 0;
}

Patient::~Patient()
{
	if (this->name != NULL)
	{
		delete[]this->name;
	}
}

Patient::Patient(char*name, Date &dateBirth, int visits)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->dateBirth = dateBirth;

	this->visits = visits;
}

Patient& Patient::operator = (const Patient& other)
{
	if (this != &other)
	{
		delete[] this->name;

		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);

		this->dateBirth = other.dateBirth;
		this->visits = other.visits;
	}

	return *this;
}

char* Patient::getName()const
{
	return this->name;
}

Date Patient::getDateBirth()const
{
	return this->dateBirth;
}

int Patient::getVisits()const
{
	return this->visits;
}

class Doctor
{
private:
	Patient*patArr;
	int countPat;
	int capacityPat;
	double avgVisits;
	int patMoreVisits;
	const int normalVisits = 10;

public:
	Doctor();
	~Doctor();
	Doctor(Patient*patArr, int size, int capacityPatients);
	Doctor& operator =(const Doctor& other);

	Patient*getPatArr()const;
	int getCountPat()const;
	int getCapacityPat()const;
	double getAvgVisits()const;
	int getPatMoreVisits()const;
};

Doctor::Doctor()
{
	this->patArr = NULL;
	this->countPat = 0;
	this->capacityPat = 0;
	this->avgVisits = 0;
	this->patMoreVisits = 0;
}

Doctor::~Doctor()
{
	if (this->patArr != NULL)
	{
		delete[]this->patArr;
	}
}

Doctor::Doctor(Patient*patArr, int size, int capacityPatients)
{
	this->patArr = new Patient[capacityPatients];
	this->capacityPat = capacityPatients;
	
	int avgVisits = 0;
	int moreVisits = 0;
	for (int i = 0; i < size; ++i)
	{
		this->patArr[i] = patArr[i];
		avgVisits += patArr[i].getVisits();

		if (patArr[i].getVisits() > this->normalVisits)
		{
			moreVisits += 1;
		}
	}

	this->countPat = size;
	this->avgVisits = avgVisits / size;
	this->patMoreVisits = moreVisits;

}

Doctor& Doctor::operator =(const Doctor& other)
{
	if (this != &other)
	{
		delete[] this->patArr;

		this->patArr = new Patient[other.capacityPat];
		for (size_t i = 0; i < other.capacityPat; ++i)
		{
			this->patArr[i] = other.patArr[i];
		}

		this->avgVisits = other.avgVisits;
		this->capacityPat = other.capacityPat;
		this->countPat = other.countPat;
		this->patMoreVisits = other.patMoreVisits;
	}

	return *this;
}

Patient*Doctor::getPatArr()const
{
	return this->patArr;
}

int Doctor::getCountPat()const
{
	return this->countPat;
}

double Doctor::getAvgVisits()const
{
	return this->avgVisits;
}

int Doctor::getPatMoreVisits()const
{
	return this->patMoreVisits;
}

int Doctor::getCapacityPat()const
{
	return this->capacityPat;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Date fisrtDate(25, 5, 1997);
	Date secDate(15, 7, 1995);
	Date thirdDate(13, 12, 1960);

	char name1[20] = "Petko";
	char name2[20] = "Dido";
	char name3[20] = "Mariq";

	int visits1 = 12;
	int visits2 = 3;
	int visits3 = 20;

	Patient firstPat(name1, fisrtDate, visits1);
	Patient secPat(name2, secDate, visits2);
	Patient thirdPat(name3, thirdDate, visits3);

	Patient patArr[20];
	patArr[0] = firstPat;
	patArr[1] = secPat;
	patArr[2] = thirdPat;

	Doctor Peshkata(patArr, 3, 19);

	cout << Peshkata.getPatArr()[1].getName() << endl;
	cout << Peshkata.getAvgVisits() << endl;
	cout << Peshkata.getCountPat() << endl;
	cout << Peshkata.getPatMoreVisits() << endl;
	cout << Peshkata.getPatArr()[2].getDateBirth().getYear() << endl;

	return 0;
}

