/* j4-1.cpp : Defines the entry point for the console application.
تمرین: برنامه ای بنویسید که عدد صحیحی را از کاربر دریافت نماید سپس توسط فانکشن پرایم تعیین کند که این عدد اول است یا خیر.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	void prime(int);
	int input;
	cout << "Enter an integer: ";
	cin >> input;
	prime(input);
	
	cin.ignore();
	cin.get();
	return 0;
}

void prime(int a)
{
	for (int i = 2; i < a; i++)
		if (a % i == 0)
		{
			cout << "This number is NOT a prime.\n";
			return;
		}
	cout << "This number IS a Prime.\n";
}

