/*
تمرین: برنامه ای بنویسید که عدد صحیحی را از کاربر دریافت نماید سپس توسط فانکشن پرایم تعیین کند که این عدد اول است یا خیر.
*/

#include <iostream>

using namespace std;

int main()
{
	bool prime(int);
	int input;
	cout << "Enter an integer: ";
	cin >> input;
	if (prime(input))
		cout << input << " IS a prime.\n";
	else
		cout << input << " is NOT a prime.\n";
	
	cin.ignore();
	cin.get();
	return 0;
}

bool prime(int a)
{
	register int till = (a / 2) + 1;
	for (register int i = 2; i < till; i++)
		if (a % i == 0)
			return false;
	return true;
}

