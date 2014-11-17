/*
برنامه ای بنویسید که این مسئله را با استفاده از آرایه یک بعدی احل کند.
بیست عدد هر کدام بین ده تا صد را از ورودی بخواند و چنانچه تکراری نباشد در آرایه قرار دهد.
سپس این عناصر را به خروجی ببرد
*/

#include <iostream>

using namespace std;

int const MANY = 20;

int main()
{
	int input(int[], int);
	void output(int[], int);

	int A[MANY], array_size;

	cout << "You will be prompted to Enter " << MANY << " numbers each ranging between 10 to 100:\n";
	array_size = input(A, MANY);
	cout << "Here are your entered values, excluding duplicates:\n";
	output(A, array_size);

	cin.ignore();
	cin.get();
	return 0;
}

int input(int A[], int n)
{
	int userin, array_end = 0;
	bool range, dup;
	// Gets 20 numbers
	for (register int i = 0; i < n; i++)
	{
		// Gets the number and check the range
		do
		{
			cout << i + 1 << ") ";
			cin >> userin;
			range = (userin > 10 && userin < 100);
			if (!range)
				cout << "\n !!! 10 < N < 100 !!! \n Try Again: \n";
		} while (!range);
		// checks for duplicate
		dup = false;
		for (int j = 0; j < array_end; j++)
		{
			if (A[j] == userin)
			{
				dup = true;
				break;
			}
		}
		// if not duplicate then add to array
		if (!dup)
		{
			A[array_end] = userin;
			array_end++;
		}
	}
	// returns size of array
	return array_end;
}
void output(int A[], int n)
{
	for (register int i = 0; i < n; i++)
		cout << i + 1 << ") " << A[i] << '\n';
}
