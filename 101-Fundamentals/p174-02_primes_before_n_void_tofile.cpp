/*
تمرین صفحه 174 شماره 2: برنامه ای بنویسید که عدد صحیحی را از ورودی خوانده، تمام اعداد اول قبل از آن عدد را با استفاده از تعریف زیر تعیین کرده به خروجی ببرد.
تعریف: عددی اول است که بر هیچ کدام از اعداد اول قبل از خودش قابل قسمت نباشد.
dynamic array, pointer, function
*/

#include <iostream>
// <fstream> hasn't been covered in the class. if you don't know what it is, don't worry.
// it stands for "File Stream". it can create, open, write and manipulate files.
#include <fstream>
using namespace std;

int main()
{
	void prime(unsigned int*, unsigned int);
	void save(unsigned int, unsigned int*);

	unsigned int n, *p;
	cout << "Enter an positive integer bigger than 3: ";
	cin >> n;
	// defines an array to store prime numbers
	p = new unsigned int[(n / 2)];
	prime(p, n);
	save(n, p);

	// Ending program
	delete[] p;
	cin.ignore();
	cin.get();
	return 0;
}

void prime(unsigned int *p, unsigned int end)
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
	*(p + end_of_array) = 0;
}

void save(unsigned int n, unsigned int *p)
{
	ofstream myfile;
	myfile.open ("primes.txt", ios::trunc);
	for (unsigned int i = 0; *(p + i); i++)
		myfile << *(p + i) << '\n';
	cout << "\n'primes.txt' generated containing " << i << " prime numbers.\n";
}
