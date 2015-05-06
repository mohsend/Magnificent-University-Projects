// Rotating Cube
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265

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

GLubyte name[3] = {'M', 'o', '\0'};

void display();
void init();
void par(GLfloat hx, GLfloat hy, GLfloat lx, GLfloat ly, int colornum);
void write(GLubyte text[]);
void star();

float sindeg(int deg)
{
  return (float)(sin((deg*2*PI/360)));
}

float cosdeg(int deg)
{
  return (float)(cos((deg*2*PI/360)));
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  /*
  for (int i = 0; i < 4; i++)
  {
    par( (1.0 * sindeg(i*90)), (1.0 * cosdeg(i*90)), (0.2 * sindeg(i*90)), (0.2 * cosdeg(i*90)),3 );
  }
  */
  star();
  
  
  glLoadIdentity();
  write(name);
  glLoadIdentity();
  glutSwapBuffers();
}

void par(GLfloat hx, GLfloat hy, GLfloat lx, GLfloat ly, int colornum)
{
  glBegin(GL_TRIANGLE_FAN);
    glColor3fv(color[colornum]);
    glVertex2f(0.0,0.0);
    glVertex2f(hx,hy);
    glVertex2f(lx,ly);
  glEnd();
}

void star()
{
  /*
  par(1.0, 0.0, 0.2, 0.2, 1);
  par(0.0, 1.0, 0.2, 0.2, 2);
  par(0.0, 1.0, -0.2, 0.2, 1);
  par(-1.0, 0.0, -0.2, 0.2, 2);
  par(-1.0, 0.0, -0.2, -0.2, 1);
  par(0.0, -1.0, -0.2, -0.2, 2);
  par(0.0, -1.0, 0.2, -0.2, 1);
  par(1.0, 0.0, 0.2, -0.2, 2);
  */
  
  glBegin(GL_TRIANGLE_FAN);
    glColor3fv(color[0]);
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.2, 0.2);
    
    glColor3fv(color[6]);
    glVertex2f(0.0, 1.0);
    glVertex2f(-0.2, 0.2);
    
    glColor3fv(color[0]);
    glVertex2f(-1.0, 0.0);
    glVertex2f(-0.2, -0.2);
    
    glColor3fv(color[6]);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.2, -0.2);
    
    glColor3fv(color[0]);
    
    glVertex2f(1.0, 0.0);
    
  glEnd();
}

void write(GLubyte text[])
{
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glRasterPos2i(100, 100);
  glColor3fv(color[4]);
  for(int p = 0; p < 3; p++)
  {
    glutStrokeCharacter(GLUT_STROKE_ROMAN, text[p]);
  }
  glFlush();
}


void init()
{
  glClearColor(0.0 ,0.0 ,0.0 ,0.0);
	glColor4f(1.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  //gluOrtho2D(0, 500, 0, 500);
  //glMatrixMode(GL_MODELVIEW);
  //glLoadIdentity();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Star");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
