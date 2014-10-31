/*
سورت با روش سورت من در آوردی.
*/

#include <iostream>
#include <string>

#define HOWMANY	5

using namespace std;

void mohsen_sort(string[], int);
void input(string[], int);
void output(string[], int);

int main()
{
	string A[HOWMANY];

	input(A, HOWMANY);
	mohsen_sort(A, HOWMANY);
	output(A, HOWMANY);

	return 0;
}

void mohsen_sort(string A[], int n)
{
	int end;
	string temp;
	end = n - 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < end; j++)
		if (A[j] > A[end])
		{
			temp = A[end];
			A[end] = A[j];
			A[j] = temp;
		}
		end--;
	}
	cout << "The array is now sorted.\n";
}

void input(string A[], int n)
{
	cout << "You will be prompted to enter " << n << " integer numbers.\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ") ";
		cin >> A[i];
	}
}

void output(string A[], int n)
{
	cout << "Here is the contents of the array:";
	for (int i = 0; i < n; i++)
		cout << '\n' << i + 1 << ") " << A[i];
}

