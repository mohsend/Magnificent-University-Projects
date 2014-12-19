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

using namespace std;

class Csite
{
  private:
    Cstudent student;
  public:
    Csite(Cstudent);
    void mainMenu();
    void lessonsMenu();
    void reportMenu();
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
  cout << "Menu:\n\t1. Add/Remove Courses\n\t2. View report card\n\t3. Check balance\n\t4. View your info" << endl;
  char response;
  cin >> response;
  switch(response)
  {
    case '1':
      lessonsMenu();
      break;
    case '2':
      reportMenu();
      break;
    case '3':
      balanceMenu();
      break;
    case '4':
      userInfoMenu();
      break;
  }
}

void Csite::lessonsMenu()
{
  cout << "\n\t1. Show lessons list\n\t2. Show your lessons\n\t3. Add lesson\n\t4. Remove lesson" << endl;
  char response;
  cin >> response;
  switch(response)
  {
    case '1':
      listLessons();
      break;
    case '2':
      
  }
}
void Csite::reportMenu()
{
  
}
void Csite::balanceMenu()
{
  
}
void Csite::userInfoMenu()
{
  
}

void Csite::listLessons()
{
  
}

#endif
