/*
 * 
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

int singleb, doubleb;

void display()
{

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
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);
	singleb = glutCreateWindow("window single");
	glutDisplayFunc(display1);
  
  glutCreateSubWindow(single, 100,100,300,300);
  glutDisplayFunc(display1);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  
  
	init();
	glutMainLoop();
}
