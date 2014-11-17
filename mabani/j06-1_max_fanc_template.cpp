/*
برنامه ای بنویسید که سه عدد صحیح از کاربر دریافت کند و بزرگترین آنها را برگرداند.
همچنین با اعداد اعشاری و کارکتر هم همین کار را انجام دهد.
(Template )
*/

#include <iostream>

using namespace std;
template <typename T> 
T max(T, T, T);
int main()
{
	int a, b, c;
	cout << "Please enter 3 integer numbers: ";
	cin >> a >> b >> c;
	cout << "The biggest one is: " << max(a, b, c) << '\n';
	float d, e, f;
	cout << "Please enter 3 float numbers: ";
	cin >> d >> e >> f;
	cout << "The biggest one is: " << max(d, e, f) << '\n';
	char g, h, i;
	cout << "Please enter 3 characters: ";
	cin >> g >> h >> i;
	cout << "The biggest one is: " << max(g, h, i) << '\n';
	
	cin.ignore();
	cin.get();
	return 0;
}

template <typename T>
T max(T p1, T p2, T p3)
{
	T max;
	if (p1 > p2)
		max = p1;
	else
		max = p2;

	if (max < p3)
		max = p3;
	return max;
}

