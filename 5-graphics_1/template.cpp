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
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1.0, 0.0, 1.0, 0.0);
	
	glFlush();
}

