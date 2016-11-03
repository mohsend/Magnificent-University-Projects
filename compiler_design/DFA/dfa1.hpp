/*
 * Sigma = {a, b}
 * matches /a*ba+b[ab]/ regex pattern
 * The table is equivalent to this graph: dfa1.svg
 */

#ifndef DFA1_HPP
#define DFA1_HPP 1

#define NO_STATES 6
#define NO_CHARS 2
int final_state = 5;
char regex [13] = "/a*ba+b[ab]/";

int table [NO_STATES][NO_CHARS] = 
	{
		{0, 1},
		{2, 4},
		{2, 3},
		{5, 5},
		{4, 4},
		{4, 4}
	};

#endif
