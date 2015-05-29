/*
 * 
 */

#include "maze_recursion.hpp"
#include "output.hpp"
using namespace std;

int main(int argc, char **argv)
{
	maze maz;
	maz.init_with_file(argv[1]);
	init_glut(argc, argv);
	maz.start();
	return 0;
}
