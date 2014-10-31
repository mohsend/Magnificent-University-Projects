// فاکتوریل به روش غیر بازگشتی

#include "stdafx.h"
#include <iostream>

using namespace std;

unsigned long int fact(unsigned int);

int main()
{
	unsigned int n;

	cout << "Enter an positive integer:\nN = ";
	cin >> n;
	cout << n << "! = " << fact(n);
	
	cin.ignore();
	cin.get();
	return 0;
}

unsigned long int fact(unsigned int n)
{
	register unsigned long int temp = 1;
	for (register unsigned int i = 1; i < n + 1; i++)
	{
		temp *= i;
	}
	return temp;
}
