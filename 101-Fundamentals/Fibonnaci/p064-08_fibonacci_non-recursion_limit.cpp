/*
تمرین کتاب: برنامه ای بنویسید که تعداد n جمله از سری فیبوناچی را تولید کند. (فصل دوم - ساختار های کنترلی - صفحه ۶۴ - تمرین ۸)
*/


#include <iostream>
using namespace std;

int main()
{
	unsigned int n = 0;
	unsigned int fn1 = 0;
	unsigned int fn2 = 1;
	unsigned int input;

	cout << "When should this program stop calculating fibonacci numbers? Enter a limit:\n";
	cin >> input;
	cout << fn1 << "\t" << fn2 << "\t";

	while ( n < input )
	{
	n = fn1 + fn2;
	cout << n << "\t";
	fn1 = fn2;
	fn2 = n;
	}

	cout << endl;

	cin.ignore();
	cin.get();
	return 0;
}

