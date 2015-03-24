/*
 * 
 */

#include <iostream>
#include "maze_recursion.hpp"
using namespace std;

int main(int argc, char **argv)
{
	maze maz;
	maz.init_with_file(argv[1]);
	maz.start();
	return 0;
}
