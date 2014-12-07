/*
 * 
*/

#include <iostream>
using namespace std;

int main()
{
	float grade;
	do
	{
		cout << "enter grade (0-20) as a float: ";
		cin >> grade;
		cout << "it's equal to (A-F): " << (char)('F' - (grade / 4)) << endl;
	} while (grade != 0);
	return 0;
}
