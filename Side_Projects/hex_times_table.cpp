/*
 * Hexadecimal Multiplication table
 */

#include <iostream>
using namespace std;

int main()
{
	for (int i = 0x1; i < 0x10; i++)
	{
		for (int j = 0x1; j < 0x10; j++)
		{
			cout << hex << i * j << '\t';
		}
		cout << endl;
	}
	return 0;
}
