 /*
	* Draws a checkered sphere with user-defined number of slices.
	* Rotates the sphere.
	* changes colors.
	*/

#include "main.hpp"

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Checkered Sphere");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	init();
	instructions();
	glutMainLoop();

	return 0;
}

void checkeredSphere (float R, int slices)
{
	bool c = true;
	float u = -0.5, v = 0.0;
	const float t = 1.0/slices, P = 3.1415;
	GLfloat poly[12];
	for (int i = 1; i <= slices; i++)
	{
		for (int j = 1; j <= slices; ++j)
		{
			poly[0] = R*cos(P*u)*cos(2.0*P*v);
			poly[1] = R*cos(P*u)*sin(2.0*P*v);
			poly[2] = R*sin(P*u);

			poly[3] = R*cos(P*(u+t))*cos(2.0*P*v);
			poly[4] = R*cos(P*(u+t))*sin(2.0*P*v);
			poly[5] = R*sin(P*(u+t));

			poly[6] = R*cos(P*(u+t))*cos(2.0*P*(v+t));
			poly[7] = R*cos(P*(u+t))*sin(2.0*P*(v+t));
			poly[8] = R*sin(P*(u+t));

			poly[9] = R*cos(P*u)*cos(2.0*P*(v+t));
			poly[10] = R*cos(P*u)*sin(2.0*P*(v+t));
			poly[11] = R*sin(P*u);

			if (mode & 1)
			{
				if (c) glColor3fv(color[c1]);
				else glColor3fv(color[c2]);
				c = !c; // toggles between colors
			}

			glBegin(GL_QUADS);
				for (int i = 0; i <= 9; i += 3) {
					if (mode & 2)
					{
						if (c) glColor3fv(color[c1]);
						else glColor3fv(color[c2]);
						c = !c; // toggles between colors
					}
					glVertex4f(poly[i], poly[i+1], poly[i+2], 1.0);
				}
			glEnd();

			v += t; // v changes from 0 to 360 degrees
		}
		u += t; // u changes from -90 to +90 degrees
		v = 0.0;
	}
	glLoadIdentity();
}

void init ()
{
	glEnable(GL_DEPTH_TEST); // Z-buffer
	glClearColor(0.2, 0.2, 0.2, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200, 200, -200, 200, -200, 200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display ()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0);
	axis();
	glRotatef(degrees, rx, ry, rz);
	checkeredSphere(150, sections);
	glutSwapBuffers();
}

void axis()
{
	const int mag = 1000;
  glBegin(GL_LINES);
    glColor3fv(color[3]);
    glVertex3f(-rx*mag, -ry*mag, -rz*mag);
    glVertex3f(rx*mag, ry*mag, rz*mag);
  glEnd();
}

void animate()
{
	if (doAnimate)
	{
		degrees++;
		if (degrees == 359) degrees = 0;
		glutPostRedisplay();
	}
}
