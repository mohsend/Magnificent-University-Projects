/*
The aim of this program is to get seconds and give human readable time.
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	void converter (long unsigned int);
	long unsigned int seconds;

	cout << "Enter a time in seconds, this program will convert it to human readable time: ";
	cin >> seconds;
	cout << seconds << " seconds is equal to ";
	converter(seconds);
	cout << endl;
	
	cin.ignore();
	cin.get();
	return 0;
}

void converter (long unsigned int secs)
{
	cout << secs / 86400 << " Day(s) and ";
	secs = secs % 86400;
	cout << secs / 3600 << " Hour(s) and ";
	secs = secs % 3600;
	cout << secs / 60 << " Minute(s) and ";
	secs = secs % 60;
	cout << secs << " Second(s).";
}
