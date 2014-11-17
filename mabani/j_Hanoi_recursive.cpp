// برنامه ای بنویسید که با استفاده از تابعی برگشتی مراحل حل بازی برج هانوی را برای تعداد اکس دیسک نمایش دهد.
// http://fa.wikipedia.org/wiki/%D8%A8%D8%B1%D8%AC_%D9%87%D8%A7%D9%86%D9%88%DB%8C
// http://www.mathsisfun.com/games/towerofhanoi.html

#include <iostream>
using namespace std;
void hanoy(char, char, char, unsigned int);
int main()
{
	unsigned int x;
	cout << "Enter the number of desired discs in the tower of Hanoi: ";
	cin >> x;
	hanoy('A', 'B', 'C', x);
	
	cin.ignore();
	cin.get();
	return 0;
}

void hanoy(char source, char help, char target, unsigned int n)
{
	if (n == 1)
	{
		cout << source << " ==> " << target << '\n';
		return;
	}
	hanoy(source, target, help, n - 1);
	cout << source << " ==> " << target << '\n';
	hanoy(help, source, target, n - 1);
}
