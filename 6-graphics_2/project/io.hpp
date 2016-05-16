/*
 * 
 */

#ifndef IO_HPP
#define IO_HPP 1

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

void printInteraction(char what);
void specialKeyInput(int key, int x, int y);
void keyInput(unsigned char key, int x, int y);
void floatToString(char * destStr, int precision, float val);

// Routine to output interaction instructions on the terminal
void printInteraction(char what)
{
	if (what == 'l')
	{
		
	}
	else
	{
		cout << "Interaction:" << endl;
		cout << "" << endl;
	}
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
   if (key == GLUT_KEY_UP) zMove -= 0.1;
   if (key == GLUT_KEY_DOWN) if (zMove < 3.0) zMove += 0.1;
   glutPostRedisplay();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
   switch (key) 
   {
      case 27:
         exit(0);
         break;
	  case 'a':
 		 if (a > 0.0) a -= 0.05);
		 break;
	  case 'A':
 		 if (a < 1.0) a += 0.05;
		 break;
      default:
         break;
      glutPostRedisplay();
   }
}

// Routine to convert floating point to char string.
void floatToString(char * destStr, int precision, float val) 
{
   sprintf(destStr,"%f",val);
   destStr[precision] = '\0';
}

#endif
