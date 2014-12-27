/*
 * p175 - #5
 */

#include <iostream>
#include <string>
using namespace std;

string remove_duplicate(string in);
string remove_spaces(string in);

int main()
{
	string input;
	cin >> input;
	string nodup = remove_duplicate(input);
	cout << nodup << endl;
	cout << remove_spaces(nodup) << endl;
	return 0;
}

string remove_duplicate(string in)
{
	char temp;
	for(unsigned int i = 0; in[i]; i++)
	{
		temp = in[i];
		for(unsigned int j = (i + 1); in[j]; j++)
		{
			if(temp == in[j])
			{
				in[j] = ' ';
			}
		}
	}
	return in;
}

string remove_spaces(string in)
{
	char temp[30];
	unsigned int j = 0; 
	for(unsigned int i = 0; in[i]; i++)
	{
		if(in[i] != ' ')
		{
			temp[j] = in[i];
			j++;
		}
	}
	temp[j] = '\0';
	return temp;
}
