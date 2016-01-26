/*
 * use "for" in place of if
 */

#include "sdafx.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	cout << "enter a number less than 10" << endl;
	int input;
	cin >> input;
	for (int i = 1; (input < 10) && i ; i = 0) // if (input < 10)
	{
		cout << "right!" << endl;
	}
	for (int i = 1; (!(input < 10) && i) ; i = 0) // else
	{
		cout << "WRONG!" << endl;
	}
	return 0;
}
