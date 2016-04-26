#include "stdafx.h"
#include "Vector.h"


int _tmain(int argc, _TCHAR* argv[])
{
	double elements[3];
	double elementss[4];
	Vector v1(elements, 3);
	Vector v2(elementss, 4);

	cin >> v1;
	cin >> v2;

	cout << v1 << endl;
	cout << v2 << endl;

	cout << v1 + v2 << endl;
	cout << v1 - v2 << endl;

	v1 += v2;
	cout << v1 << endl << v2 << endl;

	v1 -= v2;
	cout << v1 << endl << v2 << endl;

	cout<< v1 + 4 <<endl;
	cout << v1 - 3 << endl;

	v1 += 2;
	cout << v1 << endl;

	v1 -= 2;
	cout << v1 << endl;

	cout << v1 * 4 << endl;
	cout << v1 / 3 << endl;

	v1 *= 2;
	cout << v1 << endl;

	v1 /= 2;
	cout << v1 << endl;

	cout << v1*v2 << endl;

	cout << v1.operator!()<< endl;

	return 0;
}
