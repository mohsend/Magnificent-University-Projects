/*
 * 
 */

#include "common.hpp"

// Routine to output interaction instructions on the terminal
void printInteraction(char what)
{
	if (what == 'o')
	{
		cout << "Interaction:" << endl;
		cout << "use A & Q keys to change Red color value." << endl;
		cout << "use S & W keys to change Green color value." << endl;
		cout << "use D & E keys to change Blue color value." << endl;
		cout << "-----------------" << endl;
		cout << "use Y & H keys to move parallel to X axis." << endl;
		cout << "use J & U keys to move parallel to X axis." << endl;
		cout << "use K & I keys to move parallel to X axis." << endl;
		cout << "=================" << endl;
	}
	else
	{
		cout << "Interaction:" << endl;
		cout << "Right click on the window to select an object to modify." << endl;
		cout << "=================" << endl;
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
      // Red
	  case 'a':
	  case 'A':
		 current->changeColor(Red, -0.1);
		 break;
	  case 'q':
	  case 'Q':
 		 current->changeColor(Red, +0.1);
		 break;
	  // Green
	  case 's':
	  case 'S':
		 current->changeColor(Green, -0.1);
		 break;
	  case 'w':
	  case 'W':
 		 current->changeColor(Green, +0.1);
		 break;
	  // Blue
	  case 'd':
	  case 'D':
		 current->changeColor(Blue, -0.1);
		 break;
	  case 'e':
	  case 'E':
 		 current->changeColor(Blue, +0.1);
		 break;
	  // X
	  case 'h':
	  case 'H':
		 current->moveX(-0.1);
		 break;
	  case 'Y':
	  case 'y':
 		 current->moveX(+0.1);
         break;
      // Y
	  case 'j':
	  case 'J':
		 current->moveY(-0.1);
		 break;
	  case 'u':
	  case 'U':
 		 current->moveY(+0.1);
		 break;
	  // Z
	  case 'k':
	  case 'K':
		 current->moveZ(-0.1);
		 break;
	  case 'i':
	  case 'I':
 		 current->moveZ(+0.1);
         break;
   }
   glutPostRedisplay();
}

void createMenu(void)
{     

    glutAddMenuEntry("Modify Camera", 1);   
    glutAddMenuEntry("Modify Ball", 2); 
    glutAddMenuEntry("Modify Light 01", 3);  
    glutAddMenuEntry("Modify Light 02", 4); 
    glutAddMenuEntry("Quit", 0);    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 

void menu (int sel)
{
	switch (sel)
	{
		case 0:
			exit(0);
		break;
		case 1:
			current = &cam;
		break;
		case 2:
			current = &ball01;
			printInteraction('o');
		break;
		case 3:
			current = &light01;
			printInteraction('o');
		break;
		case 4:
			current = &light02;
			printInteraction('o');
		break;
		default:
			current = &light01;
			printInteraction('o');
		break;
	}
}

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{  
   char *c;

   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

