#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <iostream>

#define PI 3.14159265359

using namespace std;

double a = -17;
double v = 0;
double y = 0.0;
double x = 0.0;
double yzero = 0;
double t = 0;

void radioactive();
void time_pass();
void init();
void Mouse( int button, int state, int x, int y);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bounce");
	glutIdleFunc(time_pass);
	glutDisplayFunc(radioactive);
	init();
	glutMouseFunc(Mouse);
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
	glColor3f(0.0, 0.0, 0.0);
	//gluLookAt(0.0,5.0,0.0, 0.0,0.0,0.0, 1.0,1.0,0.0);
	glOrtho(-4.0, 4.0, 0.0, 8.0, -4.0, 4.0);
	
	glTranslatef(x, y, 0.0);
	glutWireSphere(0.4, 15, 15);
	
	glLoadIdentity();
	glutSwapBuffers();
}

void time_pass()
{
	y = a * t * t + v * t + yzero;
	t += 0.01;
	if (y < 0.50)
	{
		yzero = 0.50;
		v = -a * t * 0.80;
		t = 0;
	}
	glutPostRedisplay();
}

void Mouse( int button, int state, int xp, int yp ) {
	if ( button==GLUT_LEFT_BUTTON && state==GLUT_DOWN ) {
		x = (xp / 250.0) * 4.0 - 4.0;
		yzero = -((yp / 250.0) - 1.0) * 4.0 + 4.0;
    t = 0;
    v = 18;
    cout << x << '\t' << yzero << endl;
	}
}
