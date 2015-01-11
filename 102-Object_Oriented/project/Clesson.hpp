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
		unsigned int units;
		unsigned int score;
		bool theory;
		
	public:
		Clesson (string pName = "", unsigned int pUnits = 0, unsigned int pScore = 0, bool pTheory = true)
		{
			setDetails(pName, pUnits, pScore, pTheory);
		}
		
		void setDetails (string pName = "", unsigned int pUnits = 0, unsigned int pScore = 0, bool pTheory = true)
		{
			name = pName;
			units = pUnits;
			score = pScore;
			theory = pTheory;
		}
		
		unsigned int setName (string param)
		{
			name = param;
			return name.length();
		}
		unsigned int setUnits (unsigned int param)
		{
			units = param;
			return units;
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
		unsigned int getUnits (void)
		{
			return units;
		}
		unsigned int getScore (void)
		{
			return score;
		}
		unsigned int getWeightedScore (void)
		{
			return units * score;
		}
		unsigned int getCost (void)
		{
			if (theory)
			{
				return units * 10;
			}
			else
			{
				return units * 30;
			}
		}
};

#endif
