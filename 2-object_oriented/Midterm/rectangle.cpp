/*
 * 
 */

#include <iostream>
using namespace std;

class rectangle
{
	private:
		int length, width;
	public:
		rectangle(int l, int w)
		{
			length = l;
			width = w;
		}
		int getArea()
		{
			return length*width;
		}
		int getPerimeter()
		{
			return 2*(length+width);
		}
};

int main()
{
	int l, w;
	
	cout << "enter the length: "; cin >> l;
	cout << "enter the width: "; cin >> w;
	
	rectangle test(l, w);
	
	cout << "the area: " << test.getArea() << "\nthe perimeter: " << test.getPerimeter();
	return 0;
}
