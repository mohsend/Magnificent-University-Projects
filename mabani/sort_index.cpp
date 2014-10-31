/*
sort w/o touching the original array
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int const NUM = 6;

int main()
{
	void input(int[], int[], int const);
	void sort(int[], int[], int);
	void output(int[], int[], int);

	int A[NUM], order[NUM];

	input(A, order, NUM);
	sort(A, order, NUM);
	output(A, order, NUM);
	
	cin.ignore();
	cin.get();
	return 0;
}

void input (int A[], int P[], int const n)
{
	cout << "Enter " << n << " integer numbers:\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ") ";
		cin >> A[i];
		P[i] = i;
	}
}

void sort (int A[], int P[], int n)
{
	/*
	in each step:
	* assume the first non-sorted index is the one with lowest value
	* check till end for lower
	* swap indexes if found
	*/
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			if (A[P[j]] < A[P[i]])
			{
				// swap indexes
				int temp = P[j];
				P[j] = P[i];
				P[i] = temp;
			}
}

void output(int A[], int P[], int n)
{
	void table_head (int);
	cout << "\n Here are the values you entered:\n";
	table_head(n);
	for (int i = 0; i < n; i++)
		cout << '|' << A[i] << '\t';

	cout << "\n Here are the values you entered, Sorted ascending:\n";
	table_head(n);
	for (int i = 0; i < n; i++)
		cout << '|' << A[P[i]] << '\t';

	cout << "\n Here are the values you entered, sorted decsending:\n";
	table_head(n);
	for (int i = (n - 1); i > -1; i--)
		cout << '|' << A[P[i]] << '\t';

	cout << '\n';
}

void table_head (int n)
{
	for (int i = 0; i < n; i++)
		cout << '|' << i + 1 << '\t';
	cout << '\n';
}