// Draws 2D star
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "common.hpp"
  
void display();
void display2();
void init();
void par(GLfloat hx, GLfloat hy, GLfloat lx, GLfloat ly, int colornum);
void write(GLubyte text[]);
void star();
void star2();

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
  par(1.0, 0.0, 0.2, 0.2, 3);
  par(0.0, 1.0, 0.2, 0.2, 2);
  par(0.0, 1.0, -0.2, 0.2, 3);
  par(-1.0, 0.0, -0.2, 0.2, 2);
  par(-1.0, 0.0, -0.2, -0.2, 3);
  par(0.0, -1.0, -0.2, -0.2, 2);
  par(0.0, -1.0, 0.2, -0.2, 3);
  par(1.0, 0.0, 0.2, -0.2, 2);
}

void star()
{  
  glBegin(GL_TRIANGLE_FAN);
    glColor3fv(color[3]);
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.2, 0.2);
    
    glColor3fv(color[2]);
    glVertex2f(0.0, 1.0);
    glVertex2f(-0.2, 0.2);
    
    glColor3fv(color[3]);
    glVertex2f(-1.0, 0.0);
    glVertex2f(-0.2, -0.2);
    
    glColor3fv(color[2]);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.2, -0.2);
    glVertex2f(1.0, 0.0);
  glEnd();
  glLoadIdentity();
}

void init()
{
  glClearColor(0.0 ,0.0 ,0.0 ,0.0);
	glColor4f(1.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  
  // window one
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Star");
  glutDisplayFunc(display);
  
  // window two
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(600, 0);
  glutCreateWindow("Star2");
  glutDisplayFunc(display2); 
  
  init();
  glutMainLoop();
}
