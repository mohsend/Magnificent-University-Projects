/*
 * شکل فوق را برای سه دور کامل رسم کنید
 * هر خط بر خط قبل عمود است
 * هر خط از خط قبلی به اندازه یک سوم بزرگتر است
 * دو نقطه اول داده شده
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

void display() {};

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("mohsen");
	glutDisplayFunc(display);
	glutMainLoop();
}

{
	n = 3; // تعداد دور
	a = 1.0; // parameter
	
  // مولفه های بردار
  p = (x2 - x1); q = (y2 - y1);
  
	for ( int i = 1; i <= n; i++)
	{
    x2 = x1 + ap;
    
	}
}

{
	glBegin(GL_LINE_STRIP);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
    glVertex2f(x5,y5);
    x1 = x5; y1 = y5;
	glEnd();
}
