/*
صفحه ۶۵ - تمرین ۱۶: برنامه ای بنویسید که ضرایب معادله ی درجه دوم را از ورودی خوانده و معادله را حل کند.
صفحه 98 - تمرین 8: برنامه ای بنویسید که ضرایب معادله ی درجه دومی را از ورودی خوانده، آن ها را به تابعی ارسال کند. تابع معادله را حل کرده جواب هاب آن را به خروجی ببرد.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	void quad(float, float, float);
	
	float a, b, c;
	
	cout << "Here is a Quadratic equation:\n\t\ta*X^2 + b*X + c = 0\nEnter these values (float):\na = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	quad(a,b,c);
	
	cin.ignore();
	cin.get();
	return 0;
}

void quad(float a, float b, float c)
{
	float x1, x2, delta, temp;
	delta = (b * b) - (4 * a * c);
	if (delta == 0)
	{
		x1 = - b / (2 * a);
		cout << "I solved it!\nDelta = 0\nX = " << x1 << '\n';
	}
	else if (delta > 0)
	{
		temp = sqrt(delta);
		x1 = - (b + temp) / (2 * a);
		x2 = - (b - temp) / (2 * a);
		cout << "I solved it!\nDelta = " << delta << "\nX = " << x1 << ", " << x2 << '\n';
	}
	else
		cout << "This equation has no answers!\n";
}
