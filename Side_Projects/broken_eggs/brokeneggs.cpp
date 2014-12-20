/*
 * a c++ way to answer the "broken eggs" problem:
 * http://mathforum.org/library/drmath/view/58849.html
 */

#include <iostream>
using namespace std;

int main()
{
	int temp;
	for (int i = 1; i < 10000; i++)
	{
		temp = i * 7;
		if ( (temp % 4 == 1) && (temp % 5 == 1) && (temp % 6 == 1) )
		{
			cout << temp << endl;
		}
	}
	return 0;
}
