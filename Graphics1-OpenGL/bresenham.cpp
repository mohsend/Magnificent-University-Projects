#include <GL/glut.h>

// WARNING! HAS BUGS AND PROBLEMS!

void draw_pixel(int x, int y)
{
  float xf = (x / 250.0) - 1.0;
  float yf = -((y / 250.0) - 1.0);
  
  glBegin(GL_POINTS);
    glVertex2f(xf, yf);
  glEnd();
}

void draw_line(int x1, int y1, int x2, int y2)
{
  int x = x1; int y = y1;
  float diff = (float)(y2 - y1)/(x2 - x1);
  float error = 0.0;
  while (x < x2)
  {
    error += diff;
    if (error >= 0.5)
    {
      y = y + 1;
      error = error - 1.0;
    }
    x++;
    draw_pixel(x, y);
  }
  glFlush();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  glClearColor(1.0,1.0,1.0,0.0);
  glColor4f(0.0,0.0,1.0,0.0);
  
  draw_line(1, 1, 100, 300);
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("bresenham");
  gluOrtho2D(-1.0,1.0,-1.0,1.0);
  glutDisplayFunc(display);

  glutMainLoop();
}
