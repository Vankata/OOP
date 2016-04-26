#include "stdafx.h"
#include "Bicycle.h"
#include "Car.h"

int main()
{
	Bicycle myBicycle("blue", "balkan", 1997, 1, 50, 21, true, true);
	cout << myBicycle.getColor() << endl;
	Car myCar("red", "ferrari", 2016, 4, 333, "A75", 2, 600);
	cout << myCar.getMake() << endl;
	cout << myCar.getHP() << endl;



	return 0;
}