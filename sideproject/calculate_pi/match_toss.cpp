/*
* calculate PI using probability.
* 
* http://www.pi314.net/eng/buffon.php
*/

#include <iostream>
using namespace std;

int main()
{
	char ch;
	int crossed = 0, tossed = 0;
	
	
	cout << "If a needle of length 2a is dropped on a parquet formed of floorboard of width 2b, the probability that the needle cuts one of the lines of this parquet is (2*a) / (b*Pi)\nfor more info: http://www.pi314.net/eng/buffon.php\n";
	cout << "\n0. Grab a piece of paper, draw parallel stripes with spaces between them equal to lenght of the match.\n1. Toss the match.\n2. if it crossed the stripe, enter '1' if it didn't, enter another character.\n3. Press Enter (Return) when you done.\n";
	do
	{
		ch = cin.get();
		tossed++;
		if (ch == '1')
			crossed++;
	} while (ch != '\n');
	tossed--;
	
	cout << "Probability of crossing the lines:\t(2/PI)\nYour results:\t\t\t\t(" << crossed << '/' << tossed << ")\n";
	cout << "Based on your results PI is:\t " << (float) (2.0 * tossed / crossed) << endl;
	cout << "The real value is:\t\t 3.14159";
	
	return 0;
}

