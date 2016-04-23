/*
 * A simple DFA automata
 * gets one string as a commanline argument
 * and checks if it fits the defined automata
 */

#include <iostream>
#include <string>
#include "dfa1.hpp" // change to "dfa2.hpp" for another automata

using namespace std;

bool check(int [NO_STATES][NO_CHARS], char*);
inline int in(char);

int main(int argc, char **argv)
{
	string out = check(table, argv[1])? "Matches " : "Doesn't match ";
	out += regex;
	cout << out << endl;
	return 0;
}

bool check(int t [NO_STATES][NO_CHARS] , char* s)
{
	static int current_state = 0;
	for (int i = 0; *s; i++)
	{
		cout << *s << current_state << " -> ";
		current_state = t[current_state][in(*s++)];	
	}
	cout << "eof" << current_state << endl;
	return (current_state == final_state);
}

inline int in(char c) 
{
	return c - 'a';
}
