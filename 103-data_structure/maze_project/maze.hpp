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
    int last_col;
    int last_line;
    int been_there;
  public:
    maze();
    void init_with_file (char*);
    void show();
    void start();
    bool move();
    void move_back();
};

maze::maze()
{
  been_there = 0;
}

void maze::show()
{
	cout << "line: " << last_line << "\tcol: " << last_col << endl;
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
        last_col = i;
        last_line = j;
      }
		}
	}
}

bool maze::move()
{
  // mark where it's been.
  array[last_col][last_line] = '*';
  show();
  // look down(3)
  if ((been_there != 3) && (last_line < 14) && (array[last_col][(last_line + 1)] == '.'))
    last_line = last_line + 1;
  // look right(2)
  else if ((been_there != 2) && (last_col < 14) && (array[(last_col + 1)][last_line] == '.'))
    last_col = last_col + 1;
  // look left(4)
  else if ((been_there != 4) && (last_col > 1) && (array[(last_col - 1)][last_line] == '.'))
    last_col = last_col - 1;
  // look up(1)
  else if ((been_there != 1) && (last_line > 1) && (array[last_col][(last_line - 1)] == '.'))
    last_line = last_line - 1;
  else if (array[last_col][(last_line + 1)] == 'G')
    return true;
  else
    move_back();
    
  return false;
}

void maze::move_back()
{
  // mark where it's been.
  array[last_col][last_line] = '.';
  show();
  // look down(3)
  if ((last_line < 14) && (array[last_col][(last_line + 1)] == '*'))
  {
    last_line = last_line + 1;
    been_there = 1;
  }
  // look right(2)
  else if ((last_col < 14) && (array[(last_col + 1)][last_line] == '*'))
  {
    last_col = last_col + 1;
    been_there = 4;
  }
  // look left(4)
  else if ((last_col > 1) && (array[(last_col - 1)][last_line] == '*'))
  {
    last_col = last_col - 1;
    been_there = 2;
  }
  // look up(1)
  else if ((last_line > 1) && (array[last_col][(last_line - 1)] == '*'))
  {
    last_line = last_line - 1;
    been_there = 3;
  }
  move();
}
#endif
