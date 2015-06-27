/*
 * Class to store students.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#ifndef CSTUDENT_HPP
#define CSTUDENT_HPP	1

#include <string>
#include "Clesson.hpp"

using namespace std;

class Cstudent
{
	private:
		// صفات دانشجو از قبیل نام، شماره دانشجویی، تراز مالی، و آرایه ای از واحد های انتخاب شده.
		string name;
		string id; // string or double. it's a long decimal. should be a decimal in a database (e.g. mySQL)
		unsigned int numLessons;
		int moneyBalance;
		Clesson lessons[12];
	
	public:
		// متد ها
		Cstudent (string, string);
		unsigned int setName(string param);
		unsigned int setId(string param);
		string getId(void);
		string getName(void);
		unsigned int removeLesson (unsigned int pIndex);
		unsigned int addLessonObj (Clesson);
		Clesson getLesson (unsigned int);
		float getMeanScore (void);
		unsigned int getNumOfLessons(void);
		int currentBalance(int);
		unsigned int getUnits(void);
};

// کانستراکتور نام و شماره دانشجویی را میگیرد و ست میکند
Cstudent::Cstudent (string pName = "", string pId = "")
{
	name = pName;
	id = pId;
	numLessons = 0;
	moneyBalance = 0;
}

// متد های ست کردن صفت ها
unsigned int Cstudent::setName(string param)
{
	name = param;
	return name.length();
}

unsigned int Cstudent::setId(string param)
{
	id = param;
	return id.length();
}

// متد های گرفتن مقادیر صفت ها
string Cstudent::getId(void)
{
	return id;
}

string Cstudent::getName(void)
{
	return name;
}

// حذف درس با استفاده از شماره اندیس آن در آرایه
unsigned int Cstudent::removeLesson (unsigned int pIndex)
{
	// پول کسر شده از حساب دانشجو برای برداشتن این درس برگردانده می شود
	moneyBalance += lessons[pIndex].getCost();
	// از آن اندیس آرایه را شیفت میدهیم به بالا تا جای درس حذف شده را پر کنند
	for (unsigned int i = pIndex; i < numLessons; i++)
	{
		lessons[i] = lessons[(i + 1)];
	} 
	// خروجی تابع تعداد درس های انتخاب شده دانشجو پس از حذف درس است
	return --numLessons;
}

// اضافه کردن درس جدید. ورودی تابع یک شی از کلاس درس است
unsigned int Cstudent::addLessonObj (Clesson pLesson)
{
	// شی گرفته شده را به انتهای آرایه اضافه میکند
	lessons[numLessons] = pLesson;
	// هزینه درس را از حساب کاربر کسر میکند
	moneyBalance -= lessons[numLessons].getCost();
	// مقدار جدید تعداد درس های برداشته شده را برمیگرداند
	return ++numLessons;
}

// تابع برای گرفتن درس با استفاده از شماره اندیس آرایه
Clesson Cstudent::getLesson (unsigned int pIndex)
{
	return lessons[pIndex];
}

// متد برای گرفتن میانگین نمرات دانشجو
float Cstudent::getMeanScore (void)
{
	// نمرات درس های داخل آرایه جمع زده میشود
	unsigned int scoreSum = 0;
	for (unsigned int i = 0; i < numLessons; i++)
	{
		scoreSum += lessons[i].getWeightedScore();
	}
	// مقدار جمع زده شده ی نمرات وزنی به تعداد واحد های برداشته شده تقسیم و برگردانده میشود
	return (float)(scoreSum / getUnits());
}

// متد برای گرفتن تعداد درس های برداشته شده توسط دانشجو
unsigned int Cstudent::getNumOfLessons(void)
{
	return numLessons;
}

// متد برای گرفتن تعداد واحد های گرفته شده توسط دانشجو
unsigned int Cstudent::getUnits(void)
{
	unsigned int units = 0;
	for (unsigned int i = 0; i < numLessons; i++)
	{
		units += lessons[i].getUnits();
	}
	return units;
}

// متد دو منظوره برای اضافه کردن پول به حساب یا گرفتن مقدار فعلی تراز مالی دانشجو
int Cstudent::currentBalance(int howMuch = 0)
{
	return moneyBalance += howMuch;
}

#endif
