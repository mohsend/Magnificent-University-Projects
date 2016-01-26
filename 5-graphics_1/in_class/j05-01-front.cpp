/*
 * 
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//
	gluLookAt(0.0,1.0,1.0,0.0,0.0,0.0,0.0,0.0,1.0);
	//
	glutWireSphere(0.5, 20, 20);
	//glutWireTeapot(1.0);
	glFlush();
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// 
	glOrtho(-4.0,4.0,-4.0,4.0,-4.0,4.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("tasvir e isometric");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
