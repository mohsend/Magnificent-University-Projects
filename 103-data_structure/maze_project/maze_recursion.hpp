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
    char array[LINS][COLS];
  public:
    maze();
    void init_with_file (char*);
    void show();
    void start();
    bool solve(int x, int y);
};

maze::maze()
{
  
}

void maze::show()
{
  //cout << "line: " << y << "\tcol: " << x << endl;
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
    for (int i = 0; ch < COLS; i++)
    {
      fin >> skipws >> ch;
      array[i][j] = ch;
    }
  }
  show();
}

void maze::start()
{
  solve(0,3);
}

bool maze::solve(int X, int Y)
{
// Make the move (if it's wrong, we will backtrack later.
    array[Y][X] = '*';

    // If you want progressive update, uncomment these lines...
    show();
    cin.get();

    // Check if we have reached our goal.
    if (array[X][Y] == 'G')
    {
        return true;
    }
  // Recursively search for our goal.
    if (X > 0 && array[Y][X - 1] == '.' && solve(X - 1, Y))
    {
        return true;
    }
    if (X < COLS && array[Y][X + 1] == '.' && solve(X + 1, Y))
    {
        return true;
    }
    if (Y > 0 && array[Y - 1][X] == '.' && solve(X, Y - 1))
    {
        return true;
    }
    if (Y < LINS && array[Y + 1][X] == '.' && solve(X, Y + 1))
    {
        return true;
    }

    // Otherwise we need to backtrack and find another solution.
    array[Y][X] = '.';

    // If you want progressive update, uncomment these lines...
    //PrintDaarray();
    //Sleep(50);
    return false;
}
#endif
