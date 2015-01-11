/*
 * Class to do site-like functionality.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#ifndef LIST_OF_LESSONS_HPP
#define LIST_OF_LESSONS_HPP 1

#include <string>
#include "Clesson.hpp"

using namespace std;

class listOfLessons
{
  private:
    Clesson lessons[10];
  public:
    listOfLessons();
    Clesson getLessonByCode(unsigned int);
    void listAll();
};

listOfLessons::listOfLessons()
{
  lessons[0].setDetails("Persian literature", 2, 0, true);
  lessons[1].setDetails("C++ fundamentals", 4, 0, true);
  lessons[2].setDetails("maths 1", 3, 0, true);
  lessons[3].setDetails("maths 2", 3, 0, true);
  lessons[4].setDetails("physics 1", 3, 0, true);
  lessons[5].setDetails("physics 2", 3, 0, true);
  lessons[6].setDetails("phy lab 1", 1, 0, false);
  lessons[7].setDetails("phy lab 2", 3, 0, false);
  lessons[8].setDetails("history", 2, 0, true);
  lessons[9].setDetails("C++ object oriented", 3, 0, true);
}

void listOfLessons::listAll()
{
  for (unsigned int i = 0; i < 10; i++)
  {
    cout << i + 1 << ") " << lessons[i].getName() << " (" << lessons[i].getHours() << " hours)" << endl;
  }
}

Clesson listOfLessons::getLessonByCode(unsigned int code)
{
  return lessons[(code - 1)];
}
#endif
