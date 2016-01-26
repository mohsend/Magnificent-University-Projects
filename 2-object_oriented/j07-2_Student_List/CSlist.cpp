/*
 * Class to store student IDs of 20 students.
 * source available at (Github repo - MIT licence):
 * http://dstjrd.ir/s/cppx
 * https://github.com/mohsend/cpp-examples
 */

#include <iostream>
#include <iomanip>
using namespace std;

class CSlist
{
	private:
		unsigned long int list[20];
		unsigned int howMany;
		void shiftList(unsigned int);
	public:
		CSlist();
		int add(unsigned long int);
		int remove(unsigned long int);
		void show(void);
		unsigned int getHowMany(void);
		int search(unsigned long int);
		void batchAdd(void);
		int userInteract(void);
};

int main()
{
	CSlist students;
	while (students.userInteract())
	{
		cout << '\n';
	}
	return 0;
}

CSlist::CSlist()
{
	howMany = 0;
}

void CSlist::shiftList(unsigned int index)
{
	for (unsigned int i = index; i < 20; i++)
	{
		list[i] = list[i + 1];
	}
	list[19] = 0;
}

int CSlist::add(unsigned long int stuid)
{
	if (howMany < 20)
	{
		if (search(stuid) > -1)
		{
			return -1;
		}
		else
		{
			list[howMany] = stuid;
			return ++howMany;
		}
	}
	return 0;
}

int CSlist::remove(unsigned long int stuid)
{
	for (int i = 0; i < 20; i++)
	{
		if (list[i] == stuid)
		{
			shiftList(i);
			return --howMany;
		}
	}
	return 0;
}

void CSlist::show(void)
{
	for (unsigned int i = 0; i < howMany; i++)
	{
		cout << setw(2) << setfill('0') << i + 1;
		cout << ") " << list[i] << endl;
	}
}

unsigned int CSlist::getHowMany(void)
{
	return howMany;
}

int CSlist::search(unsigned long int stuid)
{
	for (unsigned int i = 0; i < howMany; i++)
	{
		if (list[i] == stuid)
		{
			return i;
		}
	}
	return -1;
}


void CSlist::batchAdd(void)
{
	cout << "Getting student IDs (Enter 0 to break):" << endl;
	do
	{
		unsigned long int userInput;
		cout << "New student ID: ";
		cin >> userInput;
		if (userInput == 0)
		{
			break;
		}
		
		int res = add(userInput);
		if (res > 0)
		{
			cout << "Added successfully (" << getHowMany() << ")" << endl;
		}
		else if (res == 0)
		{
			cerr << "Can't add. no more room!" << endl;
			break;
		}
		else if (res == -1)
		{
			cerr << "Duplicate entery!" << endl;
		}
	} while(true);
}

int CSlist::userInteract(void)
{
	cout << "1. Batch add\n2. Show all\n3. Remove\n4. eXit" << endl;
	char selected;
	cin >> selected;
	switch (selected)
	{
		case '1':
		case 'B':
		case 'b':
			batchAdd();
			return 1;
		case '2':
		case 'S':
		case 's':
			show();
			return 2;
		case '3':
		case 'R':
		case 'r':
			long unsigned int stuid;
			cout << "Enter a student ID to remove:" << endl; 
			cin >> stuid;
			cout << "There are " << remove(stuid) << " students in the list." << endl;
			return 3;
		case '4':
		case 'X':
		case 'x':
		case 'Q':
		case 'q':
			return 0;
		default:
			userInteract();
	}
	return 0; // never happens. it's here to avoid compiler warning.
}
