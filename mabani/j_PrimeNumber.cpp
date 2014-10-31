//برنامه ای بنویسید تمام اعداد اول بین دو تا صد را چاپ کند

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int i;
	bool prime(int);
	for (i = 2; i < 101; i++)
	if (prime(i))
		cout << i << '\t';
		
	cin.ignore();
	cin.get();
	return 0;
}
bool prime(int x)
{
	for (int z = 2; z<x/2+1;z++)
	if (x % z == 0)
		return false;
	return true;
}
