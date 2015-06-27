/*
 * program to mimik university site.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#include <iostream>
#include "Csite.hpp"
#include "Cstudent.hpp"
#include "BST.hpp"

using namespace std;
using namespace BinaryTree;
using namespace BST;

using namespace std;

int main(int argc, char **argv)
{
	ptree head;
	cout << "Making a new node with 90 as head..." << endl;
	Cstudent tempStu("Sample head student", 9000000000);
	head = newNode(tempStu);
	cout << "Insert as many students as you like, Enter 0 for ID to end:" << endl;
	
	int count = 1;
	uint64_t idInput;
	string nameInput;
	
	while (idInput)
	{
		cout << count << ") ID: ";
		cin >> idInput;
		if (idInput == 0) break; 
		cout << count << ") Name: ";
		cin >> nameInput;
		tempStu.setId(idInput);
		tempStu.setName(nameInput);
		BSTinsert(head, tempStu);
		cin.ignore();
		count++;
	}
	
	cout << "The tree Traversed in-order: " << endl;
	inOrder(head);
	cout << endl;
	
	idInput = 1;
	while (idInput)
	{
		cin.ignore();
		cout << "Search for a student by ID: ";
		cin >> idInput;
		if (idInput == 0) break; 
		ptree temp;
		temp = BSTsearch(head, idInput);
		if (temp)
		{
			// نمونه ای از کلاس سایت ساخته و متد منوی اصلی سایت اجرا میشود
			Csite site(temp->data);
			site.mainMenu();
		}
		else
		{
			cout << "student not found!" << endl;
		}
	}
	return 0;
}
