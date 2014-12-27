/*
 * p175 - #5
 */

#include <iostream>
#include <string>
using namespace std;

string remove_duplicate(string in, unsigned int lenght);
string remove_spaces(string in, unsigned int len);

int main()
{
	string input;
	cin >> input;
	
	unsigned int len;
	for (unsigned int i = 0; input[i]; i++)
	{
		len = (i + 1);
	}
	
	cout << remove_duplicate(input, len);
	return 0;
}

string remove_duplicate(string in, unsigned int len)
{
	char temp;
	for(unsigned int i = 0; i < len; i++)
	{
		temp = in[i];
		for(unsigned int j = (i + 1); j < len; j++)
		{
			if(temp == in[j])
			{
				in[j] = ' ';
			}
		}
	}
	return remove_spaces(in, len);
}

string remove_spaces(string in, unsigned int len)
{
	char temp[len];
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
