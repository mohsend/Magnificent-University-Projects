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
    char array[15][15];
    int cmax;
    int rmax;
  public:
    maze();
    void init_with_file (char*);
    void show();
    void start();
    void mfree(int x, int y);
    bool japa(int x, int y);
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
  /*
  for (int j = 0; j < 15; j++)
  {
    for (int i = 0; ch != '\n'; i++)
    {
      fin >> ch;
      //cout << ch;
      cmax = i;
    }
    rmax = j;
  }
  */
  cmax = 15; rmax = 15;
  cout << cmax << ' ' << rmax << endl;
  
  //array = new char[rmax][cmax];
  
  for (int j = 0; j < rmax; j++)
  {
    for (int i = 0; ch < cmax; i++)
    {
      fin >> skipws >> ch;
      array[i][j] = ch;
    }
  }
}

void maze::start()
{
  for (int j = 0; j <= rmax; j++)
  {
    if (array[0][j] == '.')
    {
      mfree(0, j);
    }
  }
}

void maze::mfree(int x, int y)
{
  show();
  cin.get();
  if (array[x][y] == 'G')
  {
    cout << "Found it!" << endl;
  }
  else
  {
    array[x][y] = '*';
    // right
    if (japa(x + 1, y))
    {
      mfree(x + 1, y);
    }
    // down
    if (japa(x, y + 1))
    {
      mfree(x, y + 1);
    }
    // up
    if (japa(x, y - 1))
    {
      mfree(x, y - 1);
    }
    // left
    if (japa(x - 1, y))
    {
      mfree(x - 1, y);
    }
    array[x][y] = '.';
  }
}

bool maze::japa(int x, int y)
{
  if (array[x][y] == '#')
  {
    return false;
  }
  else if (array[x][y] == '.')
  {
    return true;
  }
}

#endif
