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
    void lessonsMenu();
    void printReport();
    void balanceMenu();
    void userInfoMenu();
    void listLessons();
    unsigned int addLesson(); 
    unsigned int removeLesson(); 
  public:
    Csite(Cstudent);
    void mainMenu();
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
      mainMenu();
      break;
    case '3':
      balanceMenu();
      mainMenu();
      break;
    case '4':
      userInfoMenu();
      mainMenu();
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
  cout << "\n\t1. Show available lessons list\n\t2. Show your lessons\n\t3. Add lesson\n\t4. Remove lesson\n\t5. Back to main menu" << endl;
  char response;
  cin >> response;
  switch(response)
  {
    case '1':
      lessonsAvailabe.listAll();
      lessonsMenu();
      break;
    case '2':
      listLessons();
      lessonsMenu();
      break;
    case '3':
      addLesson();
      lessonsMenu();
      break;
    case '4':
      removeLesson();
      lessonsMenu();
      break;
    case '5':
      mainMenu();
      break;
    default:
      lessonsMenu();
  }
}
void Csite::printReport()
{
  if (student.getNumOfLessons() == 0) return;
  
  cout << "Here is your report card:" << endl;
  for (unsigned int i = 0; i < student.getNumOfLessons(); i++)
  {
    Clesson temp = student.getLesson(i);
    cout << i + 1 << ") " << temp.getName() << ": " << temp.getScore() << " * " << temp.getUnits() << endl;
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
  else
  {
    mainMenu();
  }
}
void Csite::userInfoMenu()
{
  cout << "Name: " << student.getName() << "\nID: " << student.getId() << endl;
}

void Csite::listLessons()
{
  printReport();
}

unsigned int Csite::addLesson(void)
{
  if (student.getUnits() <= 20)
  {
    unsigned int code;
    cout << "enter code of the lesson (from available lessons list): ";
    cin >> code;
    return student.addLessonObj(lessonsAvailabe.getLessonByCode(code));
  }
  else
  {
    cout << "You have reached your maximum units." << endl;
    return student.getNumOfLessons();
  }
}

unsigned int Csite::removeLesson(void)
{
    unsigned int code;
    cout << "enter code of the lesson (from your lessons list): ";
    cin >> code;
    return student.removeLesson(code - 1);
}

#endif
