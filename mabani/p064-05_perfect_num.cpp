/*
تمرین کتاب: برنامه ای بنویسید که اعدادی را که از ورودی خوانده تشخیص دهد که آیا عدد مورد نظر کامل است یا خیر. عددی کامل است که مجموع مقسوم علیه های آن (به جز خودش) برابر با آن عدد باشد. پس از برسی هر عدد برنامه باید از کاربر سوال کند میخواهد به کارش ادامه دهد یا خیر.  (فصل دوم - ساختار های کنترلی - صفحه ۶۴ - تمرین۵)
*/

#include <iostream>
using namespace std;

int main()
{
	unsigned int input, count, sum = 0;

	cout << "Enter a positive integer: ";
	cin >> input;
	while (input != 0)
	{
		for (count = 1; count < input; count ++)
		{
		if (input % count == 0)
			sum += count;
		}

		if (sum == input)
			cout << '\t' << input <<" IS a Perfect Number!\n";
		else
			cout << '\t' << input <<" is NOT a Perfect Number!\n";
		sum = 0;
		cout << "Enter another number or enter '0' to end program.\n";
		cin >> input;
	}
	
	cin.ignore();
	cin.get();
	return 0;
}
