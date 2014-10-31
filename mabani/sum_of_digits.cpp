/*
این برنامه هر تعداد ضرایبی با یک عدد صحیح که بخواهید برمیگرداند.
همچنین مجموع ارقام حاصل ضرب را نیز برمیگرداند.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	void multiply(unsigned int, unsigned int);
	unsigned int n, x;
	char prompt;
	do
	{
		cout << "Enter an positive integer (like 3, 6, 9, 10,...): \n\tX = ";
		cin >> x;
		cout << "How many multiplys should I calculate? \n\tN = ";
		cin >> n;

		multiply(x, n);

		if (x == 9)
			cout << "\n\nas you can see sum of digits of the numbers divideable by 9 is also divideable by 9.";
		else if (x == 10)
			cout << "\n\nSee the pattern in sum of digits?\n";
		else if ((x == 3) || (x == 6))
			cout << "\n\nas you can see sum of digits of the numbers divideable by 3 is also divideable by 3.";
		else
			cout << "\n\nI recommand you to enter 9 or 6 or 3 next time.";

		cout << "\nFUN! wasn't it? Do you want to try with another pair of numbers? (Y/n): ";
		cin >> prompt;
	} while (prompt == 'y' || prompt == 'Y');

	cout << "Goodbye!";
	cin.ignore();
	cin.get();
	return 0;
}

void multiply(unsigned int x, unsigned int n)
{
	unsigned int timesx, digit, sum_of_digits;
	for (int i = 1; i <= n; i++)
	{
		timesx = i * x;
		sum_of_digits = 0;
		for (int j = 10; (timesx * 10) >= j; j *= 10)
		{
			digit = ((timesx % j) / (j / 10));
			sum_of_digits += digit;
		}
		cout << "\n x * " << i << " = " << timesx << "\t\t sum of digits: " << sum_of_digits;
		// alternative solution:
		/*
		cout << "\n x * " << i << " = " << timesx;
		while (timesx) {
		digit = timesx % 10;
		sum_of_digits += digit;
		timesx /= 10;
		}
		cout << "\t\t sum of digits: " << sum_of_digits;
		*/
	}
}
