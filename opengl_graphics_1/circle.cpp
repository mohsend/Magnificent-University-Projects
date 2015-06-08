/*
 * homework of second session.
 */

#include <GL/glut.h>
#include <cmath>
#include <iostream>
#define DEG_TO_RAD 0.0174533
using namespace std;

void display();
void init();
void keyboard(unsigned char key, int a, int b);
void circle(int startdeg, int enddeg, float radius);
void scale();

int level = 0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Circle");
	glutDisplayFunc(display);
	init();
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}

void init()
{
	glClearColor(1.0 ,1.0 ,1.0 ,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (level > 0)
	{
		scale();
		glColor4f(0.0, 0.0, 0.0, 0.0);
		circle(0, 360, 1.0);
	}
	if (level > 1)
	{
		scale();
		glColor4f(0.5, 0.5, 0.5, 0.0);
		glBegin(GL_TRIANGLES);
			for (int d = 0; d <= 60; d += 60)
				for (int dd = 0; dd <= 240; dd += 120)
					glVertex2d(sin((d + dd) * DEG_TO_RAD) * R, cos((d + dd) * DEG_TO_RAD) * R);
		glEnd();
		glLoadIdentity();
	}
	if (level > 2)
	{
		scale();
		glColor4f(1.0, 1.0, 1.0, 0.0);
		circle(0, 360, 0.57);
	}
	glFlush();
}

void circle(int startdeg, int enddeg, float radius)
{
		glBegin(GL_TRIANGLE_FAN);
			glVertex2d(0.0, 0.0);
			for (int d = startdeg; d <= enddeg; d++)
				glVertex2d(sin(d * DEG_TO_RAD) * radius, cos(d * DEG_TO_RAD) * radius);
		glEnd();
		glLoadIdentity();
}

void scale()
{
	if ( level > 3)
			glScalef(1.0, 0.5, 1.0);
}

void keyboard(unsigned char key, int a, int b)
{
  switch (key)
  { 
    case(' '):
    case('.'):
    case('>'):
      level = (level < 4)? level + 1 : level;
    break;
    
    case(','):
    case('<'):
      level = (level > 0)? level - 1 : level;
    break;
    
    case 27:	// Escape key
      exit(0);
    break;
  }
  glutPostRedisplay();
}
