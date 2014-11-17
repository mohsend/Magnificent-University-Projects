/*
تمرین کلاسی اول جلسه سوم: برنامه ای بنویسید که پنج عدد صحیح از کاربر دریافت کند، سپس جمع و میانگین آن ها را نشان دهد.
*/

#include <iostream>
using namespace std;

int main()
{
	int count;
	int user_input;
	long sum = 0;
	cout << "Enter 5 integers, press Enter after each one.\n";
	for (count = 0; count < 5; count ++)
		{
		cout << count + 1 << ") ";
		cin >> user_input;
		sum += user_input;
		} 
		cout << "The sum of your numbers is: " << sum << "\nand the average of them is: " << sum/5.0 << "\n";
		
	cin.ignore();
	cin.get();
	return 0;
}
