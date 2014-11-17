/*
تمرین کتاب: برنامه ای بنویسید که تعداد n جمله از سری فیبوناچی را تولید کند. (فصل دوم - ساختار های کنترلی - صفحه ۶۴ - تمرین ۸)
*/

#include <iostream>
using namespace std;
void fibo(int);

int main()
{
	int num;
	cout << "How many fibonacci numbers would you please? ";
	cin >> num;
	fibo(num);

	cin.ignore();
	cin.get();
	return 0;
}

void fibo(int n)
{
	unsigned int f1 = 0, f2 = 1, temp;
	cout << f1 << '\t';
	for (int i = 0; i < n; i++)
	{
		cout << f2 << '\t';
		temp = f2;
		f2 += f1;
		f1 = temp;
	}	
}
