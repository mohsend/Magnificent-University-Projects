/*
 * XO game
*/

#include <iostream>

#define ROWS	3
#define COLS	3
using namespace std;

void show(char x[ROWS][COLS]);
void init(char x[ROWS][COLS]);
bool check(char x[ROWS][COLS]);
void get(char x[ROWS][COLS], int);
bool result(int sum);

int main()
{
	char x[ROWS][COLS];
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

void show(char x[ROWS][COLS])
{
	// print table head
	cout << "    ";
	for (int i = 0; i < COLS; i++)
		cout << i + 1 << "   ";
	cout << "\n";
	
	// print table
	for (int i = 0; i < ROWS; i++)
	{
		cout << i + 1 << " |";
		for (int j = 0; j < COLS; j++)
		{
			cout << ' ' << x[i][j] << " |";
		}
		cout << "\n  -------------" << endl;
	}
}

void init(char x[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			x[i][j] = ' ';
}

bool check(char x[ROWS][COLS])
{
	int sum = 0;

	// check horisontal (-) lines
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += x[i][j];
		}
		if (result(sum)) return true;
		sum = 0;
	}
	
	// check vertical (|) lines
	for (int j = 0; j < COLS; j++)
	{
		for (int i = 0; i < ROWS; i++)
		{
			sum += x[i][j];
		}
		if (result(sum)) return true;
		sum = 0;
	}
	
	// check left-to-right crossed (\) lines
	for (int i = 0; i < ROWS; i++)
	{
		sum += x[i][i];
	}
	if (result(sum)) return true;
	sum = 0;
	
	// check right-to-left crossed (/) lines
	for (int i = (ROWS - 1); i > -1; i--)
	{
		sum += x[i][i];
	}
	if (result(sum)) return true;
	sum = 0;
	
	// check if game ended as a draw
	sum = -1;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			sum += (x[i][j] == ' ');
	if (result(sum)) return true;
	
	return false;
}

bool result(int sum)
{
	if (sum == ROWS * 'X')
	{
		cout << "\n\tX Won!" << endl;
		return true;
	}
	else if (sum == ROWS * 'O')
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

void get(char x[ROWS][COLS], int round)
{
	int i, j;
	if (round % 2)
		cout << "X's turn, Place X:" << endl;
	else
		cout << "O's turn, Place O:" << endl;
		
	cout << "i) "; cin >> j;
	cout << "j) "; cin >> i;
	
	if ( (x[i-1][j-1] == 'X') || (x[i-1][j-1] == 'O') )
	{
		cout << "Already set. try another:" << endl;
		get (x, round);
	}
	else
	{
		x[i-1][j-1] = (round % 2) ? 'X' : 'O';
	}
}
