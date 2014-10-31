// greatest_com_domonaitor.cpp : Defines the entry point for the console application.
//p097 - 02
/*
تابعی به نام
gcd()
بنویسید که دو عدد صحیح را به عنوان آرگومان دریافت کند
و سپس بزرگ ترین مقسوم علیه مشترک آن ها را پیدا کند.
سپس برنامه ای بنویسید که این تابع را برای چندین جفت از اعداد امتحان کند.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int gcd(int, int);

	char respond;
	int in1, in2;

	do{
		cout << "Enter two integers:\n1) ";
		cin >> in1;
		cout << "2) ";
		cin >> in2;
		cout << "The greatest common divisor of " << in1 << " and " << in2 << " is " << gcd(in1, in2) << "\nDo you want to enter more integers? (Y/N)\n";
		cin >> respond;
	} while (respond == 'y' || respond == 'Y');
	cout << "Goodbye!";

	cin.ignore();
	cin.get();
	return 0;
}

int gcd(int n1, int n2)
{
	int com = 1, n;
	n = (n1 < n2) ? n1 : n2;
	for (int i = 2; i <= n; i++)
		if (n1 % i == 0)
			if (n2 % i == 0)
				com = i;
	return com;
}