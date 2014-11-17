/*
صفحه ۶۵ - تمرین ۱۸: برنامه ای بنویسید که دو مقدار اعشاری را از ورودی خوانده و تفاضل حاصل ضرب و حاصل تقسیم آن ها را محاسبه کرده، به خروجی ببرد. برنامه وقتی خاتمه می یابد که هر دو عدد اعشاری صفر باشند.
*/

#include <iostream>
using namespace std;

int main()
{
	float a, b;
	cout << "\n === You can always end the program by entering both values as '0' ===\n";
	do
	{
		cout << "\nEnter two float numbers:\n A = ";
		cin >> a;
		cout << " B = ";
		cin >> b;
		cout << "\n (A * B) - (A / B) = " << ((a * b) - (a / b)) << '\n';
	} while (a || b);

	cout << "\n Goodbye!\n";
	cin.ignore();
	cin.get();
	return 0;
}
