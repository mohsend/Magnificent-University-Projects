//برنامه ای بنویسید که توسط فانکشن اینپوت مقدار پنج عدد صحیح را از کاربر دریافت کند، داخل یک آرایه ذخیره کند، آنها را جا به جا کند و مقادیر را چاپ کند.اجازه ی استفاده از اندیس آرایه را ندارید.

#include "stdafx.h"
#include <iostream>

using namespace std;

void input(int *,int);
void print_swaped(int *, int);

int main()
{
	int in[5];
	input(in,5);
	print_swaped(in,5);
	
	cin.ignore();
	cin.get();
	return 0;
}

void input(int * po, int num_elements)
{
	cout << "Enter 5 integer numbers:\n";
	for (int i = 0; i < num_elements; i++)
	{
		cout << i + 1 << ": ";
		cin >> *(po + i);
		// alternatively the line above can be: cin >> p[i];
	}
}

void print_swaped(int * po, int num_elements)
{
	cout << "Here is the reversed values of the array:\n";
		for (int i = (num_elements - 1); i > -1; i--)
			cout << num_elements - i << ": " << *(po + i) <<'\n';
}