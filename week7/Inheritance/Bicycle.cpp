#include "stdafx.h"
#include "Bicycle.h"

Bicycle::Bicycle() :Vehicle()
{
	this->gears = 0;
	this->lights = false;
	this->ring = false;
}

Bicycle::Bicycle(char* color, char* make, int year, int seats, double maxSpeed, int gears, bool lights, bool ring) : Vehicle(color, make, year, seats, maxSpeed)
{
	this->gears = gears;
	this->lights = lights;
	this->ring = ring;
}

Bicycle::Bicycle(const Bicycle &other) : Vehicle(other)
{
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

}

int Bicycle::getGears()const
{
	return this->gears;
}

bool Bicycle::getLights()const
{
	return this->lights;
}

bool Bicycle::getRing()const
{
	return this->ring;
}

void Bicycle::setRing(bool ring)
{
	this->ring = ring;
}
