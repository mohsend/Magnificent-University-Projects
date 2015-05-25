// Rotating Cube
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "common.hpp"


GLfloat theta = 0.0, x_axes = 1.0, y_axes = 1.0, z_axes = 1.0;

void display();
void init();
void cube();
void axis();
void polygon(int a, int b, int c, int d);
void test();
void keyboard(unsigned char, int, int);

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef(theta, x_axes, y_axes, z_axes);
  cube();
  axis();
  glutSwapBuffers();
}

void cube()
{
  polygon(0, 3, 2, 1);
  polygon(2, 3, 7, 6);
  polygon(3, 0, 4, 7);
  polygon(1, 2, 6, 5);
  polygon(4, 5, 6, 7);
  polygon(5, 4, 0, 1);
}

void axis()
{
  glBegin(GL_LINES);
    glColor3fv(color[3]);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(x_axes*10, y_axes*10, z_axes*10);
  glEnd();
}

void polygon(int a, int b, int c, int d)
{
  glBegin(GL_POLYGON);
    glColor3fv(color[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(color[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(color[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(color[d]);
    glVertex3fv(vertices[d]);
  glEnd();
}

void init()
{
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Rotating Cube");
  
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);
  
  init();
  glutMainLoop();
}


void keyboard(unsigned char key, int a, int b)
{
  switch (key)
  {
    case('a'):
    case('A'):
    //case(GLUT_KEY_LEFT):
      x_axes -= 0.1;
    break;
    case('d'):
    case('D'):
    //case(GLUT_KEY_RIGHT):
      x_axes += 0.1;
    break;
    case('w'):
    case('W'):
    //case(GLUT_KEY_LEFT):
      z_axes -= 0.1;
    break;
    case('s'):
    case('S'):
    //case(GLUT_KEY_RIGHT):
      z_axes += 0.1;
    break;
    case(' '):
    case('.'):
    case('>'):
      theta += 2.0;
    break;
    case(','):
    case('<'):
      theta -= 2.0;
    break;
    case 27:			// Escape key
      exit(0);
    break;
  }
  glutPostRedisplay();
}
