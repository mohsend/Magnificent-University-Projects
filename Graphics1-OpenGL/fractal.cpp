/*
 * homework of second session.
 */

#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

void display();
void init();
void nextpixle();
void idle();
float hx, ax, bx, cx, mx, px, hy, ay, by, cy, my, py;


int main(int argc, char **argv)
{
	px = 0.0; py = 0.0;
	ax = 0.0; ay = 1.0;
	bx = -1.0; by = -1.0;
	cx = 1.0; cy = -1.0;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Fractal");
	glutDisplayFunc(display);
	init();
	glutIdleFunc(idle);
	glutMainLoop();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
	glColor4f(0.0 ,0.0 ,0.0 ,0.0);
	nextpixle();
	glFlush();
}

void nextpixle()
{
	switch (rand() % 3)
	{
		case 0:
			hx = ax; hy = ay;
		break;
		case 1:
			hx = bx; hy = by;
		break;
		case 2:
			hx = cx; hy = cy;
		break;
	}
	mx = (hx - px)/2.0; my = (hy - py)/2.0;
	glBegin(GL_POINTS);
		glVertex2f(mx, my);
	glEnd();
	px = mx; py = my;
	glLoadIdentity();
}

void idle()
{
	glutPostRedisplay();
}
