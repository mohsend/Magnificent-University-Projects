//برنامه ای بنویسید که رشته ای را از کاربر دریافت نموده هر کاراکتر آن را در یک سطر چاپ نماید.

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
	string str;
	cout << "Enter a String:";
	getline(cin, str);
	cout << "Here is every character of your string:\n";
	for (int i = 0; str[i]; i++)
		cout << '\t' << str[i];
	cout << "Here is every character of your string in CAPITAL and with a little more complicated way of handling the loop:\n";
	for (int j = 0; j < str.length(); j++)
	{
		str[j] = (str[j] >= 'a' && str[j] <= 'z') ? str[j] - 32 : str[j];
		cout << '\t' << str[j];
	}
	cout << "Here is every character of your string, in reverse!\n";
	for (int j = str.length(); j > -1; j--)
		cout << '\t' << str[j];
	
	cin.ignore();
	cin.get();
	return 0;
}

