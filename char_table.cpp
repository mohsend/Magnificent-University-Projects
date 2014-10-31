// prints ascii table.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char ch = 0;
	cout << "characters table in your system:\n";
	for (int i = 0; i < 255; i++)
		cout << '\'' << ch++ << "' = " << setw(3) << i << " |\t";

	cin.ignore();
	cin.get();
	return 0;
}

