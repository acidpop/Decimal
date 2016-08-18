#include <iostream>
using namespace std;

#include "decimal.h"

int main()
{
	int i;

	float f = 0;

	for (i = 0; i < 10000; i++)
	{
		f += 0.001;
	}

	cout << f << endl;

	decimal d("0");
	decimal d2("0.001");

	for (i = 0; i < 10000; i++)
	{
		d = d + d2;
	}

	cout << d.toString() << endl;

	cin.get();
	return 0;
}