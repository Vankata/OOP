#pragma once
#include <iostream>
#include <string.h>
#include "stdafx.h"
#include <math.h>

using namespace std;

class Vector
{
private:
	double *elements;
	int numberElements;

public:
Vector();//done
	Vector(double *elements, int numberElements);//done
	Vector(const Vector &other);//done
	Vector &operator=(const Vector &other);//done
	~Vector();//done

	friend ostream& operator<<(ostream& os, const Vector &other);//done
	friend istream& operator>>(istream& is, Vector &other);//done

	friend Vector operator+(const Vector &v1, const Vector &v2);//done
	friend Vector operator-(const Vector &v1, const Vector &v2);//done
	Vector &operator+=(const Vector &other);//done
	Vector &operator-=(const Vector &other);//done

	friend Vector operator+(const Vector other, double num);//done
	Vector &operator+=(double num);//done
	friend Vector operator-(const Vector other, double num);//done
	Vector &operator-=(double num);//done
	friend Vector operator*(const Vector other, double num);//done
	Vector &operator*=(double num);//done
	friend Vector operator/(const Vector other, double num);//done
	Vector &operator/=(double num);//done

	const double operator[](int index)const;//done
	double &operator[](int index);//done

	friend Vector operator*(const Vector &v1, const Vector &v2);//done
	Vector &operator*=(const Vector &other);//done

	Vector &operator!();//done
};
