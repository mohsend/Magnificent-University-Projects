/*
 * convey's game of life
*/

#ifndef GOL_HPP
#define GOL_HPP 1

#include <iostream>
#include <fstream>
#include <cstdlib>

#define GOL_WIDTH	32
#define	GOL_HEIGHT	32

using namespace std;

class gameOfLife {
	public:
		gameOfLife();
		void init_file (char*);
		void play();
	private:
		bool life[GOL_WIDTH][GOL_HEIGHT];
		void show();
		void nextgen();
};

void gameOfLife::show()
{
	for (int i = 0; i < GOL_HEIGHT; i++)
	{
		for (int j = 0; j < GOL_WIDTH; j++)
		{
			(life[j][i]) ? cout << " #" : cout << "  ";
		}
		cout << '\n';
	}
}

void gameOfLife::nextgen()
{
	// count every pixel's neighbors and store them in an array
	short int neighbors[GOL_WIDTH][GOL_HEIGHT];
	for (int i = 1; i < GOL_WIDTH - 1; i++)
	{
		for (int j = 1; j < GOL_HEIGHT - 1; j++)
		{
			// calculate the number of neighbors of the pixel
			// The Moore neighborhood checks all 8 surrounding cells
			neighbors[i][j] = 
				life[i - 1][j - 1] +
				life[i - 1][j] +
				life[i - 1][j + 1] +
				life[i][j - 1] +
				life[i][j + 1] +
				life[i + 1][j - 1] +
				life[i + 1][j] +
				life[i + 1][j + 1];
		}
	}
	// calculate the state of each pixel in the next generation
	for (int i = 0; i < GOL_WIDTH; i++)
		for (int j = 0; j < GOL_HEIGHT; j++)
		{
			// if it has 3 neighbors it comes to life
			if (neighbors[i][j] == 3)
			{
				life[i][j] = true;
			}
			// if it has 2 neighbors it remains the same
			// every other senario it dies
			else if (neighbors[i][j] != 2)
			{
				life[i][j] = false;
			}
		}
}

gameOfLife::gameOfLife()
{
	// loop through every pixel and assign a random value to it
	srand (time(NULL));
	for (int i = 1; i < GOL_WIDTH - 1; i++)
	{
		for (int j = 1; j < GOL_HEIGHT - 1; j++)
		{
			life[i][j] = rand() % 2;
		}
	}
}

void gameOfLife::init_file (char* filename)
{
	// loop through every non-whitespace charecter in a file and initialize the generation zero
	char ch;
	cout << "Initialized with " << filename << ":\n";
	fstream fin(filename, fstream::in);
	for (int j = 0; j < GOL_HEIGHT; j++)
	{
		for (int i = 0; i < GOL_WIDTH; i++)
		{
			fin >> skipws >> ch;
			life[i][j] = (ch == '#');
		}
	}
}

void gameOfLife::play()
{
	for (int gen = 0; true; gen++)
	{
		cout << "Generation: " << gen << '\n';
		show();
		nextgen();
		// intrupt to let the user see the results. enter 'q' to end the game.
		if (cin.get() == 'q') break;
	}
}

#endif
