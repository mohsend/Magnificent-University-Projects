/*
 * homework of second session.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

void display();
void draw_line(float x1, float y1, float x2, float y2);
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
	//gluOrtho2d(-1int.0,1.0,-1.0,1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1.0, 0.0, 1.0, 0.0);
	draw_line(0.5, -1.0, 1.0, 0.5);
	glFlush();
}

void draw_line(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	for (float alpha = 0.0; alpha <= 1.0; alpha += 0.005)
	{
		glBegin(GL_POINTS);
			glVertex2f(x1 + alpha * dx, y1 + alpha * dy);
		glEnd();
	}
}
