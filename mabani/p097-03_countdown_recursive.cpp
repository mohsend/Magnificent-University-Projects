// countdown.cpp : Defines the entry point for the console application.
// تمرین کتاب: برنامه ای بنویسید که عددی را از ورودی خوانده، به کمک تابع بازگشتی شمارش معکوس از آن عدد را به یک انجام دهد.
// تمرین صفحه 97 شماره 3

#include <iostream>
using namespace std;

int main()
{
	int user_input;
	int countdown(int);
	cout << "Hi!\nWhy won't you enter an integer and I count it down to one? ";
	cin >> user_input;
	countdown(user_input);
	
	cin.ignore();
	cin.get();
	return 0;
}

int countdown(int n)
{
	cout << n << '\t';
	if (n == 1)
		return 1;
	else
	{
		countdown(n - 1);
		return n;
	}
}
