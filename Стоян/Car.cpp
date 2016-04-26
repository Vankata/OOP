#include "stdafx.h"
#include "Car.h"

Car::Car() :Vehicle()
{
	cout << "Default constructor car" << endl;
	this->model = NULL;
	this->doors = 0;
	this->HP = 0;
}

Car::Car(char* color, char* make, int year, int seats, double maxSpeed, char* model, int doors, int HP) : Vehicle(color, make, year, seats, maxSpeed)
{
	cout << "Constructor car" << endl;
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
	this->doors = doors;
	this->HP = HP;
}

Car::Car(const Car &other) : Vehicle(other)
{
	cout << "Copy constructor car" << endl;
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

Car &Car::operator=(const Car &other)
{
	cout << "operator= car" << endl;
	if (this != &other)
	{
		delete[]this->color;
		delete[]this->make;
		delete[]this->model;
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

	return *this;
}

Car::~Car()
{
	cout << "Destructor car" << endl;
	if (this->model != NULL)
	{
		delete[]this->model;
	}
}

char* Car::getModel()const
{
	cout << "getModel car" << endl;
	return this->model;
}

int Car::getDoors()const
{
	cout << "getDoors car" << endl;
	return this->doors;
}

int Car::getHP()const
{
	cout << "getHP car" << endl;
	return this->HP;
}