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
    Clesson lessons[15];
    unsigned int index;
  public:
    listOfLessons();
    Clesson getLessonByCode(unsigned int);
    void listAll();
};

// مقدار دهی به اجزای آرایه
listOfLessons::listOfLessons()
{
  index = 0;
  lessons[index++].setDetails("Data structure", "Vaziri", 3, 0, true);
  lessons[index++].setDetails("Persian literature", "Daemi", 2, 0, true);
  lessons[index++].setDetails("C++ fundamentals", "Pur ganji", 4, 0, true);
  lessons[index++].setDetails("maths 1", "Reza", 3, 0, true);
  lessons[index++].setDetails("maths 1", "Zia manesh", 3, 0, true);
  lessons[index++].setDetails("maths 2", "Reza", 3, 0, true);
  lessons[index++].setDetails("maths 2", "Zia manesh", 3, 0, true);
  lessons[index++].setDetails("physics 1", "Ghafari", 3, 0, true);
  lessons[index++].setDetails("physics 2", "Ghafari", 3, 0, true);
  lessons[index++].setDetails("phy lab 1", "", 1, 0, false);
  lessons[index++].setDetails("phy lab 2", "Salehi", 1, 0, false);
  lessons[index++].setDetails("history", "", 2, 0, true);
  lessons[index++].setDetails("object oriented programming", "Farhadi", 3, 0, true);
}

// لیست کردن تمام درس های ارایه شده.
void listOfLessons::listAll()
{
  for (unsigned int i = 0; i < index; i++)
  {
    string theory = (lessons[i].getTheory()) ? "Theory" : "Applied";
    cout << i + 1 << ") " << lessons[i].getName() << " by Prof. " << lessons[i].getLecturer() << " (" << lessons[i].getUnits()  << ' ' << theory << " units)" << endl;
  }
}

// متد ای برای گرفتن درس ارایه شده به صورت یک نمونه از کلاس درس با استفاده از کد درس
Clesson listOfLessons::getLessonByCode(unsigned int code)
{
  return lessons[(code - 1)];
}
#endif
