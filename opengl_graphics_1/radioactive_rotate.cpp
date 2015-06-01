#include <GL/glut.h>
#include <iostream>
#include <cmath>

#define PI 3.14159265359

using namespace std;

int deg = 0;

void radioactive();
void time_pass();
void init();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
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
	
	float red = cos (2.0 * PI * (deg/120.0));
	
	for (double d = 0.0; d < 2.0*PI; d += 2*PI/3.0)
	{
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(red, 0.0, 0.0);
			glVertex2d(0.0,0.0);
			glColor3f(0.0, 0.0, 0.0);
			for (double dis = 0.0; dis < 2*PI/6; dis += 0.1)
			{
				glVertex2d(cos(d + dis), sin(d + dis));
			}
		glEnd();
	}
	
	glLoadIdentity();
	glutSwapBuffers();
}

void time_pass()
{
	deg = (deg < 120) ? deg + 1 : 0;
	glutPostRedisplay();
}
