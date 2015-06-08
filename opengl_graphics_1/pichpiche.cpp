/*
 * homework of second session.
 */

#define DEG_TO_RAD 0.0174533

#define ADAD 0.0174533

#include <GL/glut.h>
#include <cmath>
using namespace std;

void display();
void init();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Template");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}

void init()
{
	glClearColor(0.0 ,0.0 ,0.0 ,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1.0, 0.0, 1.0, 0.0);
	
	float x = 0.0;
	float y = 0.0;
	
	float d = ADAD;
	glBegin(GL_LINE_STRIP);
		
		for (int i = 1; i <= 60; i++)
		{
			glVertex2f(x, y);
			x -= d;
			glVertex2f(x, y);
			y += d;
			glVertex2f(x, y);
			d += ADAD;
			glVertex2f(x, y);
			x += d;
			glVertex2f(x, y);
			y -= d;
			glVertex2f(x, y);
			d += ADAD;
		}
	glEnd();
	glFlush();
}

