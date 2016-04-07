// 03.Week 3 - OOPPract.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

enum Type{ VEGETABLES, FRUITS, MEET };

struct Product{

	Type type;
	char *name;
	long long int barcode;
	double price;
	int id;

};

struct Market{

	char *name;
	Product arr[20];
	int countProducts = 0;
	int capacity;
};

void initProduct(Product &product, Type Type, char *Name, long long int Barcode, double Price, int ID)
{
	product.name = new char[strlen(Name) + 1];
	product.type = Type;
	strcpy_s(product.name, strlen(Name) + 1, Name);
	product.barcode = Barcode;
	product.price = Price;
	product.id = ID;

}

void addProductToMarket(Market &Market, Product p, double Price)
{
	int capacity = 20;
	if (Market.countProducts < capacity)
	{
		Market.arr[Market.countProducts] = p;
		Market.countProducts++;
		Market.arr[Market.countProducts].price = Price;
		cout << "There are " << Market.countProducts << " products in the market." << endl;
	}
	else
	{
		cout << "You have reached the limit of the store." << endl;
	}

}

void initMarket(Market &Market, char *Name, int Capacity)
{
	Market.name = new char[strlen(Name) + 1];
	strcpy_s(Market.name, strlen(Name) + 1, Name);
	Market.capacity = Capacity;

}

void printMarket(Market &Market)
{	
	cout << "The name of the market is: " << Market.name << endl;
	cout << "The capacity of the store is " << Market.capacity << " and there are "<< Market.countProducts << "products." << endl;
}

void printProduct(Product &product)
{
	cout << "Product's type: " << product.type << endl;
	cout << "Product's name: " << product.name << endl;
	cout << "Product's barcode: " << product.barcode << endl;
	cout << "Product's price: " << product.price << endl;
	cout << "Product's ID: " << product.id << endl;

}

Market lowestPriceTypeProduct(Market *Market, Type type, int size)
{
	Market[0];

	for (int i = 0; i < size;i++)
}


int _tmain(int argc, _TCHAR* argv[])
{
	Product Krastavica;
	Product Domat;
	initProduct(Domat, VEGETABLES, "domat", 345678909876, 2.30, 345);
	initProduct(Krastavica, VEGETABLES, "krastavica", 123454321234, 1.20 , 123);
	printProduct(Krastavica);
	cout << endl;

	Market Levche;
	Market Djumaq;
	initMarket(Levche, "Levche", 20);
	initMarket(Djumaq, "Djumaq", 30);
	addProductToMarket(Levche, Domat,2.20);
	addProductToMarket(Djumaq, Domat, 2.10);

	printMarket(Levche);

	Market arrMarkets[10];

	arrMarkets[0] = Levche;
	arrMarkets[1] = Djumaq;


	cout << endl;


	delete[] Krastavica.name;
	delete[] Domat.name;
	delete[] Levche.name;
	delete[] Djumaq.name;

	return 0;
}

