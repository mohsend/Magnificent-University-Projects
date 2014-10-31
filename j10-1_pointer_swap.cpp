//تمرین اول جلسه ده: برنامه ای بنویسید که دو عدد اعشاری دلخواه را توسط تابع اینپوت دریافت بکند، سپس توسط فاکشن سوپ جا به چا و توسط پرینت مقادیر را برگرداند.

#include "stdafx.h"
#include <iostream>

using namespace std;

void input(float *);
void swap(float *);
void print(float *);
void print_alt(float []);

int main()
{
	float in[2];
	input(in);
	swap(in);
	print(in);
	print_alt(in);
	
	cin.ignore();
	cin.get();
	return 0;
}
void input(float * po)
{
	cout << "Why won't you enter 2 float numbers for me? \n1: ";
	cin >> *po;
	cout << "2: ";
	cin >> *(po + 1);
}
void swap(float * po)
{
	float temp;
	temp = *po;
	*po = *(po + 1);
	*(po + 1) = temp;
}
void print(float * po)
{
	cout << "I swapped the values, what is that good for? I don't have a clue either. \nbut here you go anyway:\n";
	cout << "1: " << *po << "\n2: " << *(po + 1) << '\n';
}
void print_alt(float F[2])
{
	cout << "Your swapped values, this time using array syntax! how cool is that?\n";
	cout << "1: " << F[0] << "\n2: " << F[1] << '\n';
}