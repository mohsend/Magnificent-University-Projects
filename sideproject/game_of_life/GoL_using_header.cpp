/*
 * convey's game of life
*/

#include <iostream>
#include "GoL.hpp"

int main(int arg, char* args[])
{
	gameOfLife gol;
	if (arg == 2) // if argument passed use the file to initialize 'gol'
	{
		gol.init_file(args[1]);
	}
	else
	{
		std::cout << "Initilized pseudo-randomly.\nTip: You can pass a .gol file az an argument.\n";
	}
	
	gol.play();
	
	return 0;
}
