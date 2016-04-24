#include "stdafx.h"
#include "Vehicle.h"

Vehicle::Vehicle()
{
	this->color = NULL;
	this->make = NULL;
	this->maxSpeed = 0;
	this->seats = 0;
	this->year = 1970;
}

Vehicle::Vehicle(char* color, char* make, int year, int seats, double maxSpeed)
{
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
	return this->color;
}

void Vehicle::setColor(char* color)
{
	if (this->color != NULL)
	{
		delete[]this->color;
	}
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

char* Vehicle::getMake()const
{
	return this->make;
}

int Vehicle::getYear()const
{
	return this->year;
}

int Vehicle::getSeats()const
{
	return this->seats;
}

double Vehicle::getMaxSpeed()const
{
	return this->maxSpeed;
}
