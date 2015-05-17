// Draws 2D star
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include "common.hpp"

#define PI 3.14159265359
  
void display();
void display2();
void init();
void par(GLfloat hx, GLfloat hy, GLfloat lx, GLfloat ly, int colornum);
void write(GLubyte text[]);
void star();
void star2();
void myMouseFunc( int button, int state, int x, int y );
void keyboard(unsigned char key, int a, int b);
void updateWindows();
void addPar(int);

int c1 = 3, c2 = 2;
int win1, win2;

double IncFactor = PI;
int clicks = 1;

void addPar(int no = 1)
{
  clicks += no;
  IncFactor = PI/(clicks/2.0);
  updateWindows();
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
      c1 = (c1 < 8)? c1 + 1 : c1;
    break;
    
    case('q'):
    case('Q'):
      c1 = (c1 > 0)? c1 - 1 : c1;
    break;
    
    case('w'):
    case('W'):
      c2 = (c2 < 8)? c2 + 1 : c2;
    break;
    
    case('s'):
    case('S'):
      c2 = (c2 > 0)? c2 - 1 : c2;
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

void myMouseFunc( int button, int state, int x, int y ) {
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
      par(cos(deg), sin(deg), 0.2 * cos(deg + IncFactor/2.0), 0.2 * sin(deg + IncFactor/2.0), c1);
      par(0.2 * sin(deg + IncFactor/2.0), 0.2 * cos(deg + IncFactor/2.0), sin(deg), cos(deg), c2);
    }
}

void star()
{  
  glBegin(GL_TRIANGLE_FAN);
    glColor3fv(color[c1]);
    glVertex2f(0.0, 0.0);
    glColor3fv(color[c2]);
    for (double deg = 0.0; deg < 2*PI; deg += IncFactor)
    {
      glVertex2f(cos(deg), sin(deg));
      glVertex2f(0.2 * cos(deg + IncFactor/2.0), 0.2 * sin(deg + IncFactor/2.0));
    }
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
  win1 = glutCreateWindow("Star fade color");
  glutDisplayFunc(display);
  
  glutMouseFunc(myMouseFunc);
  glutKeyboardFunc(keyboard);
  
  // window two
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(600, 0);
  win2 = glutCreateWindow("Star solid color");
  glutDisplayFunc(display2); 
  
  glutMouseFunc(myMouseFunc);
  glutKeyboardFunc(keyboard);
  
  init();
  glutMainLoop();
}
