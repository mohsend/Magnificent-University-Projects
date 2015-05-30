/*
 * homework of first session.
 */

#include <GL/glut.h>
using namespace std;

void display();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("mohsen");
	glutDisplayFunc(display);
	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glClearColor(1.0,1.0,1.0,0.0);
	glColor4f(0.0,0.0,1.0,0.0);
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();
	
	glFlush();
}
