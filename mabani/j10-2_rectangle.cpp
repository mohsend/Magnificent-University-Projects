//برنامه ای بنویسید که توسط فانکشن اینپوت مقدار طول و عرض مستطیل را از کاربر بگیرد، توسط فانکشن کلکولیت مساحت و محیط را حساب کند و توسط فانکشن پرینت مقادیر را چاپ کند.

#include "stdafx.h"
#include <iostream>

using namespace std;

void input(float *);
void calculate(float *);
void print(float *);

int main()
{
	float in[2];
	input(in);
	calculate(in);
	print(in);
	
	cin.ignore();
	cin.get();
	return 0;
}
void input(float * po)
{
	cout << "Enter length: ";
	cin >> *po;
	cout << "And width: ";
	cin >> *(po + 1);
}
void calculate(float * po)
{
	float sur;
	sur = ((*po) * (*(po + 1)));
	*po = (*po + *(po + 1)) * 2;
	*(po + 1) = sur;
}
void print(float * po)
{
	cout << "Surface: " << *po << "\nPerimeter: " << *(po + 1) << '\n';
}