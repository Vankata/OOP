#include "stdafx.h"
#include "Vector.h"

Vector::Vector()
{
	this->elements = NULL;
	this->numberElements = 0;
}

Vector::Vector(double *elements, int numberElements)
{
	this->elements = new double[numberElements];

	for (int i = 0; i < numberElements; i++)
	{
		this->elements[i] = elements[i];
	}
	this->numberElements = numberElements;
}

Vector::Vector(const Vector &other)
{
	this->elements = new double[other.numberElements];

	for (int i = 0; i < other.numberElements; i++)
	{
		this->elements[i] = other.elements[i];
	}
	this->numberElements = other.numberElements;
}

Vector &Vector::operator=(const Vector &other)
{
	if (this != &other)
	{
		if (this->elements != NULL)
		{
			delete[]this->elements;
		}

		this->elements = new double[other.numberElements];

		for (int i = 0; i < other.numberElements; i++)
		{
			this->elements[i] = other.elements[i];
		}
		this->numberElements = other.numberElements;
	}

	return *this;
}

Vector::~Vector()
{
	if (this->elements != NULL)
	{
		delete[]this->elements;
	}
}

ostream& operator<<(ostream& os, const Vector &other)
{
	os << "(";
	for (int i = 0; i < other.numberElements; i++)
	{
		if (i == other.numberElements - 1)
		{
			os << other.elements[i];
		}
		else
		{
			os << other.elements[i] << ", ";
		}
	}
	os << ")";

	return os;
}

istream& operator>>(istream& is, Vector &other)
{
	for (int i = 0; i < other.numberElements; i++)
	{
		is >> other.elements[i];
	}

	return is;
}

Vector &Vector::operator+=(const Vector &other)
{
	int sizeSmaller;
	if (this->numberElements >= other.numberElements)
	{
		sizeSmaller = other.numberElements;
	}
	else
	{
		sizeSmaller = this->numberElements;
	}

	for (int i = 0; i < sizeSmaller; i++)
	{
		this->elements[i] += other.elements[i];
	}

	return *this;
}

Vector &Vector::operator-=(const Vector &other)
{
	int sizeSmaller;
	if (this->numberElements >= other.numberElements)
	{
		sizeSmaller = other.numberElements;
	}
	else
	{
		sizeSmaller = this->numberElements;
	}

	for (int i = 0; i < sizeSmaller; i++)
	{
		this->elements[i] -= other.elements[i];
	}

	return *this;
}

Vector operator+(const Vector &v1, const Vector &v2)
{
	Vector result(v1);

	result += v2;

	return result;
}

Vector operator-(const Vector &v1, const Vector &v2)
{
	Vector result(v1);

	result -= v2;

	return result;
}

Vector &Vector::operator+=(double num)
{
	for (int i = 0; i < this->numberElements; i++)
	{
		this->elements[i] += num;
	}

	return *this;
}

Vector &Vector::operator-=(double num)
{
	for (int i = 0; i < this->numberElements; i++)
	{
		this->elements[i] -= num;
	}

	return *this;
}

Vector operator+(const Vector other, double num)
{
	Vector result(other);

	result += num;

	return result;
}

Vector operator-(const Vector other, double num)
{
	Vector result(other);

	result -= num;

	return result;
}

Vector &Vector::operator*=(double num)
{
	for (int i = 0; i < this->numberElements; i++)
	{
		this->elements[i] *= num;
	}

	return *this;
}

Vector &Vector::operator/=(double num)
{
	for (int i = 0; i < this->numberElements; i++)
	{
		this->elements[i] /= num;
	}

	return *this;
}

Vector operator*(const Vector other, double num)
{
	Vector result(other);

	result *= num;

	return result;
}

Vector operator/(const Vector other, double num)
{
	Vector result(other);

	result /= num;

	return result;
}

double wrongIndex = 404;

const double Vector::operator[](int index)const
{
	if (index < 0 || index > this->numberElements)
	{
		return wrongIndex;
	}
	else
	{
		return this->elements[index];
	}
}

double &Vector::operator[](int index)
{
	if (index < 0 || index > this->numberElements)
	{
		return wrongIndex;
	}
	else
	{
		return this->elements[index];
	}
}

Vector &Vector::operator*=(const Vector &other)
{
	int sizeSmaller;
	if (this->numberElements >= other.numberElements)
	{
		sizeSmaller = other.numberElements;
	}
	else
	{
		sizeSmaller = this->numberElements;
	}

	for (int i = 0; i < sizeSmaller; i++)
	{
		this->elements[i] *= other.elements[i];
	}

	if (sizeSmaller != this->numberElements)
	{
		for (int i = sizeSmaller; i < this->numberElements; i++)
		{
			this->elements[i] = 0;
		}
	}

	return *this;
}

Vector operator*(const Vector &v1, const Vector &v2)
{
	Vector result(v1);
	
	result *= v2;

	return result;
}

Vector &Vector::operator!()
{
	double sum = 0;
	for (int i = 0; i < this->numberElements; i++)
	{
		sum += this->elements[i] * this->elements[i];
	}
	double length = sqrt(sum);
	
	return (*this /= length);
}
