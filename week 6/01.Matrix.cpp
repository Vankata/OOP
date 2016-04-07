
#include "stdafx.h"
#include <iostream>

using namespace std;

class Matrix
{
	int ** m;
	int rows;
	int cols;

public:
	Matrix(int ** m = NULL, int rows = 0, int cols = 0);
	Matrix(Matrix const &mat);
	Matrix &operator=(Matrix const &mat);
	~Matrix();
};

Matrix::Matrix(Matrix const &mat)
{
	cols = mat.cols;
	rows = mat.rows;
	this->m = new int*[cols];

	for (int i = 0; i < cols; i++)
	{
		m[i] = new int[rows];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->m[i][j] = mat.m[i][j];
		}
	}
}

Matrix &Matrix::operator=(Matrix const &mat)
{
	if (this != NULL)
	{
		for (int i = 0; i < cols; i++)
		{
			delete[]m[i];
		}
		delete[]m;
	}

	return *this;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

