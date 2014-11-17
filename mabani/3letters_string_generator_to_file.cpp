/*
این برنامه همه ی رشته های ممکن بین 
aaa to zzz
را تولید میکند.
*/

#include <iostream>
// <fstream> hasn't been covered in the class. if you don't know what it is, don't worry.
// it stands for "File Stream". it can create, open, write and manipulate files.
#include <fstream>
using namespace std;

int main()
{
	// the character '`' is the one right before 'a' in ASCII table.
	char ch1 = '`', ch2 = '`', ch3 = '`';
	ofstream myfile;
	// look for the generated file in the same folder as the cpp file. typicaly: C:\Users\your_username\Documents\Visual Studio 2013\Projects\proj_name\proj_name\
	myfile.open ("3letter_strings.txt", ios::trunc);
	for (int z = 0; z < 26; z++)
	{
		ch1++;
		ch2 = '`';
		for (int i = 0; i < 26; i++)
		{
			ch2++;
			ch3 = '`';
			for (register int j = 0; j < 26; j++)
			{
				ch3++;
				myfile << ch1 << ch2 << ch3 << '\n';
			}
		}
	}
	myfile.close();
	return 0;
}
