/*
تمرین کتاب: برنامه ای بنویسید که مقدار e^x را به صورت زیر محاسبه کند. (فصل دوم - ساختار های کنترلی - صفحه ۶۴ - تمرین ۳)
*/

#include <iostream>
using namespace std;

int main()
{
	double ep = 0.0;
	long unsigned int fact = 1;
	int input;
	cout << "Enter an integer, I'll calculate e^x for you.\n" << "x = ";
	cin >> input;	
	for (int count = 1; count < 50; count++)
	{
		ep += input * (1.0 / fact);
		fact *= count;
	}
	cout << "e^" << input << " = " << ep <<endl;
	
	return 0;
}

