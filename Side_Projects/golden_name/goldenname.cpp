/*
 * 
 */

#include <iostream>
#include <string>
using namespace std;

string to_lowercase (string in);

int main()
{
	string name;
	
	do
	{
		int sum = 0;
		cout << "Enter name: ";
		cin >> name;
		name = to_lowercase(name);
		for (int i = 0; name[i]; i++)
		{
			sum += (int)(name[i] - 'a' + 1);
		}
		if (sum % name.length())
		{
			cout << name << ": No" << endl;
		}
		else
		{
			cout << name << ": Yes" << endl;
		}
	} while (name != "0");
	
	return 0;
}

string to_lowercase (string in)
{
	for (int i = 0; in[i]; i++)
	{
		if(in[i] <= 'Z' && in[i] >= 'A')
		{
			in[i] = in[i] - ('Z' - 'z');
		}
	}
	return in;
}
