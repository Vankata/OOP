#include "stdafx.h"
#include "Vehicle.h"

Vehicle::Vehicle()
{
	cout << "Default constructor vehicle" << endl;
	this->color = NULL;
	this->make = NULL;
	this->maxSpeed = 0;
	this->seats = 0;
	this->year = 1970;
}

Vehicle::Vehicle(char* color, char* make, int year, int seats, double maxSpeed)
{
	cout << "Constructor vehicle" << endl;
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
	this->make = new char[strlen(make) + 1];
	strcpy_s(this->make, strlen(make) + 1, make);
	this->year = year;
	this->seats = seats;
	this->maxSpeed = maxSpeed;
}

Vehicle::Vehicle(const Vehicle &other)
{
	cout << "Copy constructor vehicle" << endl;
	this->color = new char[strlen(other.color) + 1];
	strcpy_s(this->color, strlen(other.color) + 1, other.color);
	this->make = new char[strlen(other.make) + 1];
	strcpy_s(this->make, strlen(other.make) + 1, other.make);
	this->year = other.year;
	this->seats = other.seats;
	this->maxSpeed = other.maxSpeed;
}

Vehicle &Vehicle::operator=(const Vehicle &other)
{
	cout << "operator= vehicle" << endl;
	if (this != &other)
	{
		delete[]this->color;
		delete[]this->make;

		this->color = new char[strlen(other.color) + 1];
		strcpy_s(this->color, strlen(other.color) + 1, other.color);
		this->make = new char[strlen(other.make) + 1];
		strcpy_s(this->make, strlen(other.make) + 1, other.make);
		this->year = other.year;
		this->seats = other.seats;
		this->maxSpeed = other.maxSpeed;
	}

	return *this;
}

Vehicle::~Vehicle()
{
	cout << "Destructor vehicle" << endl;
	if (this->color != NULL)
	{
		delete[]this->color;
	}
	if (this->make != NULL)
	{
		delete[]this->make;
	}
}

char* Vehicle::getColor()const
{
	cout << "getColor vehicle" << endl;
	return this->color;
}

void Vehicle::setColor(char* color)
{
	cout << "setColor vehicle" << endl;
	if (this->color != NULL)
	{
		delete[]this->color;
	}
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

char* Vehicle::getMake()const
{
	cout << "getMake vehicle" << endl;
	return this->make;
}

int Vehicle::getYear()const
{
	cout << "getYear vehicle" << endl;
	return this->year;
}

int Vehicle::getSeats()const
{
	cout << "getSeats vehicle" << endl;
	return this->seats;
}

double Vehicle::getMaxSpeed()const
{
	cout << "getMaxSpeed vehicle" << endl;
	return this->maxSpeed;
}