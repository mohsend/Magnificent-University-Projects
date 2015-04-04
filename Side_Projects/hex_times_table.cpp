/*
 * Hexadecimal Multiplication table
 */

#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 0xf; i++)
	{
		for (int j = 0; j < 0xf; j++)
		{
			cout << hex <<(i + 1)*(j + 1) << '\t';
		}
		cout << endl;
	}
	return 0;
}
