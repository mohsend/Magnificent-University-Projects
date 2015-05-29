/*
 * 
 */

#include "maze_recursion.hpp"
#include "output.hpp"
using namespace std;

int main(int argc, char **argv)
{
	init_with_file(argv[1]);
	start();
	init_glut(argc, argv);
	show_glut();
	return 0;
}
