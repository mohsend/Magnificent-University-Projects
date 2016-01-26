#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

#define PI 3.14159265359
#define ZARIB 0.56

using namespace std;

int deg = 0;

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
	
	glutIdleFunc(rotate);
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
	glRotated(deg, 0.0, 0.0, 1.0);
	glColor4d(0.0, 0.0, 0.0 , 0.0);
	glPolygonMode(GL_FRONT, GL_FILL);
	for (double d = PI/2.0; d < 2.0*PI; d += 2*PI/3.0)
	{
		glBegin(GL_POLYGON);
			glVertex2d(0.0,0.0);
			glVertex2d(ZARIB * cos(d - PI/6.0), ZARIB * sin(d - PI/6.0));
			glVertex2d(cos(d), sin(d));
			glVertex2d(ZARIB * cos(d + PI/6.0), ZARIB * sin(d + PI/6.0));
		glEnd();
	}
	glLoadIdentity();
	glutSwapBuffers();
}

void rotate()
{
	deg = (deg < 120) ? deg + 1 : 0;
	glutPostRedisplay();
}
