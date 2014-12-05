//تمرین کلاسی: برنامه ای بنویسید که شماره ی جمله ی فیبوناچی را از کاربر دریافت کند و مقدار آن را تحویل دهد. (توسط تابع برگشت پذیر)
// برنامه ای بنویسید که یک عدد صحیح دریافت کند و فاکتوریل آن را برگرداند.

#include <iostream>

using namespace std;

unsigned int fibo(unsigned int n);
unsigned long int factorial(register unsigned long int n);
unsigned long int factorial_for(register unsigned long int n);
unsigned int fibo_for(unsigned int n);

int main()
{
	unsigned int input;
	cout << "Please enter a positive integer: ";
	cin >> input;
	cout << "recursive function: " << input << "! = " << factorial(input) << '\n';
	cout << "using FOR loop: " << input << "! = " << factorial_for(input) << '\n';
	cout << "Calculated using recursive function, The " << input << "th sentence of fibbonacci series is " << fibo(input) << '\n';
	cout << "Calculated using FOR loop, The " << input << "th sentence of fibbonacci series is " << fibo_for(input) << '\n';
	
	cin.ignore();
	cin.get();
	return 0;
}

unsigned long int factorial(register unsigned long int n)
{
	if (n == 0)
		return 1;
		return n * factorial(n - 1);
}

unsigned long int factorial_for(register unsigned long int n)
{
	unsigned long int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}

unsigned int fibo(unsigned int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
		return fibo(n - 1) + fibo(n - 2);
}

unsigned int fibo_for(unsigned int n)
{
	unsigned int n_1 = 0;
	unsigned int n_2 = 1;
	unsigned int temp;

	for (int i = 0; i < n; i++)
	{
		temp = n_2 + n_1;
		n_1 = n_2;
		n_2 = temp;
	}
	return n_1;
}
