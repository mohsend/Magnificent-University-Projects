/*
 * Demo for Cstudent.hpp
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#include <string>
#include <iostream>
#include "Cstudent.hpp"

using namespace std;

int main()
{
	cout << "Defining a new student:" << endl;
	string stName, stId;
	cout << "Enter Student's name: ";	getline(cin >> ws, stName); // '>> ws' removes all leading white spaces.
	cout << "Enter Student's ID: "; cin >> stId;
	Cstudent testStudent(stName, stId);

	cout << "\nSetting " << testStudent.getName() << "'s courses:" << endl;
	for (int i = 0; i < 3; i++)
	{
		string cName;
		unsigned int cHours, cScore;
		cout << i + 1 << ") Course Name: "; getline(cin >> ws, cName);
		cout << i + 1 << ") Course Hours: "; cin >> cHours;
		cout << i + 1 << ") Course Score: "; cin >> cScore;
		testStudent.setLesson(i, cName, cHours, cScore);
	}

	cout << "Here is my information about " << testStudent.getName()  << ':' << endl;
	cout << "Name: " << testStudent.getName() << endl;
	cout << "ID: " << testStudent.getId() << endl;
	cout << "Mean score: " << testStudent.getMeanScore() << endl;
	
	cout << testStudent.getName() << "'s courses:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << '\t' << testStudent.getLesson(i).getName() << ':' << endl;
		cout << "\t\tScore:" << testStudent.getLesson(i).getScore() << endl;
		cout << "\t\tHours:" << testStudent.getLesson(i).getHours() << endl;
		cout << "\t\tWeighted Score:" << testStudent.getLesson(i).getWeightedScore() << endl;
	}

	return 0;
}
