// mohsen_sort.cpp : Defines the entry point for the console application.
// سورت با روش سورت من در آوردی.

#include <iostream>
using namespace std;

int main()
{
	int A[5];
	void mohsen_sort(int[], int);
	void input(int[], int);
	void output(int[], int);

	input(A, 5);
	mohsen_sort(A, 5);
	output(A, 5);
	
	cin.ignore();
	cin.get();
	return 0;
}
void mohsen_sort(int A[], int n)
{
	int end, temp;
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
void input(int A[], int n)
{
	cout << "You will be prompted to enter " << n << "integer numbers.\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ") ";
		cin >> A[i];
	}
}
void output(int A[], int n)
{
	cout << "Here is the contents of the array:";
	for (int i = 0; i < n; i++)
		cout << '\n' << i + 1 << ") " << A[i];
}

