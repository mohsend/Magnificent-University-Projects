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
		unsigned int numLessons;
		int moneyBalance;
		Clesson lessons[12];
	
	public:
		Cstudent (string, string);
		unsigned int setName(string param);
		unsigned int setId(string param);
		string getId(void);
		string getName(void);
		unsigned int removeLesson (unsigned int pIndex);
		unsigned int addLessonObj (Clesson);
		Clesson getLesson (unsigned int);
		float getMeanScore (void);
		unsigned int getNumOfLessons(void);
		int currentBalance(void);
		int payedMoney(int);
};

Cstudent::Cstudent (string pName = "", string pId = "")
{
	name = pName;
	id = pId;
	numLessons = 0;
	moneyBalance = 0;
}

unsigned int Cstudent::setName(string param)
{
	name = param;
	return name.length();
}

unsigned int Cstudent::setId(string param)
{
	id = param;
	return id.length();
}

string Cstudent::getId(void)
{
	return id;
}

string Cstudent::getName(void)
{
	return name;
}

unsigned int Cstudent::removeLesson (unsigned int pIndex)
{
	for (unsigned int i = pIndex; i < numLessons; i++)
	{
		lessons[i] = lessons[(i + 1)];
	}
	return --numLessons;
}

unsigned int Cstudent::addLessonObj (Clesson pLesson)
{
	lessons[numLessons] = pLesson;
	return ++numLessons;
}

Clesson Cstudent::getLesson (unsigned int pIndex)
{
	return lessons[pIndex];
}

float Cstudent::getMeanScore (void)
{
	unsigned int scoreSum = 0;
	for (unsigned int i = 0; i < numLessons; i++)
	{
		scoreSum += lessons[i].getScore();
	}
	return (float)(scoreSum / numLessons);
}

unsigned int Cstudent::getNumOfLessons(void)
{
	return numLessons;
}

int Cstudent::currentBalance(void)
{
	return moneyBalance;
}

int Cstudent::payedMoney(int howMuch)
{
	return moneyBalance += howMuch;
}

#endif
