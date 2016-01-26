/*
 * 
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

void Display() {}
void bresenham (float x1, float x2, float y1, float y2);
void init();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(20,20);
	glutCreateWindow("Bresenham Algorith for Lines");
	init();
	bresenham(1,1,100,100);
	glutDisplayFunc(Display);
	
	glutMainLoop();
}

void bresenham(float x1, float x2, float y1, float y2)
{
	float diff = (y2-y1)/(x2-x1);
	float x = x1;
	float y = y1;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
	
	float error = 0;
	
	while (x < x2)
	{
		error += diff;
		if (error >= 0.5)
		{
			y += 1;
			error -= 1;
		}
		
	x += 1;
	
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();
	}
	glFlush();
}

void init()
{
	glClearColor(0.0 ,0.0 ,0.0 ,0.0);
	glColor4f(1.0, 0.0, 1.0, 0.0);
	//glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(-1.0,1.0,-1.0,1.0);
}
