/*
convey's game of life
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define	HEIGHT	32
#define WIDTH		32

void show(bool life[WIDTH][HEIGHT]);
void nextgen(bool life[WIDTH][HEIGHT]);
void init(bool life[WIDTH][HEIGHT]);

int main()
{
	bool life[WIDTH][HEIGHT];
	init(life);
	for (int gen = 0; true; gen++)
	{
		cout << gen << '\n';
		show(life);
		nextgen(life);
		cin.get();
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
			{
				cout << " #";
			}
			else
			{
				cout << "  ";
			}
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
			//1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
			if (neighbors[i][j] < 2)
				life[i][j] = false;
			//2. Any live cell with two or three live neighbors lives on to the next generation.
				// automaticly done
			//3. Any live cell with more than three live neighbors dies, as if by overcrowding.
			if (neighbors[i][j] > 3)
				life[i][j] = false;
			//4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
			if (neighbors[i][j] == 3)
				life[i][j] = true;
		}
}

void init(bool life[WIDTH][HEIGHT])
{
	// loop through every pixel and assign a random value to it
	for (int i = 1; i < WIDTH - 1; i++)
		for (int j = 1; j < HEIGHT - 1; j++)
			life[i][j] = rand() % 2;
}
