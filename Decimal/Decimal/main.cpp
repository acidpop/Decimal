#include <iostream>
using namespace std;

#include "decimal.h"

int main()
{
	int i;

	float f = 0;

	for (i = 0; i < 10000; i++)
	{
		f += 0.1f;
	}

	cout << f << endl;

	cin.get();
	return 0;
}