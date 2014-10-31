/*
تمرین دوم جلسه دوم: برنامه ای بنویسید که از کاربر متنی را دریافت کند، به محض وارد کردن کارکتر نقطه به کاربر تعداد کراکتر های تایپ شده را نشان دهد.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	
	cout << "Please type an sentence:\n";
	while (cin.get() != '.')
	{
	count ++;
	}
	cout << "The number of characters before period is: " << count << "\n";
	
	cin.ignore();
	cin.get();
	return 0;
}
