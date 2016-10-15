/*
 * a c++ way to answer the "broken eggs" problem:
 * http://mathforum.org/library/drmath/view/58849.html
 */

#include <iostream>
using namespace std;

int main()
{
	// We can add 6 to 'i' at a time, because we know 'i' isn't divisible by 2 or 6
	for (int i = 1; i < 10000; i += 6)
	{
		int temp = i * 7;
		if ( (temp % 4 == 1) && (temp % 5 == 1) && (temp % 6 == 1) )
		{
			cout << temp << endl;
		}
	}
	return 0;
}
