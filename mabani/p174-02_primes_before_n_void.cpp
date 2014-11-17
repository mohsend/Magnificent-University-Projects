/*
تمرین صفحه 174 شماره 2: برنامه ای بنویسید که عدد صحیحی را از ورودی خوانده، تمام اعداد اول قبل از آن عدد را با استفاده از تعریف زیر تعیین کرده به خروجی ببرد.
تعریف: عددی اول است که بر هیچ کدام از اعداد اول قبل از خودش قابل قسمت نباشد.
dynamic array, pointer, function
*/

#include <iostream>

using namespace std;

int main()
{
	void prime(int*, int);
	void print(int, int*);

	int n, *p;

	cout << "Enter an positive integer bigger than 3: ";
	cin >> n;
	// defines an array to store prime numbers
	p = new int[(n / 2)];
	prime(p, n);
	print(n, p);

	// Ending program
	delete[] p;
	cin.ignore();
	cin.get();
	return 0;
}

void prime(int *p, int end)
{
	// initializes end_of_array and puts the first prime number in the array
	int end_of_array = 1;
	*p = 2;
	// checks every number from 3 to end (n)
	for (int i = 3; i < end; i++)
	{
		// checks the number (i) against every prime number before it
		bool is_prime = true;
		for (int j = 0; j < end_of_array; j++)
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
	*(p + end_of_array) = 0;
}

void print(int n, int *p)
{
	cout << "\nprime numbers before " << n << ":\n";
	for (int i = 0; *(p + i); i++)
		cout << *(p + i) << ", ";
	cout << '\n' << i << " prime numbers.\n";
}
