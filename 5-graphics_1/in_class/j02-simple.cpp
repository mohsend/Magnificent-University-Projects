/*
 * homework of second session.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

void display_polygon();
void display_lines();
void display_points();
void init();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Simple 2");
	glutDisplayFunc(display_polygon);
	init();
	glutMainLoop();
}

void init()
{
	glClearColor(0.0 ,0.0 ,0.0 ,0.0);
	glColor4f(1.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(-1.0,1.0,-1.0,1.0);
}

void display_polygon()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT, GL_FILL);
	//glPolygonMode(GL_BACK, GL_POINT);
	glBegin(GL_POLYGON);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();
	
	glFlush();
}

void display_points()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(3.0);
	
	glBegin(GL_POINTS);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();
	
	glFlush();
}

void display_lines()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(3.0);
	
	glBegin(GL_LINES);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();
	
	glFlush();
}

void display_stipple()
{
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x3C);
	// glLineStipple(int factor, GLbyte pattern)
	
	glDisable(GL_LINE_STIPPLE);
}
