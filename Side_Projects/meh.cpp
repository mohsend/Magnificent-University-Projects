/*
 * meh
 */

#include <iostream>
#include <cstdint>
using namespace std;

int main(int argc, char **argv)
{
	uint64_t meh = 0xFFFFFFFFFFFFFFFF;
	uint64_t age;
	cout << "meh = " << meh << endl;
	cout << "How old are you? ";
	cin >> age;
	cout << "meh per year = " << meh / age << endl;
	cout << "meh per month = " << meh / (age * 12) << endl;
	cout << "meh per day = " << meh / (age * 365) << endl;
	cout << "meh per hour = " << meh / (age * 365 * 24) << endl;
	cout << "meh per second = " << meh / (age * 365 * 24 * 3600) << endl;
	return 0;
}
