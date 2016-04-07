
#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
	this->capacity = initialCapacity;
	this->container = new int[capacity];
	this->size = 0;
}

Vector::Vector(size_t capacity, size_t size)
{
	this->capacity = capacity;
	this->container = new int[this->capacity];
	this->size = size;

	for (size_t i = 0; i < this->size; ++i)
	{
		this->container[i] = 0;
	}
}

Vector::Vector(const Vector& otherVector)
{
	this->capacity = otherVector.capacity;
	this->container = new int[this->capacity];
	this->size = otherVector.size;

	for (size_t i = 0; i < this->size; ++i)
	{
		this->container[i] = otherVector.container[i];
	}
}

Vector::~Vector()
{
	delete[]this->container;
}

void Vector::SetAt(int value, size_t index)
{
	if (index < 0 || index > size)
	{
		cout << "invalid index";
	}

	this->container[index] = value;
}

int Vector::GetAt(size_t index)const
{
	if (index < 0 || index > size)
	{
		return -1;
	}

	return this->container[index];
}

void Vector::PushBack(int element)
{
	if (this->size >= this->capacity)
	{
		Resize(2 * this->capacity);
	}

	this->container[this->size] = element;
}

void Vector::InsertAt(int element, size_t index)
{
	if (index < 0 || index > size)
	{
		cout << "invalid index";
	}

	if (this->size == this->capacity)
	{
		Resize(2 * this->capacity);
	}

	for (size_t i = size; i >= index ; --i)
	{
		
			this->container[i] = this->container[i - 1];
		
	}
	this->container[index] = element;
	this->size += 1;

	if (this->size == this->capacity)
	{
		Resize(2 * this->capacity);
	}
}

void Vector::DeletAt(size_t index)
{
	if (index < 0 || index >= size)
	{
		cout << "invalid index" << endl;
	}
	else
	{
		for (size_t i = index; i < this->size - 1; ++i)
		{
			this->container[i] = this->container[i + 1];
		}
		this->size -= 1;
	}
}

bool Vector::IsEmpty()const
{
	if (this->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

size_t Vector::Size()const
{
	return this->size;
}

void Vector::Sort(bool sortIncreasing)
{
	int temp;

	if (sortIncreasing)
	{
		for (size_t i = 0; i < this->size - 1; ++i)
		{
			for (size_t j = i; j < this->size; ++j)
			{
				if (this->container[i]>this->container[j])
				{
					temp = this->container[i];
					this->container[i] = this->container[j];
					this->container[j] = temp;
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i < this->size - 1; ++i)
		{
			for (size_t j = i; j < this->size; ++j)
			{
				if (this->container[i]<this->container[j])
				{
					temp = this->container[i];
					this->container[i] = this->container[j];
					this->container[j] = temp;
				}
			}
		}
	}
}

bool Vector::IsSorted()const
{
	bool flag = true;

	for (size_t i = 0; i < this->size - 1; ++i)
	{
		if (this->container[i]>this->container[i + 1])
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

void Vector::Resize(size_t newCapacity)
{
	int*buffer;
	buffer = new int[newCapacity];
	for (size_t i = 0; i < this->size; ++i)
	{
		buffer[i] = this->container[i];
	}
	delete[]this->container;
	this->capacity = newCapacity;
	this->container = buffer;
}

