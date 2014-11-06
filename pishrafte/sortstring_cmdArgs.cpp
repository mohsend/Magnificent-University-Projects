/*
سورت با روش سورت من در آوردی.
 رشته ها به صورت کامندلاین آرگومنت گرفته میشوند.
*/

#include <iostream>
#include <string>

using namespace std;

void mohsen_sort(string[], unsigned int);
void output(string[], unsigned int);

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "I need at least 1 argument (string) to do anything.\n";
		return 0;
	}
	
	// convert commandline arguments to strings
	unsigned int stringsc = argc - 1;
	string argstring[stringsc];
	for (unsigned int i = 0; i < stringsc; i++)
	{
		argstring[i] = argv[(i + 1)];
	}
	
	mohsen_sort(argstring, stringsc);
	output(argstring, stringsc);

	return 0;
}

void mohsen_sort(string A[], unsigned int n)
{
	unsigned int end;
	string temp;
	end = n - 1;
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < end; j++)
		if (A[j] > A[end])
		{
			temp = A[end];
			A[end] = A[j];
			A[j] = temp;
		}
		end--;
	}
}

void output(string A[], unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		cout << A[i] << ' ';
	}
	cout << endl;
}
