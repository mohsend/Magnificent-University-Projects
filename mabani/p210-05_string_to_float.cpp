/*
page 210-5
یک عدد اعشاری را به صورت آرایه ای از کارکتر ها از کاربر دریافت میکند.
آن را به عدد اعشاری تبدیل میکند.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	float convert (char[]);
	char string[10];
	cout << "Enter a float number with a point in it.\n";
	cin >> string;
	cout << convert(string) << endl;
	
	cin.ignore();
	cin.get();
	return 0;
}

float convert (char A[])
{
	int point, end;
	for (int i = 0; i < 11; i++)
	{
		if (A[i] == '.')
			point = i;
		if (A[i] == 0)
		{
			end = i;
			break;
		}
	}
	float num = 0.0, digit_f;
	int digit, power = 0;
	for (int i = point - 1; i > -1; i--)
	{
		digit = A[i] - '0';
		for (int i = 0; i < power; i++)
			digit *= 10; 
		num += digit;
		power++;
	}
	power = 1;
	for (int i = point + 1; i < end; i++)
	{
		digit_f = A[i] - '0';
		for (int i = 0; i < power; i++)
			digit_f /= 10; 
		num += digit_f;
		power++;
	}
	return num;
}
