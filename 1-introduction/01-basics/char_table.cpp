/*
 * Prints (printable part of) ASCII table on standard out.
 * https://en.wikipedia.org/wiki/ASCII
 */

#include <iostream>

using namespace std;

int main()
{
	cout << "ASCII table: " << endl;
	cout << "| Char\t| DEC\t| HEX\t|" << endl;
	for (int i = 0x20; i < 0x80; i++)
	{
		cout << "| " << char(i) << "\t| " << 
		dec << i << "\t| " << 
		hex << i << "\t|" << endl;
	}
	return 0;
}

