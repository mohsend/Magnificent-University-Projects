/*
فاکتوریل یک عدد به صورت بازگشتی
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	unsigned int fact(unsigned int);

	unsigned int num;

	cout << "Enter a positive integer and I will calculate the factorial of it: ";
	cin >> num;
	cout << num << "! = " << fact(num) << '\n';

	cin.ignore();
	cin.get();
	return 0;
}

unsigned int fact(unsigned int n)
{
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}
