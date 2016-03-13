#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Person
{
	char name[100];
	char lname[100];
};

struct Client
{
	Person person;
	double money;
};

void initPerson(Person &person)
{
	cout << "Enter first name: ";
	cin >> person.name;
	cout << "Enter last name: ";
	cin >> person.lname;
};

Person read_person()
{
	Person person;

	cout << "First name: ";
	cin >> person.name;
	cout << "Last name: ";
	cin >> person.lname;

	return person;
}//a podtochka

Client read_client()
{
	Client client;

	client.person = read_person();
	cout << "Enter money: ";
	cin >> client.money;

	return client;
}//a podtochka

void read_clients(Client* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = read_client();
	}
}  //a podtochka

void initCl(Client &client,Person person,double money)
{
	client.person = person;
	client.money = money;
}

void printPer(Person person)
{
	cout << person.name << " " << person.lname << endl;
}

void printCl(Client client)
{
	cout << "Person: " << client.person.name << " " << client.person.lname;
	cout << "Money in the bank account: " << client.money;
}

void readClients(Client*arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "First name: ";
		cin >> arr[i].person.name;
		cout << "Last name: ";
		cin >> arr[i].person.lname;
		cout << "Money in the bank account: ";
		cin >> arr[i].money;
	}
}

void printCls(Client* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i].person = read_person();
		cout << "Clients: " << read_person << arr[i].money << endl;
	}
}

double Sum(Client *arr, int size)
{
	double sum = 0;

	for (int i = 0; i < size; ++i)
	{
		sum += arr[i].money;
	}
	return sum;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

