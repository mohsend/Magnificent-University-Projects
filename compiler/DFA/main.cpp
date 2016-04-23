/*
 * A simple DFA (Deterministic finite automaton) implantation 
 * Gets one string as a commanline argument
 * and checks if it fits the defined automaton
 */

#include <iostream>
#include <string>
#include "dfa1.hpp" // change to "dfa2.hpp" for another automaton

using namespace std;

bool check(int [NO_STATES][NO_CHARS], char*);
inline int in(char);

int main(int argc, char **argv)
{
	if (argc < 2) { // Prints instructions to use the program if no arguments passed
		cout << "This program takes strings as commandline arguments and checks if they match the \n" << regex << " \nregex pattern." << endl;
	}
	else
	{
		for (int i = 1; i < argc; i++) // Check each passed string
		{
			cout << '"' << argv[i] << "\": " << endl;
			string out = check(table, argv[i])? "Matches " : "Doesn't match ";
			out += regex;
			cout << out << '\n' << endl;
		}
	}
	return 0;
}

bool check(int t [NO_STATES][NO_CHARS] , char* s)
{
	int current_state = 0;
	for (int i = 0; *s; i++)
	{
		cout << '(' << current_state << ')' << " -" << *s << "-> ";
		current_state = t[current_state][in(*s++)];	
	}
	cout << '(' << current_state << ')' << endl;
	return (current_state == final_state);
}

inline int in(char c) 
{
	return c - 'a';
}
