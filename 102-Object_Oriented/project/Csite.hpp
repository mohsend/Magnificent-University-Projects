/*
 * Class to do site-like functionality.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#ifndef CSITE_HPP
#define CSITE_HPP 1

#include <string>
#include <iostream>
#include "Clesson.hpp"
#include "Cstudent.hpp"
#include "list_of_lessons.hpp"

using namespace std;

class Csite
{
  private:
    Cstudent student;
    listOfLessons lessonsAvailabe;
  public:
    Csite(Cstudent);
    void mainMenu();
    void lessonsMenu();
    void printReport();
    void balanceMenu();
    void userInfoMenu();
    void listLessons();
};

Csite::Csite(Cstudent pStudent)
{
  // should load student's class from a database in real life application
  student = pStudent;
}

void Csite::mainMenu ()
{
  cout << "Welcome " << student.getName() << endl;
  cout << "Menu:\n\t1. Add/Remove Courses\n\t2. View report card\n\t3. Check balance\n\t4. View your info\n\t5. exit" << endl;
  char response;
  cin >> response;
  switch(response)
  {
    case '1':
      lessonsMenu();
      break;
    case '2':
      printReport();
      break;
    case '3':
      balanceMenu();
      break;
    case '4':
      userInfoMenu();
      break;
    case '5':
      // returns to main() and executes 'return 0;'
      break;
    default:
      mainMenu();
  }
}

void Csite::lessonsMenu()
{
  cout << "\n\t1. Show available lessons list\n\t2. Show your lessons\n\t3. Add lesson\n\t4. Remove lesson" << endl;
  char response;
  cin >> response;
  switch(response)
  {
    case '1':
      lessonsAvailabe.listAll();
      break;
    case '2':
      
      break;
    case '3':
      
      break;
    case '4':
      
      break;
    default:
      lessonsMenu();
  }
}
void Csite::printReport()
{
  cout << "Here is your report card:" << endl;
  for (unsigned int i = 0; i < student.getNumOfLessons(); i++)
  {
    Clesson temp = student.getLesson(i);
    cout << i + 1 << ") " << temp.getName() << ": " << temp.getScore() << " * " << temp.getHours() << endl;
  }
  cout << "Your mean score is " << student.getMeanScore() << endl;
  lessonsMenu();
}
void Csite::balanceMenu()
{
  char response;
  unsigned int howMuch;
  
  cout << "Your current balance is " << student.currentBalance() << endl;
  
  cout << "\tPay more to add to balance? (y/N) ";
  cin >> response;
  if (response == 'y' || response == 'Y')
  {
    cout << "How much? ";
    cin >> howMuch;
    cout << "Your new balance is " << student.currentBalance(howMuch) << endl;
  }
  mainMenu();
}
void Csite::userInfoMenu()
{
  cout << "Name: " << student.getName() << "\nID: " << student.getId();
}

void Csite::listLessons()
{
  printReport();
}

#endif
