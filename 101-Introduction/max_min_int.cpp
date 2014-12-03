/*

*/

#include <iostream>
using namespace std;

int main()
{
	int max, min, input;
	cout << "enter 5 integers: \n";
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " )";
		cin >> input;
		
		if (i == 0)
			min = max = input;
		if (input < min)
			min = input;
		if (input > max)
			max = input;
	}
	
	cout << "min: " << min << ", max: " << max;
	return 0;
}
