/*
 * Calculates the trailing zeros of a n! (Factorial)
 */

#include <stdio.h>

int trailingZerosOfFactorial(int n);

int main(int argc, char **argv)
{
	int n = 0;
	printf("Enter an integer: ");
	scanf("%d", &n);
	printf("%d! has %d trailing zeros.", n, trailingZerosOfFactorial(n));
	return 0;
}

int trailingZerosOfFactorial(int n)
{
	int multipliesof5 = 0;
	for (int i = 5; i <= n; i *= 5)
	{
		multipliesof5 += n / i;
	}
	return multipliesof5;
}
