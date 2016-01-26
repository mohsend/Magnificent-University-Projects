/*
 * Class to store lessons.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#ifndef CLESSON_HPP
#define CLESSON_HPP	1

#include <string>

using namespace std;

class Clesson
{
	private:
		// صفات
		string name; // نام
		string lecturer; // نام استاد
		unsigned int units; // چند واحد
		unsigned int score; // نمره
		bool theory; // آیا تئوری است یا عملی
		
	public:
		// کانستراکتور همان کار تابع بعدی را میکند
		Clesson (string pName = "", string pLecturer = "", unsigned int pUnits = 0, unsigned int pScore = 0, bool pTheory = true)
		{
			setDetails(pName, pLecturer, pUnits, pScore, pTheory);
		}
		
		// تمام صفات را میتوان با همین یک متد ست کرد
		void setDetails (string pName = "", string pLecturer = "", unsigned int pUnits = 0, unsigned int pScore = 0, bool pTheory = true)
		{
			name = pName;
			lecturer = pLecturer;
			units = pUnits;
			score = pScore;
			theory = pTheory;
		}
		
		// متد های ست کردن مقادیر به متد ها
		unsigned int setName (string param)
		{
			name = param;
			return name.length();
		}
		unsigned int setLecturer (string param)
		{
			lecturer = param;
			return lecturer.length();
		}
		unsigned int setUnits (unsigned int param)
		{
			units = param;
			return units;
		}
		unsigned int setScore (unsigned int param)
		{
			score = param;
			return score;
		}
		bool setTheory (unsigned int param)
		{
			theory = param;
			return theory;
		}
		
		// توابع گرفتن مقادیر صفات
		string getName (void)
		{
			return name;
		}
		string getLecturer (void)
		{
			return lecturer;
		}
		unsigned int getUnits (void)
		{
			return units;
		}
		unsigned int getScore (void)
		{
			return score;
		}
		bool getTheory (void)
		{
			return theory;
		}
		// گرفتن نمره ی وزنی
		unsigned int getWeightedScore (void)
		{
			// ضرب نمره در تعداد واحد های درس
			return units * score;
		}
		// محاسبه ی هزینه ی درس با توجه به عملی بودن یا نبودن آن
		unsigned int getCost (void)
		{
			if (theory)
			{
				return units * 10;
			}
			else
			{
				return units * 30;
			}
		}
};

#endif
