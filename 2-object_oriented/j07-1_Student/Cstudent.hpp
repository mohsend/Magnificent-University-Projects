/*
 * Class to store students.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#ifndef CSTUDENT_HPP
#define CSTUDENT_HPP	1

#include <string>
#include "Clesson.hpp"

using namespace std;

class Cstudent
{
	private:
		string name;
		string id; // string or double. it's a long decimal. should be a decimal in a database (e.g. mySQL)
		Clesson lessons[3];
	
	public:
		Cstudent (string pName = "", string pId = "")
		{
			name = pName;
			id = pId;
		}
		unsigned int setName(string param)
		{
			name = param;
			return name.length();
		}
		unsigned int setId(string param)
		{
			id = param;
			return id.length();
		}
		string getId(void)
		{
			return id;
		}
		string getName(void)
		{
			return name;
		}
		unsigned int setLesson (unsigned int pIndex, string pName, unsigned int pHours, unsigned int pScore)
		{
			lessons[pIndex].setName(pName);
			lessons[pIndex].setHours(pHours);
			lessons[pIndex].setScore(pScore);
			return lessons[pIndex].getHours();
		}
		Clesson getLesson (unsigned int pIndex)
		{
			return lessons[pIndex];
		}
		float getMeanScore (void)
		{
			unsigned int scoreSum = 0;
			for (int i = 0; i < 3; i++)
			{
				scoreSum += lessons[i].getScore();
			}
			return scoreSum / 3.0;
		}
};

#endif
