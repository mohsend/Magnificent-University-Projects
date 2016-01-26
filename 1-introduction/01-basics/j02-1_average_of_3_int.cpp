/*
تمرین اول جلسه دوم.
برنامه ای بنویسید که سه عدد صحیح را از کاربر دریافت کند، حاصل جمع و میانگین را حساب کند و نتایج را نشان دهد.
*/
// pre-prosessor commands
#include <iostream>
#include <iomanip>

using namespace std;
// تعریف متغیر ها
int x1, x2, x3;

int main()
{
// سه عدد از کاربر دریافت کند
	cout << "Enter three integers, seperate with space or enter key: \n"; 
	cin >> x1 >> x2 >> x3;
// حاصل جمع حساب کند
	long int sum = x1 + x2 + x3;
// میانگین حساب کند
	float average = (float)sum/3;
// نتایج را نشان دهد
	cout.fill('*');
	cout << "sum = " << setw(5) << sum << "\naverage = " << setprecision (5) << scientific << average << endl;

	cin.ignore();
	cin.get();
	return 0;
}
