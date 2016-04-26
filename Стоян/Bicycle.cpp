#include "stdafx.h"
#include "Bicycle.h"

Bicycle::Bicycle() :Vehicle()
{
	cout << "Default constructor bicycle" << endl;
	this->gears = 0;
	this->lights = false;
	this->ring = false;
}

Bicycle::Bicycle(char* color, char* make, int year, int seats, double maxSpeed, int gears, bool lights, bool ring) : Vehicle(color, make, year, seats, maxSpeed)
{
	cout << "Constructor bicycle" << endl;
	this->gears = gears;
	this->lights = lights;
	this->ring = ring;
}

Bicycle::Bicycle(const Bicycle &other) : Vehicle(other)
{
	cout << "Copy constructor bicycle" << endl;
	this->color = new char[strlen(other.color) + 1];
	strcpy_s(this->color, strlen(other.color) + 1, other.color);
	this->make = new char[strlen(other.make) + 1];
	strcpy_s(this->make, strlen(other.make) + 1, other.make);
	this->year = other.year;
	this->seats = other.seats;
	this->maxSpeed = other.maxSpeed;
	this->gears = other.gears;
	this->lights = other.lights;
	this->ring = other.ring;
}

Bicycle &Bicycle::operator=(const Bicycle &other) 
{
	cout << "operator= bicycle" << endl;
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
		this->gears = other.gears;
		this->lights = other.lights;
		this->ring = other.ring;
	}

	return *this;
}

Bicycle::~Bicycle()
{
	cout << "Destructor bicycle" << endl;
}

int Bicycle::getGears()const
{
	cout << "getGears bicycle" << endl;
	return this->gears;
}

bool Bicycle::getLights()const
{
	cout << "getLights bicycle" << endl;
	return this->lights;
}

bool Bicycle::getRing()const
{
	cout << "getRing bicycle" << endl;
	return this->ring;
}

void Bicycle::setRing(bool ring)
{
	cout << "setRing bicycle" << endl;
	this->ring = ring;
}