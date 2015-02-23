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

enum dir
{
  up,
  right,
  down,
  left
};

class maze
{
  private:
    char array[COLS][LINS];
    int last_col;
    int last_line;
    dir hand;
  public:
    maze();
    void init_with_file (char*);
    void show();
    void start();
    void move_dir();
    void hand_dir();
};

maze::maze()
{

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

void maze::move_dir(dir to)
{
  if (to = up)
    last_line = last_line - 1;
  if (to = down)
    last_line = last_line + 1;
  if (to = right)
    last_col = last_col + 1;
  if (to = left)
    last_col = last_col - 1;
  
  // mark where it's been.
  array[last_col][last_line] = '*';
  show();
  return false;
}

void hand_dir()
{
  if (hand == )
}
#endif
