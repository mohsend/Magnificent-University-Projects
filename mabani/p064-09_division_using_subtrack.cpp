// تمرین کتاب: برنامه ای بنویسید که دو عدد صحیح مثبت را از ورودی خوانده، آنها را به روش تفریق بر هم تقسیم کند. (فصل دوم - ساختار های کنترلی - صفحه ۶۴ - تمرین ۹)
// page 64 #9
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned int x;
	unsigned int y;
	unsigned int count;
	unsigned int temp;
	cout << "This program calculates dvision of two positive integers. Enter x: ";
	cin >> x;
	cout << "and y: ";
	cin >> y;
	temp = x;
	for (count = 0; y <= temp; count++)
	temp -= y;
	cout << "x/y = " << count << " and x%y = " << temp << endl;
	
	cin.ignore();
	cin.get();
	return 0;
}

