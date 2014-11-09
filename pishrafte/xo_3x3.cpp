/*
 * simple 3x3 XO game.
 * source available at http://dstjrd.ir/s/cppx (MIT licence)
*/

#include <iostream>

using namespace std;

void show(char x[3][3]);
void init(char x[3][3]);
bool check(char x[3][3]);
void get(char x[3][3], int);
bool result(int sum);

int main()
{
	char x[3][3];
	int round = 0;
	init(x);
	show(x);
	
	while (!check(x))
	{
		get(x, round++);
		show(x);
	}
	return 0;
}

void show(char x[3][3])
{
	// print table head
	cout << "    ";
	for (int i = 0; i < 3; i++)
		cout << i + 1 << "   ";
	cout << "\n";
	
	// print table
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " |";
		for (int j = 0; j < 3; j++)
		{
			cout << ' ' << x[i][j] << " |";
		}
		cout << "\n  -------------" << endl;
	}
}

void init(char x[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			x[i][j] = ' ';
}

bool check(char x[3][3])
{
	int sum;

	// check horisontal (-) lines
	for (int i = 0; i < 3; i++)
	{
		sum = x[i][0] + x[i][1] + x[i][2];
		if (result(sum)) return true;
	}
	
	// check vertical (|) lines
	for (int j = 0; j < 3; j++)
	{
		sum = x[0][j] + x[1][j] + x[2][j];
		if (result(sum)) return true;
	}
	
	// check left-to-right crossed (\) lines
	sum = x[0][0] + x[1][1] + x[2][2];
	if (result(sum)) return true;
	
	// check right-to-left crossed (/) lines
	sum = x[0][2] + x[1][1] + x[2][0];
	if (result(sum)) return true;
	
	// check if game ended as a draw
	sum = -1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			sum += (x[i][j] == ' ');
	if (result(sum)) return true;
	
	return false;
}

bool result(int sum)
{
	if (sum == 3 * 'X')
	{
		cout << "\n\tX Won!" << endl;
		return true;
	}
	else if (sum == 3 * 'O')
	{
		cout << "\n\tO Won!" << endl;
		return true;
	}
	else if (sum == -1)
	{
		cout << "\n\tit's a Draw!" << endl;
		return true;
	}
	return false;
}

void get(char x[3][3], int round)
{
	int i, j;
	char ch = (round % 2) ? 'X' : 'O';
	
	cout << ch << "'s turn, Place " << ch << ":" << endl;
	cout << "i) "; cin >> j;
	cout << "j) "; cin >> i;
	
	if (x[i-1][j-1] != ' ')
	{
		cout << "Already set. try another:" << endl;
		get(x, round);
	}
	else if ( (i > 3) || (i < 1) || (j > 3) || (j < 1) )
	{
		cout << "1,2 and 3 are the only acceptable values for i and j." << endl;
		get(x, round);
	}
	else
	{
		x[i-1][j-1] = ch;
	}
}
