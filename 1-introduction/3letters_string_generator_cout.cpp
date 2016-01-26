/*
 * Prints all the 3 letter lowercase strings
 * on standard out.
 * From 'aaa' to 'zzz'
 */

#include <iostream>

using namespace std;

int main()
{
	// The backtick character ('`') is the one right before 'a' in ASCII table.
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
		}
	}
	return 0;
}
