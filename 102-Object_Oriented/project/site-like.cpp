/*
 * program to mimik university site.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#include <iostream>
#include "Csite.hpp"
#include "Cstudent.hpp"
#include "Clesson.hpp"

using namespace std;

int main()
{
	Clesson lessons[5];
	Cstudent stu("Mohsen Dastjedi Zade", "90000001");
	
	stu.addLessonObj();
	Csite site(stu);
	site.mainMenu();
	
	return 0;
}
