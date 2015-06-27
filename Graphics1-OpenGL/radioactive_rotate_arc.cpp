#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int deg = 0;

void radioactive();
void time_pass();
void init();
void arc(int startdeg, int enddeg, double radius);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Radioactive");
	glutIdleFunc(time_pass);
	glutDisplayFunc(radioactive);
	init();
	glutMainLoop();
}

void init()
{
	glClearColor(1.0 ,1.0 ,0.0 ,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void radioactive()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glRotatef(deg, 0.0, 0.0, 1.0);
	glColor4f(0.0, 0.0, 0.0, 0.0);
	for (int d = 0; d <= 360; d += 120)
	{
		arc(d, d + 60, 1.0);
	}
	glLoadIdentity();
	
	glColor4f(1.0, 1.0, 0.0, 0.0);
	arc(0, 360, 0.2);
	glLoadIdentity();
	
	glColor4f(0.0, 0.0, 0.0, 0.0);
	arc(0, 360, 0.17);
	glLoadIdentity();
	
	glutSwapBuffers();
}

void time_pass()
{
	deg = (deg < 120) ? deg + 1 : 0;
	glutPostRedisplay();
}

void arc(int startdeg, int enddeg, double radius)
{
	double toRad = 0.0174532925;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(0.0,0.0);
	for (int dis = startdeg; dis <= enddeg; dis++)
	{
		glVertex2d(cos(dis * toRad) * radius, sin(dis * toRad) * radius);
	}
	glEnd();
}
