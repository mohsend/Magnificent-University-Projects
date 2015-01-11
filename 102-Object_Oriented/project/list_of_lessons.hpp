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
    void listLessons();
};

listOfLessons::listOfLessons()
{
  lessons[0].set("Persian literature", 2, 0, true);
  lessons[1].set("C++ fundamentals", 4, 0, true);
  lessons[2].set("maths 1", 3, 0, true);
  lessons[3].set("maths 2", 3, 0, true);
  lessons[4].set("physics 1", 3, 0, true);
  lessons[5].set("physics 2", 3, 0, true);
  lessons[6].set("phy lab 1", 1, 0, false);
  lessons[7].set("phy lab 2", 3, 0, false);
  lessons[8].set("history", 2, 0, true);
  lessons[9].set("C++ object oriented", 3, 0, true);
}

void listOfLessons::listAll()
{
  for (unsigned int i = 0; i < student.getNumOfLessons(); i++)
  {
    Clesson temp = student.getLesson(i);
    cout << i + 1 << ") " << temp.getName() << " * " << temp.getHours() << endl;
  }
}

#endif
