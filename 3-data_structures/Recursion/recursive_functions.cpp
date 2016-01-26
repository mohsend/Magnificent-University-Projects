/*
 * 
 */

#include <iostream>
using namespace std;

// factorial
// n!
// en.wikipedia.org/wiki/Factorial
long int factorial(long int n)
{
	if (n == 1)
		return 1;
	return n * factorial(n-1);
}

// Exponentiation
// a^b
// https://en.wikipedia.org/wiki/Exponentiation
long int expo(long int a, long int b)
{
	if (b == 1)
		return a;
	return a * expo(a, b-1);
}

// Triangular number
// 1+2+3+...+n
// https://en.wikipedia.org/wiki/Triangular_number
int triangular(int n)
{
	if (n == 1)
		return 1;
	return n + triangular(n - 1);
}

// Fibonacci
// https://en.wikipedia.org/wiki/Fibonacci_number
int fibonacci(int n)
{
	if (n == 1 || n == 0)
		return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

// Modulo
// a%b
// https://en.wikipedia.org/wiki/Modulo_operation
int modulo(int a, int b)
{
	if (a < b)
		return a;
	return modulo(a-b, b);
}

// division
// a/b
// https://en.wikipedia.org/wiki/Division_(mathematics)
int division(int a, int b)
{
	if (a < b)
		return 0;
	return division(a-b, b) + 1;
}

// Combination
// https://en.wikipedia.org/wiki/Combination
int combination(int n, int k)
{
	if (k == 0 || n == k)
		return 1;
	return combination(n-1, k-1) + combination(n-1, k);
}

int combination2(int n, int k)
{
	return (factorial(n)/(factorial(k)*factorial(n-k)));
}

// Ackermann function
// https://en.wikipedia.org/wiki/Ackermann_function

// Addition
// a+b
// https://en.wikipedia.org/wiki/Addition
int add(int a, int b)
{
	if (b == 0)
		return a;
	return 1 + add(a, b-1);
}

// Multiplication
// a*b
// https://en.wikipedia.org/wiki/Multiplication
int mul(int a, int b)
{
	if (b == 1)
		return a;
	return a + mul(a, b-1);
}

// Lowest common denominator
// https://en.wikipedia.org/wiki/Lowest_common_denominator

// Least common multiple
// https://en.wikipedia.org/wiki/Least_common_multiple

// Greatest common divisor
// https://en.wikipedia.org/wiki/Greatest_common_divisor
int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

// Convert bases
// http://stackoverflow.com/questions/10375922/base-number-converter-from-10-base-with-recursive-function-c
int baseconvert(int decimal, int base)
{
	if (decimal == 0)
		return 0;
	return (decimal % base) + 10 * baseconvert(decimal/base, base);
}

int main(int argc, char **argv)
{
	cout << "9! = " << factorial(9) << endl;
	cout << "3^3 = " << expo(3, 3) << endl;
	cout << "1+2+3+...+20 = " << triangular(20) << endl;
	cout << "5th fibonacci number = " << fibonacci(5) << endl;
	cout << "10%3 = " << modulo(10, 3) << endl;
	cout << "10/3 = " << division(10, 3) << endl;
	cout << "c(5,2) = " << combination(5, 2) << endl;
	cout << "c(5,2) = " << combination2(5,2) << endl;
	cout << "10 + 12 = " << add(10, 12) << endl;
	cout << "10 * 12 = " << mul(10, 12) << endl;
	cout << "GCD(30, 15) = " << GCD(30, 15) << endl;
	cout << "GCD(17, 5) = " << GCD(17, 5) << endl;
	cout << "10 in base 7: " << baseconvert(10, 7) << endl;
	return 0;
}
