/*
 * convey's game of life
 */

#include <iostream>
#include "GoL.hpp"
#include "output.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2) // if argument passed use the file to initialize 'gol'
	{
		gol.init_file(argv[1]);
	}
	else
	{
		std::cout << "Initilized pseudo-randomly.\nTip: You can pass a .gol file az an argument.\n";
	}
	init_glut(argc, argv);
	
	return 0;
}
