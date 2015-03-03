/*
 * squares inside other squares
 * at the start left buttom must be pushed
 */

//#include <stdlib>
#include <GL/glut.h>

// every program must call glutDisplayFunc even if it is empty
void display() {}

void drawsquare(int x, int y)
{
  int n, i;
  float m, ax, bx, by, cx, cy, dx, dy, x1, y1, x2, y2, x3, x4, y4, a, b;
  
  a = x;
  b = 500 - y; // co-ordinate of mouse is upper left corner
  
  n = 25; // number of squares
  m = 0.9; // parameter of line
  
  ax = a; ay = b;
  bx = 150.0 + a; by = b;
  cx = 150.0 + a; cy = 150.0 + b;
  dx = a; dy = 150.0 + b;
  
  glClear(GL_COLOR_BUFFER_BIT);
  
}
