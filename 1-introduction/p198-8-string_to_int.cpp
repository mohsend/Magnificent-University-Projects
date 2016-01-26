/*
 * 
 */

#include <iostream>
using namespace std;

int string_to_int(char*);

int main()
{
	char input[15];
	cin >> input;
	cout << string_to_int(input);
	return 0;
}

int string_to_int(char* in)
{
	int res = 0;
	int power = 1;
	char *rightmost;
	
	// finds the least significant (rightmost) char and assign a pointer to it
	for(int i = 0; *(in + i); i++)
	{
		rightmost = (in + i);
	}
	
	// turns each char into the repesenting digit, multiply it by it power of ten and sums it with res.
	for(int i = 0; *(rightmost - i); i++)
	{
		if ( *(rightmost - i) >= '0' && *(rightmost - i) <= '9')
		{
			res += (*(rightmost - i) - '0') * power;
			power *= 10;
		}
		else if ((*(rightmost - i) == '-') && (rightmost - i) == in)
		{
			res *= -1;
		}
		else
		{
			cout << "Illigal character." << endl;
		}
	}
	
	return res;
}
