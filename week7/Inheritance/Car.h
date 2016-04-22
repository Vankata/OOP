#pragma once
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "Vehicle.h"

class Car : public Vehicle
{
protected:
	char* model;
	int doors;
	int HP;

public:
	Car();
	Car(char* color, char* make, int year, int seats, double maxSpeed, char* model, int doors, int HP);
	Car(const Car &other);
	Car &operator=(const Car &other);
	~Car();
};