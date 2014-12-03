/*
 * 
*/

#include <iostream>
#include <string>
#include "Clesson.hpp"

using namespace std;


int main()
{
	Clesson testLesson;
	
	testLesson.setName("C 101");
	testLesson.setHours(3);
	testLesson.setScore(18);
	
	cout << testLesson.getName() << " is " << testLesson.getHours() << " hours long." << endl;
	cout << testLesson.getName() << "'s score is " << testLesson.getScore() << endl;
	
	return 0;
}
