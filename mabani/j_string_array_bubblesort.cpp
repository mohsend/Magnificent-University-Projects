//برنامه ای بنویسید که پنج رشته را از کاربر دریافت کند، سورت کند و مقادیر را چاپ کند.

#include <iostream>
#include <string>

using namespace std;

int main()
{
	void input(string[], int);
	void print(string[], int);
	void bubble_sort(string[], int);

	string str[5];

	input(str, 5);
	bubble_sort(str, 5);
	print(str, 5);
	
	cin.ignore();
	cin.get();
	return 0;
}

void input(string A[], int n)
{
	cout << "You will be prompted to enter " << n << " Strings.\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ")  ";
		getline(cin, A[i]);

	}
}

void print(string A[], int n)
{
	cout << "Here is the contents of your array:\n";
	for (int i = 0; i < n; i++)
		cout << i + 1 << ") " << A[i] << endl;
}
void bubble_sort(string A[], int n)
{
	bool flag = true;
	string temp;
	// do steps for n-1 times
	for (int i = 1; i < n && flag; i++)
	{
		flag = false;
		// compare each element with the one next to it
		for (int j = 0; j < n - i; j++)
		if (A[j] > A[j + 1])
		{
			temp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = temp;
			flag = true;
		}
	}
	cout << "Your array of strings is now sorted.\n";
}
