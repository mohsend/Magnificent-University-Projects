/*
page 53, example 2-9.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int in, digit;
	while (true)
	{
		cout << "\nEnter an integer, '0' to end: ";
		cin >> in;
		if (!in) break;
		cout << "Inverse: ";
		do {
			digit = in % 10;
			cout << digit;
			in /= 10;
		} while (in);
	}

	cin.ignore();
	cin.get();
	return 0;
}

