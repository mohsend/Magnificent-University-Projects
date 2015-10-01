// Draws 2D star

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "common.hpp"
  
void display();
void display2();
void init();
void par(GLfloat hx, GLfloat hy, GLfloat lx, GLfloat ly, int colornum);
void write(GLubyte text[]);
void star();
void star2();

const int c1 = 3, c2 = 2;


void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  star();
  glutSwapBuffers();
}

void display2()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  star2();
  glutSwapBuffers();
}

void par(GLfloat hx, GLfloat hy, GLfloat lx, GLfloat ly, int colornum)
{
  glBegin(GL_TRIANGLE_FAN);
    glColor3fv(color[colornum]);
    glVertex2f(0.0,0.0);
    glVertex2f(hx,hy);
    glVertex2f(lx,ly);
  glEnd();
  glLoadIdentity();
}

void star2()
{
  par(1.0, 0.0, 0.2, 0.2, c1);
  par(0.0, 1.0, 0.2, 0.2, c2);
  par(0.0, 1.0, -0.2, 0.2, c1);
  par(-1.0, 0.0, -0.2, 0.2, c2);
  par(-1.0, 0.0, -0.2, -0.2, c1);
  par(0.0, -1.0, -0.2, -0.2, c2);
  par(0.0, -1.0, 0.2, -0.2, c1);
  par(1.0, 0.0, 0.2, -0.2, c2);
}

void star()
{  
  glBegin(GL_TRIANGLE_FAN);
    glColor3fv(color[c1]);
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.2, 0.2);
    
    glColor3fv(color[c2]);
    glVertex2f(0.0, 1.0);
    glVertex2f(-0.2, 0.2);
    
    glColor3fv(color[c1]);
    glVertex2f(-1.0, 0.0);
    glVertex2f(-0.2, -0.2);
    
    glColor3fv(color[c2]);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.2, -0.2);
    glVertex2f(1.0, 0.0);
  glEnd();
  glLoadIdentity();
}

void init()
{
  glClearColor(0.0 ,0.0 ,0.0 ,0.0);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  
  // window one
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Star fade color");
  glutDisplayFunc(display);
  
  // window two
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(600, 0);
  glutCreateWindow("Star solid color");
  glutDisplayFunc(display2); 
  
  init();
  glutMainLoop();
}
