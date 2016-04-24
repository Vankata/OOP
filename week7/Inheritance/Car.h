#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
protected:
	char* model;
	int doors;
	int HP;

public:
	Car();//done
	Car(char* color, char* make, int year, int seats, double maxSpeed, char* model, int doors, int HP);//done
	Car(const Car &other);//done
	Car &operator=(const Car &other);//done
	~Car();//done

	char* getModel()const;//done
	int getDoors()const;//done
	int getHP()const;//done
};