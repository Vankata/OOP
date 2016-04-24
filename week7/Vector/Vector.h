#pragma once
#include <iostream>
#include <string.h>
#include "stdafx.h"
#include <math.h>

using namespace std;

class Vector
{
private:
	int *elements;
	int numberElements;

public:
	Vector();//done
	Vector(int *elements, int numberElements);//done
	Vector(const Vector &other);//done
	Vector &operator=(const Vector &other);//done
	~Vector();//done

	friend ostream& operator<<(ostream& os, const Vector &other);//done
	friend istream& operator>>(istream& is, Vector &other);//done

	friend Vector operator+(const Vector &v1, const Vector &v2);//done
	friend Vector operator-(const Vector &v1, const Vector &v2);//done
	Vector &operator+=(const Vector &other);//done
	Vector &operator-=(const Vector &other);//done

	friend Vector operator+(const Vector other, int num);//done
	Vector &operator+=(int num);//done
	friend Vector operator-(const Vector other, int num);//done
	Vector &operator-=(int num);//done
	friend Vector operator*(const Vector other, int num);//done
	Vector &operator*=(int num);//done
	friend Vector operator/(const Vector other, int num);//done
	Vector &operator/=(int num);//done

	const int operator[](int index)const;//done
	int &operator[](int index);//done

	friend Vector operator*(const Vector &v1, const Vector &v2);//done
	Vector &operator*=(const Vector &other);//done

	Vector &operator!();//done
};