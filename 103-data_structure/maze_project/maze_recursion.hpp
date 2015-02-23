/*
 * 
 */

#ifndef MAZE_HPP
#define MAZE_HPP 1

#define COLS  15
#define LINS  15


#include <iostream>
#include <fstream>
using namespace std;

class maze
{
  private:
    char array[COLS][LINS];
    int x;
    int y;
  public:
    maze();
    void init_with_file (char*);
    void show();
    void start();
};

maze::maze()
{
  been_there = 0;
}

void maze::show()
{
  cout << "line: " << y << "\tcol: " << x << endl;
  char ch;
  for (int j = 0; j < LINS; j++)
    {
      for (int i = 0; i < COLS; i++)
      {
	ch = array[i][j];
	if (ch == '.')
	  cout << "  ";
	else if (ch == '#')
	  cout << "##";
	else
	  cout << ch << ' ';
      }
    cout << endl;
    }
}

void maze::init_with_file (char* filename)
{
	// loop through every non-whitespace charecter in a file and initialize the char array
	char ch;
	cout << "Initialized with " << filename << ":\n";
	fstream fin(filename, fstream::in);
	for (int j = 0; j < LINS; j++)
	{
	  for (int i = 0; i < COLS; i++)
	  {
	    fin >> skipws >> ch;
	    array[i][j] = ch;
	  }
	}
}

void maze::start()
{
  for (int j = 0; j < LINS; j++)
  {
    for (int i = 0; i < COLS; i++)
    {
      if (array[i][j] == '*')
      {
        x = i;
        y = j;
      }
    }
  }
}

void solve()
{
  
}

#endif
