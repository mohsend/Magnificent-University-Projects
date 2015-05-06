/*
 * 
 */

#include <GL/glut.h>
using namespace std;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//
	gluLookAt(0.0,0.0,0.0, 1.0,1.0,1.0, 0.0,1.0,0.0);
	glTranslatef(0.0,0.0,-3.0);
	//
	//glutWireCube(1.0);
	glutWireTeapot(1.0);
	glFlush();
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// 
	//glFrustum(-1.0,1.0,-1.0,1.0,1.0,10.0);
	gluPerspective(60.0,1.0,1.0,10.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //forever alone glut
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("tasvir e perspective");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
