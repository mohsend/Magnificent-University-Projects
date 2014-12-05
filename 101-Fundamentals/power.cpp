/*
این برنامه یک عدد صحیح به توان یک عدد صحیح را حساب میکند.
*/

#include <iostream>
using namespace std;

int main()
{
	long int power(int, unsigned int);
	int base = 1;
	unsigned int exponent;
	
	while (base)
	{
		cout << "Enter an integer for base (or '0' to break the loop): ";
		cin >> base;
		cout << "Enter an positive integer for exponent: ";
		cin >> exponent;
		
		cout << '\n' << base << '^' << exponent << " = " << power(base, exponent) << '\n';
	}
	
	cin.ignore();
	cin.get();
	return 0;
}

long int power(int base, unsigned int exponent)
{
	register long int javab = 1;
	for (unsigned int i = 0; i < exponent; i++)
		javab *= base;
	return javab;
}
