/*
 * 
 */

#include <iostream>
#include "maze.hpp"
using namespace std;

int main(int argc, char **argv)
{
	maze maz;
	maz.init_with_file(argv[1]);
	maz.start();
	while (!maz.move())
	{
		cin.get();
	}
	return 0;
}
