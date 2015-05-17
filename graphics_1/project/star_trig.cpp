// Draws 2D star
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include "common.hpp"

#define PI 3.14159265359

void par(double hx, double hy, double lx, double ly, int colornum);
void addPar(int);
void star();
void star2();
void updateWindows();
void Mouse( int button, int state, int x, int y );
void keyboard(unsigned char key, int a, int b);
void display();
void display2();
void init();

int color1 = 3, color2 = 2;
int clicks = 1;
int win1, win2;
double IncFactor = PI;

void star()
{  
  glBegin(GL_TRIANGLE_FAN);
    glColor3fv(color[color1]);
    glVertex2f(0.0, 0.0);
    glColor3fv(color[color2]);
    for (double deg = 0.0; deg < 2*PI; deg += IncFactor)
    {
      glVertex2f(cos(deg), sin(deg));
      glVertex2f(0.2 * cos(deg + IncFactor/2.0), 0.2 * sin(deg + IncFactor/2.0));
    }
    glVertex2f(1.0, 0.0);
  glEnd();
  glLoadIdentity();
}

void par(double hx, double hy, double lx, double ly, int colornum)
{
  glBegin(GL_TRIANGLE_FAN);
    glColor3fv(color[colornum]);
    glVertex2d(0.0,0.0);
    glVertex2d(hx,hy);
    glVertex2d(lx,ly);
  glEnd();
  glLoadIdentity();
}

void star2()
{
  for (double deg = 0.0; deg < 2*PI; deg += IncFactor)
    {
      par(cos(deg), sin(deg), 0.2 * cos(deg + IncFactor/2.0), 0.2 * sin(deg + IncFactor/2.0), color1);
      par(0.2 * sin(deg + IncFactor/2.0), 0.2 * cos(deg + IncFactor/2.0), sin(deg), cos(deg), color2);
    }
}

void addPar(int no = 1)
{
  clicks += no;
  IncFactor = PI/(clicks/2.0);
  updateWindows();
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
  win1 = glutCreateWindow("Star fade color");
  glutDisplayFunc(display);
  
  glutMouseFunc(Mouse);
  glutKeyboardFunc(keyboard);
  
  // window two
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(600, 0);
  win2 = glutCreateWindow("Star solid color");
  glutDisplayFunc(display2); 
  
  glutMouseFunc(Mouse);
  glutKeyboardFunc(keyboard);
  
  init();
  glutMainLoop();
}


void updateWindows()
{
  glutSetWindow(win1);
  glutPostRedisplay();
  glutSetWindow(win2);
  glutPostRedisplay();
}

void keyboard(unsigned char key, int a, int b)
{
  switch (key)
  {
    case('a'):
    case('A'):
      color1 = (color1 < 8)? color1 + 1 : color1;
    break;
    
    case('q'):
    case('Q'):
      color1 = (color1 > 0)? color1 - 1 : color1;
    break;
    
    case('w'):
    case('W'):
      color2 = (color2 < 8)? color2 + 1 : color2;
    break;
    
    case('s'):
    case('S'):
      color2 = (color2 > 0)? color2 - 1 : color2;
    break;
    
    case(' '):
    case('.'):
    case('>'):
      addPar();
    break;
    
    case(','):
    case('<'):
      addPar(-1);
    break;
    
    case 27:			// Escape key
      exit(0);
    break;
  }
  
  updateWindows();
}

void Mouse( int button, int state, int x, int y ) {
	if ( button==GLUT_LEFT_BUTTON && state==GLUT_DOWN ) {
    addPar();
	}
}

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
