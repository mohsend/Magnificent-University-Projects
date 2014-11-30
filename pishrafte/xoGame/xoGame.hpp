/*
 * simple 3x3 XO game.
 * Object Oriented version.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
*/

#include <iostream>

#ifndef SevenSegment_hpp
#define SevenSegment_hpp

using namespace std;

class xoGame
{
	public:
		xoGame();
		void play();
	private:
		char A[3][3];
		char * const ptr = &A[0][0];
		void show();
		bool check();
		void get(int round);
		bool result(int sum);
};

xoGame::xoGame()
{
	for (int i = 0; i < 9; i++)
	{
		*(ptr + i) = ' ';
	}
}

void xoGame::show()
{
	cout << "    1   2   3\n"; // table head
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " |";
		for (int j = 0; j < 3; j++)
		{
			cout << ' ' << A[i][j] << " |";
		}
		cout << "\n  -------------" << endl;
	}
}

bool xoGame::check()
{
	int sum;
	bool res = false;

	// check horisontal (-) lines
	for (int i = 0; i < 3; i++)
	{
		sum = A[i][0] + A[i][1] + A[i][2];
		res += result(sum);
	}
	
	// check vertical (|) lines
	for (int j = 0; j < 3; j++)
	{
		sum = A[0][j] + A[1][j] + A[2][j];
		res += result(sum);
	}
	
	// check left-to-right crossed (\) lines
	sum = A[0][0] + A[1][1] + A[2][2];
	res += result(sum);
	
	// check right-to-left crossed (/) lines
	sum = A[0][2] + A[1][1] + A[2][0];
	res += result(sum);
	
	// check if game ended as a draw
	sum = -1;
	for (int i = 0; i < 9; i++)
	{
		sum += (*(ptr + i) == ' ');
	}
	res += result(sum);
	
	return res;
}

bool xoGame::result(int sum)
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

void xoGame::get(int round)
{
	int i, j;
	char ch = (round % 2) ? 'X' : 'O';
	
	cout << ch << "'s turn, Place " << ch << " on:" << endl;
	cout << "i) "; cin >> j;
	cout << "j) "; cin >> i;
	
	if ( (i > 3) || (i < 1) || (j > 3) || (j < 1) )
	{
		cout << "1,2 and 3 are the only acceptable values for i and j." << endl;
		get(round);
	}
	else if (A[i-1][j-1] != ' ')
	{
		cout << "Already set. try another:" << endl;
		get(round);
	}
	else
	{
		A[i-1][j-1] = ch;
	}
}

void xoGame::play()
{
	int round = 0;
	
	show();
	while (!check())
	{
		get(round++);
		show();
	}
}

#endif
