// برنامه ای بنویسید که پنج عدد صحیح از کاربر دریافت کند، بزرگ ترین و کوچک ترین آن ها را مشخص کند، و فاصله ی هرکدام از آن ها را با بزرگترین و کوچکترین عدد نمایش دهد.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int inputs[5];
	int max, min;
	cout << "You will be prompted for 5 integer numbers: \n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the " << i + 1 << "th one: ";
		cin >> inputs[i];
		if (i == 0)
			min = max = inputs[i];
		else
		{
			/*
			if (inputs[i] < min)

				min = inputs[i];

			if (inputs[i] > max)

				max = inputs[i];
			*/
			max = (max > inputs[i]) ? max : inputs[i];
			min = (min < inputs[i]) ? min : inputs[i];
		}
	}
	cout << "Maximum = " << max;
	cout << "\nMinimum = " << min << '\n';
	for (int i = 0; i < 5; i++)
	{
		cout << "\nDifference between " << i + 1 << "th one and min = " << inputs[i] - min << "\nDifference between " << i + 1 << "th one and max = " << max - inputs[i];
	}
	
	cin.ignore();
	cin.get();
	return 0;
}
