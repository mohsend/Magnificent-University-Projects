/*
این برنامه همه ی رشته های ممکن بین 
aaa to zzz
را تولید میکند.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	// the character '`' is the one right before 'a' in ASCII table.
	char ch1 = '`', ch2 = '`', ch3 = '`';
	for (int z = 0; z < 26; z++)
	{
		ch1++;
		ch2 = '`';
		for (int i = 0; i < 26; i++)
		{
			ch2++;
			ch3 = '`';
			for (register int j = 0; j < 26; j++)
			{
				ch3++;
				cout << ch1 << ch2 << ch3 << '\n';
			}
			cout << "Press Enter to continue.";
			cin.get();
		}
	}
	return 0;
}
