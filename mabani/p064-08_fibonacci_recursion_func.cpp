/*
تمرین کتاب: برنامه ای بنویسید که تعداد n جمله از سری فیبوناچی را تولید کند. (فصل دوم - ساختار های کنترلی - صفحه ۶۴ - تمرین ۸)
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	long unsigned int fibonacci (unsigned int);
	unsigned int input;
	cout << "how many fibonacci numbers you want? ";
	cin >> input;
	for (unsigned int i = 0; i < input; i++)
		cout << fibonacci(i) << "\t";
	cout << endl;
	
	cin.ignore();
	cin.get();
	return 0;
}

long unsigned int fibonacci (unsigned int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}
