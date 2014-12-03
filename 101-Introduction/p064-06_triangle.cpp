// page 64 #6

#include <iostream>
using namespace std;
int height = 0;
int width = 0;
int input;

int main()
{
	cout << "Enter desired height of the triangle: ";
	cin >> input;
	for (height; height < input; height ++)
	{
		for (width; width < height; width ++ )
		cout << "*";
	cout << endl;
	width = 0;
	}
	
	cin.ignore();
	cin.get();
	return 0;
}

