/*
 * Class to store lessons.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#ifndef CLESSON_HPP
#define CLESSON_HPP	1

#include <string>

using namespace std;

class Clesson
{
	private:
		string name;
		unsigned int hours;
		unsigned int score;
		
	public:
		Clesson (string pName = "", unsigned int pHours = 0, unsigned int pScore = 0)
		{
			name = pName;
			hours = pHours;
			score = pScore;
		}
		
		unsigned int setName (string param)
		{
			name = param;
			return name.length();
		}
		unsigned int setHours (unsigned int param)
		{
			hours = param;
			return hours;
		}
		unsigned int setScore (unsigned int param)
		{
			score = param;
			return score;
		}
		
		string getName (void)
		{
			return name;
		}
		unsigned int getHours (void)
		{
			return hours;
		}
		unsigned int getScore (void)
		{
			return score;
		}
		unsigned int getWeightedScore (void)
		{
			return hours * score;
		}
};

#endif
