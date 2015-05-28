#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265359

using namespace std;

double deg = 0.0;

void mitsubishi();
void rotate();
void init();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("mitsubishi");
	//glutIdleFunc(rotate);
	glutDisplayFunc(mitsubishi);
	init();
	glutMainLoop();
}

void init()
{
	glClearColor(1.0 ,1.0 ,1.0 ,0.0);
	glColor4f(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void mitsubishi()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4d(deg/6, 0.0, deg/6 , 0.0);
	glPolygonMode(GL_FRONT, GL_FILL);
	for (double d = PI/2.0; d < 2.0*PI; d += 2*PI/3.0)
	{
		glBegin(GL_POLYGON);
			glVertex2d(0.0,0.0);
			glVertex2d(cos(d + deg - PI/6), sin(d + deg - PI/6));
			glVertex2d(cos(d + deg), sin(d + deg));
			glVertex2d(cos(d + deg + PI/6), sin(d + deg + PI/6));
		glEnd();
		glLoadIdentity();
	}
	glutSwapBuffers();
}

void rotate()
{
	deg = (deg < 2*PI) ? deg + 0.05 : 0;
	 glutPostRedisplay();
}
