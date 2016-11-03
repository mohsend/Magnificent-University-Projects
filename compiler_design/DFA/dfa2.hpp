/*
 * Sigma = {a, b}
 * matches /(ab)* / regex pattern
 * The table is equivalent to this graph: dfa2.svg
 */

#ifndef DFA2_HPP
#define DFA2_HPP 1

#define NO_STATES 4
#define NO_CHARS 2
int final_state = 2;
char regex [8] = "/(ab)*/";

int table [NO_STATES][NO_CHARS] = 
	{
		{3, 1},
		{2, 1},
		{3, 1},
		{3, 3}
	};

#endif
