/*
 * homework of first session.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
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


{
	m = 6; // تعداد دور
	n = 0.0; // parameter
	
	for ( int i = 1; i <= m; i++)
	{
		a = b = c = d = n/6.0;
		
		ax1 = a*x + a*(b*x - a*x);
		ay1 = a*y + a*(b*y - a*y);
		
		bx1 = b*x + b*(c*x - b*x);
		by1 = b*y + b*(c*y - B*y);
		
		cx1 = c*x + c*(c*x - b*x);
		cy1 = c*y + c*(c*y - B*y);
		
		dx1 = d*x + c*(c*x - b*x);
		dy1 = c*y + c*(c*y - B*y);
	}
}

{
	glBegin(GL_LINE_LOOP);
		glVertex2f(ax1,ay1);
		glVertex2f(bx1,by1);
		glVertex2f(cx1,cy1);
		glVertex2f(dx1,dy1);
	glEnd();
}
