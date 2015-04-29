// Rotating Cube
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLfloat vertices[][3] = {
  {-1.0, -1.0, -1.0},
  {-1.0, 1.0, -1.0},
  {1.0, 1.0, -1.0},
  {1.0, -1.0, -1.0},
  {-1.0, -1.0, 1.0},
  {-1.0, 1.0, 1.0},
  {1.0, 1.0, 1.0},
  {1.0, -1.0, 1.0}
  };
  
GLfloat color[][3] = {
  {0.0, 0.0, 0.0},
  {0.0, 1.0, 0.0},
  {1.0, 1.0, 0.0},
  {1.0, 0.0, 0.0},
  {0.0, 0.0, 1.0},
  {0.0, 1.0, 1.0},
  {1.0, 1.0, 1.0},
  {1.0, 0.0, 1.0}
  };

GLfloat theta = 0.0, x_axes = 1.0, y_axes = 1.0, z_axes = 1.0;

void display();
void init();
void cube();
void polygon(int a, int b, int c, int d);
void test();

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef(theta, x_axes, y_axes, z_axes);
  cube();
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

void polygon(int a, int b, int c, int d)
{
  glBegin(GL_POLYGON);
    glColor3fv(color[a]);
    glVertex3fv(color[a]);
    glColor3fv(color[b]);
    glVertex3fv(color[b]);
    glColor3fv(color[c]);
    glVertex3fv(color[c]);
    glColor3fv(color[d]);
    glVertex3fv(color[d]);
  glEnd();
}

void test()
{
  theta += 2.0;
  if (theta == 180.0)
    x_axes = -1 * x_axes;
  if (theta == 360.0)
    y_axes = -1 * y_axes;
  if (theta == 540.0)
    z_axes = -1 * z_axes;
  if (theta == 720.0)
    theta == -1 * theta;
  glutPostRedisplay();
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
  glutIdleFunc(test);
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
