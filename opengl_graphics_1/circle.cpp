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

int level = 0;
double R = 1.0;
double r = 0.57; //sqrt(r*r*cos(30 * DEG_TO_RAD)*cos(30 * DEG_TO_RAD) + r*r*sin(30 * DEG_TO_RAD)*sin(30 * DEG_TO_RAD));

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Template");
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
		if ( level > 3)
			glScalef(1.0, 0.5, 1.0);
		glColor4f(0.0, 0.0, 0.0, 0.0);
		glBegin(GL_TRIANGLE_FAN);
			glVertex2d(0.0, 0.0);
			for (int d = 0; d < 361; d++)
			{
				glVertex2d(sin(d * DEG_TO_RAD) * R, cos(d * DEG_TO_RAD) * R);
			}
		glEnd();
		glLoadIdentity();
	}
	if (level > 1)
	{
		if ( level > 3)
			glScalef(1.0, 0.5, 1.0);
		glColor4f(0.5, 0.5, 0.5, 0.0);
		glBegin(GL_TRIANGLES);
			for (int d = 0; d < 70; d += 60)
			{
				glVertex2d(sin(d * DEG_TO_RAD) * R, cos(d * DEG_TO_RAD) * R);
				glVertex2d(sin((d + 120) * DEG_TO_RAD) * R, cos((d + 120) * DEG_TO_RAD) * R);
				glVertex2d(sin((d + 240) * DEG_TO_RAD) * R, cos((d + 240) * DEG_TO_RAD) * R);
			}
		glEnd();
		glLoadIdentity();
	}
	if (level > 2)
	{
		if ( level > 3)
			glScalef(1.0, 0.5, 1.0);
		glColor4f(1.0, 1.0, 1.0, 0.0);
		glBegin(GL_TRIANGLE_FAN);
			glVertex2d(0.0, 0.0);
			for (int d = 0; d < 361; d++)
			{
				glVertex2d(sin(d * DEG_TO_RAD) * r, cos(d * DEG_TO_RAD) * r);
			}
		glEnd();
		glLoadIdentity();
	}
	glFlush();
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
    
    case 27:			// Escape key
      exit(0);
    break;
  }
  glutPostRedisplay();
}
