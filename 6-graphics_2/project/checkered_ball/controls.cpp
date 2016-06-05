 /*
  * handles keyboard controls and prints Instructions
  */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

using namespace std;

// Functions
void keyboard(unsigned char key, int a, int b);
void instructions();

// Globals
int c1 = 6; // The two colors of checkered pattern
int c2 = 3;
int* c = &c1;

double rx = 1.0; // Rotation vector
double ry = 1.0;
double rz = 0.0;

int degrees = 0; // Rotation degree
bool doAnimate = true; // Animation
int sections = 37; // Number of sections (slices) of the sphere
int colormode = 3; // 1: sudden change, 2: gradual change, 3: both 
int drawmode = 6; // 0: GL_POINTS, 1: GL_LINES, ...

void keyboard(unsigned char key, int a, int b)
{
  switch (key)
  {
    case('a'):
    case('A'):
    //case(GLUT_KEY_LEFT):
      ry -= 0.1;
    break;
    case('d'):
    case('D'):
    //case(GLUT_KEY_RIGHT):
      ry += 0.1;
    break;
    case('w'):
    case('W'):
    //case(GLUT_KEY_LEFT):
      rz -= 0.1;
    break;
    case('s'):
    case('S'):
    //case(GLUT_KEY_RIGHT):
      rz += 0.1;
    break;
    case(' '):
      doAnimate = !doAnimate;
    break;
    case('z'):
    case('Z'):
      c = (c == &c1)? &c2 : &c1;
    break;
    case('x'):
    case('X'):
      *c = (*c > 0)? *c - 1 : 8;
    break;
    case('.'):
    case('>'):
      sections++;
    break;
    case(','):
    case('<'):
      sections--;
    break;
    case('m'):
    case('M'):
      colormode = (colormode == 3)? 1 : colormode + 1;
    break;
    case('n'):
    case('N'):
      drawmode = (drawmode == 9)? 0 : drawmode + 1;
    break;
    case 27:	// Escape key
      exit(0);
    break;
  }
  glutPostRedisplay();
}

void instructions()
{
	cout << "Controls:" << endl;
	cout << "  use Z to switch between first and second color selections." << endl;
	cout << "  use X to iterate through colors." << endl;
	cout << "  use AWSD to move rotation vector." << endl;
	cout << "  use < > to increese or decreese the number of slices on sphere." << endl;
	cout << "  use M to iterate through coloring modes." << endl;
	cout << "  use N to iterate through drawing modes." << endl;
	cout << "  use Spacebar to toggle animation." << endl;
}
