/*
 * 
 */

#include <iostream>
#include "maze.hpp"
using namespace std;

int main()
{
	maze maz;
	maz.init_with_file("first_maze_15x15.txt");
	maz.start();
	while (!maz.move())
	{
		cin.get();
	}
	return 0;
}
