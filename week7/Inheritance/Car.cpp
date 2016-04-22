#include "stdafx.h"
#include "Car.h"

Car::Car()
{
	Vehicle();
	this->model = NULL;
	this->doors = 0;
	this->HP = 0;
}

Car::Car(char* color, char* make, int year, int seats, double maxSpeed, char* model, int doors, int HP)
{
	Vehicle(color, make, year, seats, maxSpeed);
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
	this->doors = doors;
	this->HP = HP;
}

Car::Car(const Car &other)
{
	this->color = new char[strlen(other.color) + 1];
	strcpy_s(this->color, strlen(other.color) + 1, other.color);
	this->make = new char[strlen(other.make) + 1];
	strcpy_s(this->make, strlen(other.make) + 1, other.make);
	this->year = other.year;
	this->seats = other.seats;
	this->maxSpeed = other.maxSpeed;
	this->model = new char[strlen(other.model) + 1];
	strcpy_s(this->model, strlen(other.model) + 1, other.model);
	this->doors = other.doors;
	this->HP = other.HP;

}
