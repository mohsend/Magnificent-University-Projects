/*
Count Words in a String – Counts the number of individual words in a string.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string user_input;
	int i = 0, words = 1, sentences = 0;
	cout << "Type out a string, press Enter afterwards: \n";
	cin.ignore();
	getline(cin, user_input);
	do {
		if (user_input[i] == ' ')
			words++;
		else if (user_input[i] == '.' || user_input[i] == '!' || user_input[i] == '?')
			sentences++;
		i++;
	} while (user_input[i]);
	cout << "Assumig you got basic typography right, your string contains:\n\t" << sentences << " sentences (periods)\n\t" << words << " words (space)\n\t" << i << " characters overall.\n";

	cin.ignore();
	cin.get();
	return 0;
}