// etehad.cpp : Defines the entry point for the console application.
// درستی این اتحاد ریاضی را بررسی میکند

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	long int x, n, x_n = 1, sum = 1;
	cout << "Enter two positive integers:\nX = ";
	cin >> x;
	cout << "N = ";
	cin >> n;
	n++;
	for (int i = 1; i < n; i++)
	{
		x_n *= x;
		cout << x <<'^' << i << " = " << x_n <<'\n';
		sum += x_n;
	}
	cout << "\n1 + x + x^2 + ... + x^n = " << sum;
	x_n *= x;
	cout << "\n(1 - x^(n+1) )/(1 - x) = " << ((1 - x_n) / (1 - x));

	cin.ignore();
	cin.get();
	return 0;
}

