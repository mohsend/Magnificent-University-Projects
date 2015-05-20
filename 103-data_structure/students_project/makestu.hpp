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
    // درست کردن یک نمونه از کلاس دانشجو
    Cstudent student;
    // درست کردن نمونه ای از کلاس لیست درس ها صرفا برای داشتن لیستی از درس های ارایه شده در این ترم. در مثال واقعی این مقادیر باید از دیتابیس خوانده شوند.
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

// یک شی از کلاس دانشجو گرفته میشود و به صفت همین کلاس ست میشود
Csite::Csite(Cstudent pStudent)
{
  student = pStudent;
}

// منوی اصلی سایت را چاپ میکند و بعد از گرفتن پاسخ تابع مربوط به آن را اجرا میکند
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

// منوی مربوط به درس ها را چاپ میکند و با توجه به جواب تابع مربوطه را اجرا و پس از پایان دوباره همان منو را چاپ میکند
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

// کارنامه را چاپ میکند
void Csite::printReport()
{
  // اگر هیچ درسی برنداشته خارج شو
  if (student.getNumOfLessons() == 0) return;
  // جدولی چاپ میکند با نام درس، نمره ی درس، و تعداد واحد های درس
  cout << "Here is your report card:" << endl;
  for (unsigned int i = 0; i < student.getNumOfLessons(); i++)
  {
    Clesson temp = student.getLesson(i);
    cout << i + 1 << ") " << temp.getName() << " by Prof. " << temp.getLecturer() << ": " << temp.getScore() << " * " << temp.getUnits() << endl;
  }
  // معدل را چاپ میکند
  cout << "Your mean score is " << student.getMeanScore() << endl;
  lessonsMenu();
}

// منوی مربوط به امور مالی
void Csite::balanceMenu()
{
  char response;
  unsigned int howMuch;
  // تراز مالی فعلی را چاپ میکند
  cout << "Your current balance is " << student.currentBalance() << endl;
  // از کاربر میپرسد آیا میخواهد پول بیشتری به حساب بریزد
  cout << "\tPay more to add to balance? (y/N) ";
  cin >> response;
  if (response == 'y' || response == 'Y')
  {
    // مقدار را میپرسد و این مقدار را به حساب اضافه میکند.
    // در مثال واقعی پس از پرسیدن مقدار به درگاه بانکی منتقل میشود و بانک مقدار پول ریخته شده را تایید میکند و به نرم افزار میدهد.
    cout << "How much? ";
    cin >> howMuch;
    cout << "Your new balance is " << student.currentBalance(howMuch) << endl;
  }
  else
  {
    // اگر کاربر مایل به ریختن پول نبود به منوی اصلی برگرد
    mainMenu();
  }
}

// چاپ اطلاعات دانشجو
void Csite::userInfoMenu()
{
  cout << "Name: " << student.getName() << "\nID: " << student.getId() << endl;
}

// برای لیست کردن درسهای برداشته شده همان کارنامه را چاپ میکنیم
void Csite::listLessons()
{
  printReport();
}

// منوی اضافه کردن درس
unsigned int Csite::addLesson(void)
{
  // اگر بیش از بیست واحد برداشته شده تا الان اجازه برداشتن واحد دیگه ای رو نده
  if (student.getUnits() <= 20)
  {
    // از کاربر کد درس رو که در لیست دروس ارایه شده هست میگیرد و درس را اضافه میکند
    unsigned int code;
    cout << "enter code of the lesson (from available lessons list): ";
    cin >> code;
    // مقدار بازگشتی تابع تعداد درس های برداشته شده است
    return student.addLessonObj(lessonsAvailabe.getLessonByCode(code));
  }
  else
  {
    cout << "You have reached your maximum units." << endl;
    return student.getNumOfLessons();
  }
}

// متد برای حذف درس. شماره ی درس از جدول درس های برداشته شده را میگیرد و حذف میکند
unsigned int Csite::removeLesson(void)
{
    unsigned int code;
    cout << "enter code of the lesson (from your lessons list): ";
    cin >> code;
    // مقدار بازگشتی تعداد درس های برداشته شده است
    return student.removeLesson(code - 1);
}

#endif
