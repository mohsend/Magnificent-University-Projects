// page 65 #17
#include "stdafx.h"
#include <iostream>
using namespace std;
int height = 0;
int width = 0;
int input;

int main()
{
	cout << "Enter desired squre size: ";
begir:	cin >> input;
	if (input < 3)
	{
	cout << "What is this? Squre for ants? Enter a bigger number:\n";
	goto begir;
	}
	for (height; height < input; height ++)
	{
		for (width; width < input; width ++)
		cout << "\u25A0;";
	width = 0;
	cout << endl;
	}
	
	cin.ignore();
	cin.get();
	return 0;
}

