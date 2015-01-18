/*
 * Class to make list of available lessons.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

// این کلاس فقط برای این ساخته شده که لیستی از دروس ارایه شده را در اختیار کد اصلی بگذارد
// در یک مثال واقعی این اطلاعات در دیتابیس ذخیره میشوند و از آنجا لود میشوند. نه از یک فایل هدر
#ifndef LIST_OF_LESSONS_HPP
#define LIST_OF_LESSONS_HPP 1

#include <string>
#include "Clesson.hpp"

using namespace std;

class listOfLessons
{
  private:
    // یک آرایه از کلاس درس برای ذخیره واحد های ارایه شده
    Clesson lessons[10];
  public:
    listOfLessons();
    Clesson getLessonByCode(unsigned int);
    void listAll();
};

// مقدار دهی به اجزای آرایه
listOfLessons::listOfLessons()
{
  lessons[0].setDetails("Persian literature", 2, 0, true);
  lessons[1].setDetails("C++ fundamentals", 4, 0, true);
  lessons[2].setDetails("maths 1", 3, 0, true);
  lessons[3].setDetails("maths 2", 3, 0, true);
  lessons[4].setDetails("physics 1", 3, 0, true);
  lessons[5].setDetails("physics 2", 3, 0, true);
  lessons[6].setDetails("phy lab 1", 1, 0, false);
  lessons[7].setDetails("phy lab 2", 1, 0, false);
  lessons[8].setDetails("history", 2, 0, true);
  lessons[9].setDetails("C++ object oriented", 3, 0, true);
}

// لیست کردن تمام درس های ارایه شده.
void listOfLessons::listAll()
{
  for (unsigned int i = 0; i < 10; i++)
  {
    cout << i + 1 << ") " << lessons[i].getName() << " (" << lessons[i].getUnits() << " units)" << endl;
  }
}

// متد ای برای گرفتن درس ارایه شده به صورت یک نمونه از کلاس درس با استفاده از کد درس
Clesson listOfLessons::getLessonByCode(unsigned int code)
{
  return lessons[(code - 1)];
}
#endif
