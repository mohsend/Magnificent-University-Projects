// page 65 #17
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	void squre(int);
	int input;
	cout << "Enter desired squre size: ";
begir:	cin >> input;
	if (input < 3)
	{
	cout << "What is this? Squre for ants? Enter a bigger number:\n";
	goto begir;
	}
	squre(input);
	
	cin.ignore();
	cin.get();
	return 0;
}

void squre(int size)
{
	int height = 0;
	int width = 0;
	for (height; height < size; height ++)
	{
		for (width; width < size; width ++)
			cout << "\u25A0;";
	width = 0;
	cout << endl;
	}
}

