#pragma once
#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

class Vehicle
{
protected:
	char* color;
	char* make;
	int year;
	int seats;
	double maxSpeed;

public:
	Vehicle();//done
	Vehicle(char* color, char* make, int year, int seats, double maxSpeed);//done
	Vehicle(const Vehicle &other);//done
	Vehicle &operator=(const Vehicle &other);//done
	~Vehicle();//done

	char* getColor()const;//done
	void setColor(char* color);//done
	char* getMake()const;//done
	int getYear()const;//done
	int getSeats()const;//done
	double getMaxSpeed()const;//done
};