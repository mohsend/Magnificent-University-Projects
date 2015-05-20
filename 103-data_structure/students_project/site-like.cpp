/*
 * program to mimik university site.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#include <iostream>
#include "Csite.hpp"
#include "Cstudent.hpp"

using namespace std;

int main()
{
	// ساخت یک نمونه از کلاس دانشجو برای کانستراکت نمونه کلاس سایت
	// در یک مثال واقعی باید بعد از گرفتن یوزر و پسورد از دیتابیس لود شود
	Cstudent stu("Mohsen Dastjedi Zade", "90000001");
	
	// نمونه ای از کلاس سایت ساخته و متد منوی اصلی سایت اجرا میشود
	Csite site(stu);
	site.mainMenu();
	
	return 0;
}
