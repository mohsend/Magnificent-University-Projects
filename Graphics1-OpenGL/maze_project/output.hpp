/*
 * 
 */

#ifndef OUTPUT_HPP
#define OUTPUT_HPP 1

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

bool first = true;

void show_glut();
void init_glut(int ac, char **av);
void drawpixel(int j, int i, char ch);

void drawpixel(int i, int j, char ch)
{
  float s = 1.0/(ROWS/2.0) - 0.01;
  float x = (i/(COLS/2.0)) - 1.0;
  float y = -((j/(ROWS/2.0)) - 1.0);
  
  if (ch == '#')
  {
    glColor3f(0.0, 0.0, 0.0);
  }
  else if (ch == '.')
  {
    glColor3f(1.0, 1.0, 1.0);
  }
  else if (ch == '*')
  {
    glColor3f(0.0, 1.0, 0.0);
  }
  else if (ch == 'G')
  {
    glColor3f(1.0, 1.0, 0.0);
  }
  
  glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex2f(x, y);
    glVertex2f(x + s, y);
    glVertex2f(x + s, y + s);
    glVertex2f(x, y + s);
	glEnd();
  glLoadIdentity();
}

void show_glut()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  
  for (int j = 0; j < ROWS; j++)
  {
    for (int i = 0; i < COLS; i++)
    {
      drawpixel(i, j, array[i][j]);
    }
  }
  glFlush();
}

void init_glut(int ac, char **av)
{
  glutInit(&ac, av);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("MAZE");
  
  glClearColor(0.7 ,0.7 ,0.7 ,0.0);
	glLoadIdentity();
  
  glutDisplayFunc(show_glut);
  glutMainLoop();
}

#endif
