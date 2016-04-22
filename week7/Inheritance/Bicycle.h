#pragma once
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "Vehicle.h"

using namespace std;


class Bicycle : public Vehicle
{
protected:
	int gears;
	bool lights;
	bool ring;

public:
	Bicycle();//done
	Bicycle(char* color, char* make, int year, int seats, double maxSpeed, int gears, bool lights, bool ring);//done
	Bicycle(const Bicycle &other);//done
	Bicycle &operator=(const Bicycle &other);//done
	~Bicycle();//done

	int getGears()const;
	bool getLights()const;
	bool getRing()const;
	void setRing(bool ring);
};