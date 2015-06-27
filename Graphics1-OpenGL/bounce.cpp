#include <GL/glut.h>
#include <cmath>
#include <iostream>

#define PI 3.14159265359

using namespace std;

double a = -10;
double v = 0;
double y = 0.0;
double x = 0.0;
double y00 = 5;
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
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2d(x, y);
		for (double dis = 0.0; dis < 2.1*PI; dis += 0.1)
		{
			glVertex2d(0.1*cos(dis) + x, 0.1*sin(dis) + y);
		}
	glEnd();
	
	glLoadIdentity();
	glutSwapBuffers();
}

void time_pass()
{
	y = a * t * t + v * t + y00;
	t += 0.01;
	if (y < -0.90)
	{
		y00 = -0.90;
		v = -a * t * 0.83;
		t = 0;
	}
	glutPostRedisplay();
}

void Mouse( int button, int state, int xp, int yp ) {
	if ( button==GLUT_LEFT_BUTTON && state==GLUT_DOWN ) {
		x = (xp / 250.0d) - 1.0d;
		y00 = -((yp / 250.0d) - 1.0d);
    t = 0;
    v = 8;
    cout << x << '\t' << y00 << endl;
	}
}
