/*
convey's game of life
*/

#include <iostream>
using namespace std;

#define	HEIGHT	16
#define WIDTH	16

void show(bool life[WIDTH][HEIGHT]);
void nextgen(bool life[WIDTH][HEIGHT]);

int main()
{
	bool life[WIDTH][HEIGHT] = {
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
		{1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,0},
		{1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,0},
		{1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,0}
		};
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
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			// calculate the number of neighbors of the pixel
			neighbors[i][j] = 0;
			if ((i - 1) >= 0)
			{
				if ((j - 1) >= 0)
					neighbors[i][j] += life[i - 1][j - 1];
				neighbors[i][j] += life[i - 1][j];
				if ((j + 1) < HEIGHT)
					neighbors[i][j] += life[i - 1][j + 1];
			}
			if ((i + 1) < WIDTH)
			{
				if ((j - 1) >= 0)
					neighbors[i][j] += life[i + 1][j - 1];
				neighbors[i][j] += life[i + 1][j];
				if ((j + 1) < HEIGHT)
					neighbors[i][j] += life[i + 1][j + 1];
			}
			if ((j + 1) > HEIGHT)
				neighbors[i][j] += life[i][j + 1];
			if ((j - 1) <= 0)
				neighbors[i][j] += life[i][j - 1];
		}
	}
	// calculate the state of each pixel in the next generation
	for (int i = 0; i < WIDTH; i++)
	{
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
}
