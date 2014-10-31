/*
تمرین صفحه 174 شماره 2: برنامه ای بنویسید که عدد صحیحی را از ورودی خوانده، تمام اعداد اول قبل از آن عدد را با استفاده از تعریف زیر تعیین کرده به خروجی ببرد.
تعریف: عددی اول است که بر هیچ کدام از اعداد اول قبل از خودش قابل قسمت نباشد.
dynamic array, pointer, function
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	unsigned int prime(unsigned int*, unsigned int);
	void print(unsigned int, unsigned int, unsigned int*);

	unsigned int n, *p, *p2, array_size;

	cout << "Enter an positive integer bigger than 3: ";
	cin >> n;
	// defines an array to store prime numbers
	p = new unsigned int[(n / 2)];
	array_size = prime(p, n);
	// the sole purpose of the next 6 lines is to use less RAM in the long run
	// defines a new array with the exact size needed and puts the values in it
	p2 = new unsigned int [array_size];
	for (unsigned int i = 0; i < array_size; i++)
		*(p2 + i) = *(p + i);
	// deletes the bigger array
	delete[] p;
	
	print(n, array_size, p2);

	// Ending program
	delete[] p2;
	cin.ignore();
	cin.get();
	return 0;
}

unsigned int prime(unsigned int *p, unsigned int end)
{
	// initializes end_of_array and puts the first prime number in the array
	unsigned int end_of_array = 1;
	*p = 2;
	// checks every number from 3 to end (n)
	for (unsigned int i = 3; i < end; i++)
	{
		// checks the number (i) against every prime number before it
		bool is_prime = true;
		for (unsigned int j = 0; j < end_of_array; j++)
			if ((i % *(p + j)) == 0)
			{
				is_prime = false;
				break;
			}
		if (is_prime)
		{
			*(p + end_of_array) = i;
			end_of_array++;
		}
	}
	return end_of_array;
}

void print(unsigned int n, unsigned int array_size, unsigned int *p)
{
	cout << "There are " << array_size << " prime numbers before " << n << ".\nHere they are:\n";
	for (unsigned int i = 0; i < array_size; i++)
		cout << *(p + i) << ", ";
	cout << '\n';
}
