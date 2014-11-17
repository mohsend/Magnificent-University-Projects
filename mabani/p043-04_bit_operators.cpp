/*
تمرین کتاب: مثالی بزنید که در آن از عملگر های بیتی استفاده شده باشد. (فصل اول - مقدمات زبان سی پلاس پلاس - صفحه ۴۳ - تمرین ۴)
page 42 #4
*/

#include <iostream>
using namespace std;

int main()
{
	char input;
	char temp;
	cout << "Enter a character: ";
	cin >> input;
	temp = ~ input;
	cout << "When we NOT the bits, we get: " << temp;
	temp = input & 1;
	cout << "\nWhen we AND the bits with 1, we get: " << temp;
	temp = input | 1;
	cout << "\nWhen we OR the bits with 1, we get: " << temp;
	temp = input ^ 1;
	cout << "\nWhen we XOR the bits with 1, we get: " << temp;
	temp = input >> 1;
	cout << "\nWhen we shift the bits 1 bit to right, we get: " << temp;
	temp = input << 1;
	cout << "\nWhen we shift the bits 1 bit to left, we get: " << temp << endl;
	
	cin.ignore();
	cin.get();
	return 0;
}

