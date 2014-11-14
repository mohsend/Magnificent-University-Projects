/*
 * simple 3x3 XO game.
 * source available at http://dstjrd.ir/s/cppx (MIT licence)
*/

#include <iostream>

using namespace std;

void show(char xo[3][3]);
void init(char xo[3][3]);
bool check(char xo[3][3]);
void get(char xo[3][3], int round);
bool result(int sum);

int main()
{
	char xo[3][3];
	int round = 0;
	init(xo);
	
	while (!check(xo))
	{
		show(xo);
		get(xo, round++);
	}
	return 0;
}

void show(char xo[3][3])
{
	// print table head
	cout << "    ";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "   ";
	}
	cout << "\n";
	
	// print table
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " |";
		for (int j = 0; j < 3; j++)
		{
			cout << ' ' << xo[i][j] << " |";
		}
		cout << "\n  -------------" << endl;
	}
}

void init(char xo[3][3])
{
	char *ptr = &xo[0][0];
	for (int i = 0; i < 9; i++)
	{
		*(ptr + i) = ' ';
	}
}

bool check(char xo[3][3])
{
	int sum;

	// check horisontal (-) lines
	for (int i = 0; i < 3; i++)
	{
		sum = xo[i][0] + xo[i][1] + xo[i][2];
		if (result(sum)) return true;
	}
	
	// check vertical (|) lines
	for (int j = 0; j < 3; j++)
	{
		sum = xo[0][j] + xo[1][j] + xo[2][j];
		if (result(sum)) return true;
	}
	
	// check left-to-right crossed (\) lines
	sum = xo[0][0] + xo[1][1] + xo[2][2];
	if (result(sum)) return true;
	
	// check right-to-left crossed (/) lines
	sum = xo[0][2] + xo[1][1] + xo[2][0];
	if (result(sum)) return true;
	
	// check if game ended as a draw
	sum = -1;
	char *ptr = &xo[0][0];
	for (int i = 0; i < 9; i++)
	{
		sum += (*(ptr + i) == ' ');
	}
	if (result(sum)) return true;
	
	return false;
}

bool result(int sum)
{
	char ch = sum / 3;
	if ( (ch == 'X') || (ch == 'O') )
	{
		cout << "\n\t" << ch << " Won!" << endl;
		return true;
	}
	else if (sum == -1)
	{
		cout << "\n\tit's a Draw!" << endl;
		return true;
	}
	return false;
}

void get(char xo[3][3], int round)
{
	int i, j;
	char ch = (round % 2) ? 'X' : 'O';
	
	cout << ch << "'s turn, Place " << ch << " on:" << endl;
	cout << "i) "; cin >> j;
	cout << "j) "; cin >> i;
	
	if (xo[i-1][j-1] != ' ')
	{
		cout << "Already set. try another:" << endl;
		get(xo, round);
	}
	else if ( (i > 3) || (i < 1) || (j > 3) || (j < 1) )
	{
		cout << "1,2 and 3 are the only acceptable values for i and j." << endl;
		get(xo, round);
	}
	else
	{
		xo[i-1][j-1] = ch;
	}
}
