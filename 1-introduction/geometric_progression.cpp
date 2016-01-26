/*
 * https://en.wikipedia.org/wiki/Geometric_progression
 */

#include <iostream>

using namespace std;

int main()
{
	long int x, n, x_n = 1, sum = 1;
	cout << "Enter two positive integers:\nX = ";
	cin >> x;
	cout << "N = ";
	cin >> n;
	
	cout << "Geometric sequence: " << endl;
	for (int i = 1; i <= n; i++)
	{
		x_n *= x;
		cout << x <<'^' << i << " = " << x_n <<'\n';
		sum += x_n;
	}
	cout << "\nCalculated sum of the sequence: " << endl;
	cout << "1 + x + x^2 + ... + x^n = " << sum << endl;
	
	cout << "\nFormula for sum of geometric sequence: " << endl;
	cout << "(1 - x^(n+1) )/(1 - x) = " << ((1 - x_n * x) / (1 - x)) << endl;

	return 0;
}

