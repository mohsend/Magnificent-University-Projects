// imperial_lenght_to_metric.cpp : Defines the entry point for the console application.
// pgae 95 - 5

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double input_imperial();
	double converter(double);
	void print(double);
	print(converter(input_imperial()));
	
	cin.ignore();
	cin.get();
	return 0;
}

double input_imperial()
{
	double feet, inches;
	cout << "How many feet?\n";
	cin >> feet;
	cout << "And how many inches?\n";
	cin >> inches;
	inches += feet * 12.0;
	return inches;
}

double converter(double inches)
{
	return inches * 2.54;
}

void print(double centimeters)
{
	cout << "That's about " << int(centimeters)/100 << " meters and " << int(centimeters) % 100 << " centimeters.\n";
}
