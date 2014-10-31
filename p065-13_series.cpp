/*
صفحه ۶۵ - تمرین ۱۳: برنامه ای بنویسید که حاصل عبارت زیر را محاسبه کند.
1 + 1/2! + 1/3! + ... + 1/n! (n<10)
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	float series(unsigned int);

	unsigned int num;
	bool again = true;

	cout << "Enter a positive integer smaller than 10 and I will calculate the sum of a series that long: ";
	while (again)
	{
		cin >> num;
		if (num < 10 && num > 0)
		{
			cout << "\n1 + 1/2! + ... + 1/" << num << "! = " << series(num) << '\n';
			again = false;
		}
		else
			cout << "I thought I made myself clear that:\n\t\t0 < your input < 10\nwhat do you think I am? a supercomputer?\nHere, I'll let you try once more: ";
	}
	
	cin.ignore();
	cin.get();
	return 0;
}

float series(unsigned int n)
{
	float sum = 0.0, fact = 1.0;
	for (int i = 1; i < n + 1; i++)
	{
		fact *= i;
		sum += 1.0 / fact;
	}
	return sum;
}
