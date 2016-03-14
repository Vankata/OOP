
#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

struct Triangle{

	double a, b, c;

	void createTriangle(double A, double B, double C)
	{
		a = A;
		b = B;
		c = C;
	}

	void printTriangle()
	{
		cout << "First side: " << a << endl << "Second side: " << b << endl << "Third side: " << c << endl;
	}

	double perimeter()
	{
		cout << "The perimeter is: ";
		return a + b + c;
	}

	double area()
	{
		double p = (a + b + c) / 2;
		cout << "The area of the triangle is: ";
		return sqrt(p*(p - a)*(p - b)*(p - c));

	}

	Triangle newTriangle(int param)
	{
		Triangle newTr;
		newTr.createTriangle(a*param, b*param, c*param);
		return newTr;
	}
};

Triangle minArea(Triangle *arr, int size)
{
	int index = 0;
	double area = arr[0].area();

	for (int i = 1; i < size; i++)
	{
		if (arr[i].area() < area)
		{
			index = i;
			area = arr[i].area();
		}
	}

	return arr[index];
}

Triangle maxPer(Triangle *arr, int size)
{
	int index = 0;
	double perimeter = arr[0].perimeter();

	for (int i = 1; i < size; i++)
	{
		if (arr[i].perimeter() > perimeter)
		{
			index = i;
			perimeter = arr[i].perimeter();
		}
	}

	return arr[index];
}

void newSequence(Triangle *arr, int size, Triangle *newarr)
{
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i].newTriangle(i + 1);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	Triangle t;

	t.createTriangle(3, 4, 5);

	cout << t.a << endl;

	t.printTriangle();
	cout << t.perimeter() << endl;
	cout << t.area() << endl;


	return 0;
}

