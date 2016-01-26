/*
 * 
 */

#ifndef OUTPUT_HPP
#define OUTPUT_HPP 1

#include <GL/glut.h>

gameOfLife gol;

bool first = true;

void show_glut();
void init_glut(int ac, char **av);
void drawpixel(int j, int i, bool alive);
void keyboard(unsigned char, int, int);

const float s = 1.0/(GOL_WIDTH/2.0) - 0.005;
void drawpixel(int i, int j, bool alive)
{
  float x = (i/(GOL_HEIGHT/2.0)) - 1.0;
  float y = -((j/(GOL_WIDTH/2.0)) - 1.0);
  
  if (alive) glColor3f(1.0, 1.0, 1.0);
  else glColor3f(0.0, 0.0, 0.0);
  
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
  
  for (int j = 0; j < GOL_WIDTH; j++)
  {
    for (int i = 0; i < GOL_HEIGHT; i++)
    {
      drawpixel(i, j, gol.getLife(i, j));
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
  glutCreateWindow("Game of Life");
  
  glClearColor(0.7 ,0.7 ,0.7 ,0.0);
	glLoadIdentity();
  
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(show_glut);
  glutMainLoop();
}

void keyboard(unsigned char key, int a, int b)
{
  switch (key)
  {
    case(' '):
      gol.nextgen();
      glutPostRedisplay();
    break;
    case(27): // esc
    case('q'):
    case('Q'):
      exit(0);
    break;
  }
}
#endif
