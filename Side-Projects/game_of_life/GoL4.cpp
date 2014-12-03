/*
convey's game of life
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

#define	HEIGHT	32
#define WIDTH		32

void show(bool life[WIDTH][HEIGHT]);
void nextgen(bool life[WIDTH][HEIGHT]);
void init_rand(bool life[WIDTH][HEIGHT]);
void init_file (bool life[WIDTH][HEIGHT]);

int main()
{
	bool life[WIDTH][HEIGHT];
	init_file(life);
	for (int gen = 0; true; gen++)
	{
		cout << gen << '\n';
		show(life);
		nextgen(life);
		cin.get();
		//system("sleep .1");
	}
	return 0;
}

void show(bool life[WIDTH][HEIGHT])
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (life[j][i])
				cout << " #";
			else
				cout << "  ";
		}
		cout << '\n';
	}
}

void nextgen(bool life[WIDTH][HEIGHT])
{
	// analyze each pixel
	int neighbors[WIDTH][HEIGHT];
	for (int i = 1; i < WIDTH - 1; i++)
		for (int j = 1; j < HEIGHT - 1; j++)
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
				
				// the Von Neumann checks only the 4 cardinal directions: (N, S, E, and W).
				/*
				neighbors[i][j] = 
				life[i - 1][j] +
				life[i][j - 1] +
				life[i][j + 1] +
				life[i + 1][j];
				*/
		}
	// calculate the state of each pixel in the next generation
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++)
		{
			// if it has 3 neighbors it comes to life
			if (neighbors[i][j] == 3)
				life[i][j] = true;
			// if it has 2 neighbors it remains the same
			// every other senario it dies
			else if (neighbors[i][j] != 2)
				life[i][j] = false;
		}
}

void init_rand(bool life[WIDTH][HEIGHT])
{
	// loop through every pixel and assign a random value to it
	for (int i = 1; i < WIDTH - 1; i++)
		for (int j = 1; j < HEIGHT - 1; j++)
			life[i][j] = rand() % 2;
}

void init_file (bool life[WIDTH][HEIGHT])
{
	char ch;
	int i = 0;
	bool * ptr = &life[0][0];
	fstream fin("file.gol", fstream::in);
	while (fin >> skipws >> ch) {
			if (ch == '1')
				*(ptr + i) = true;
			else
				*(ptr + i) = false;
			i++;
	}
}
