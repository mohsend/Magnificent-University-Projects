/*
 *
 */

#include <iostream>
#include "conio.hpp"

using namespace std;

class parity
{
  private:
    int array[3][3];
    int current_i;
    int current_j;
    void show_underline(int i, int j);
    void move_up();
    void move_down();
    void move_left();
    void move_right();
  public:
    parity();
    void play();
    void show();
    void get_input();
};

int main(int argc, char ** argv)
{
  parity n;
  n.play();
  return 0;
}

parity::parity()
{
  current_i = 1;
  current_j = 1;
  
  
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      array[i][j] = 0;
    }
  }
}

void parity::show()
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      cout << array[i][j] << '\t';
    }
    cout << endl;
    show_underline(i, j);
  }
}

void parity::show_underline(int i, int j)
{
  if (i == current_i)
  {
    if (current_j == 0)
    {
      cout << "---" << endl;
    }
    if (current_j == 1)
    {
      cout << "       ---" << endl;
    }
    if (current_j == 2)
    {
      cout << "               ---" << endl;
    }
  }
  else
  {
    cout << endl;
  }
}

void parity::get_input()
{
  move_up();
}

void parity::move_up()
{
  if (current_j == 2)
  {
    return;
  }
  else
  {
    current_j--;
  }
}

void parity::move_down()
{
  if (current_j == 2)
  {
    return;
  }
  else
  {
    current_j++;
  }
}

void parity::move_left()
{
  if (current_i == 0)
  {
    return;
  }
  else
  {
    current_i--;
  }
}

void parity::move_right()
{
  if (current_i == 2)
  {
    return;
  }
  else
  {
    current_i++;
  }
}

void parity::play()
{
 // while (1)
  {
    show();
    get_input();
  }
}
