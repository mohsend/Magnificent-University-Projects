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
   if (key == GLUT_KEY_UP) ;
   if (key == GLUT_KEY_DOWN) ;
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
	  case 'A':
		 break;
	  case 'q':
	  case 'Q':
 		 
		 break;
      default:
         break;
      glutPostRedisplay();
   }
}

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{  
   char *c;

   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

#endif
