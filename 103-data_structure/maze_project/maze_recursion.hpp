/*
 * 
 */

#ifndef MAZE_HPP
#define MAZE_HPP 1

#define COLS  15
#define ROWS  15


#include <iostream>
#include <fstream>
using namespace std;

class maze
{
  private:
    char array[ROWS][COLS];
    int steps;
  public:
    maze();
    void init_with_file (char*);
    void show();
    void start();
    bool solve(int x, int y);
};

maze::maze()
{
  steps = 0;
}


void maze::show()
{
  cout << "Steps: " << steps++ << endl;
  char ch;
  for (int j = 0; j < ROWS; j++)
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
  for (int j = 0; j < ROWS; j++)
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
  // left line
  for (int j = 0; j < ROWS; j++)
  {
    if (array[0][j] == '.')
    {
      solve(j, 0);
      return;
    }
  }
  // right line
  for (int j = 0; j < ROWS; j++)
  {
    if (array[0][j] == '.')
    {
      solve(j, COLS);
      return;
    }
  }
}

bool maze::solve(int X, int Y)
{
  // foot-print
  array[Y][X] = '*';

  show();
  cin.get();

  // Check if we have reached Ganj
  if (array[X][Y] == 'G' || array[X+1][Y] == 'G' || array[X-1][Y] == 'G' || array[X][Y+1] == 'G' || array[X][Y-1] == 'G')
  {
      return true;
  }
  // Recursive search
  if (X > 0 && array[Y][X - 1] == '.' && solve(X - 1, Y)) //left
  {
      return true;
  }
  if (X < COLS && array[Y][X + 1] == '.' && solve(X + 1, Y)) // right
  {
      return true;
  }
  if (Y > 0 && array[Y - 1][X] == '.' && solve(X, Y - 1)) // top
  {
      return true;
  }
  if (Y < ROWS && array[Y + 1][X] == '.' && solve(X, Y + 1)) // down
  {
      return true;
  }

  // goes back
  array[Y][X] = '.';
  
  return false;
}
#endif
