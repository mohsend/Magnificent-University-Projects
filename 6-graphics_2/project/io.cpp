/*
 * Includes IO functions:
 * Prints instructions.
 * Handles keyboard key presses.
 * Makes a rightclick menu.
 */

#include "common.hpp"

// Routine to output interaction instructions on the terminal
void printInteraction(char what)
{
	cout << "Interaction help:" << endl;
	// Light colors
	if (what & 0x01)
	{
		cout << "Color Change controls:" << endl;
		cout << "  use \033[31mA & Q\033[0m keys to change Red color value." << endl;
		cout << "  use \033[32mS & W\033[0m keys to change Green color value." << endl;
		cout << "  use \033[34mD & E\033[0m keys to change Blue color value." << endl;
	}
	// Move Objects (inc. lights)
	if (what & 0x02)
	{
		cout << "Movement controls:" << endl;
		cout << "  use Y & H keys to move parallel to X axis." << endl;
		cout << "  use J & U keys to move parallel to Y axis." << endl;
		cout << "  use K & I keys to move parallel to Z axis." << endl;
	}
	// Camera
	if (what & 0x04)
	{
		cout << "Camera Tumble controls:" << endl;
		cout << "  use Y & H keys to move camera parallel to X axis." << endl;
		cout << "  use J & U keys to move camera parallel to Y axis." << endl;
		cout << "  use K & I keys to move camera parallel to Z axis." << endl;
		cout << "Camera Pan controls:" << endl;
		cout << "  use A & Q keys to move center of veiw parallel to X axis." << endl;
		cout << "  use S & W keys to move center of veiw parallel to Y axis." << endl;
		cout << "  use D & E keys to move center of veiw parallel to Z axis." << endl;
	}
	// On startup
	if (what & 0x80)
	{
		cout << "Right click on the window to select an object to modify." << endl;
	}
	cout << "///////////////////////////////" << endl;
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
   if (key == GLUT_KEY_UP) ;
   if (key == GLUT_KEY_DOWN) ;
   glutPostRedisplay();
}

// Gets called when user presses a keyboard key
void keyInput(unsigned char key, int x, int y)
{
   switch (key)
   {
    case 27: // Quit
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

// Creates a rightclick menu so select objects to modify
void createMenu(void)
{

    glutAddMenuEntry("Modify Camera", 1);
    glutAddMenuEntry("Modify Ball", 2);
    glutAddMenuEntry("Modify Deffuse Light", 3);
    glutAddMenuEntry("Modify Ambeint Light", 4);
		glutAddMenuEntry("Toggle Animation", 5);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Gets called when user clicks on a rightclick menu
void menu (int sel)
{
	switch (sel)
	{
		case 0: // Quit
			exit(0);
		break;
		case 1: // Modify Camera
			current = &cam;
			printInteraction(0x04);
		break;
		case 2: // Modify Ball
			current = &ball01;
			printInteraction(0x02);
		break;
		case 3: // Modify Deffuse Light
			current = &light01;
			printInteraction(0x03);
		break;
		case 4: // Modify Ambeint Light
			current = &light02;
			printInteraction(0x01);
		break;
		case 5: // Toggle Animation
			doAnimate = !doAnimate;
		break;
		default:
			current = &light01;
			printInteraction(0x03);
		break;
	}
}

// Draws a bitmap character string.
void writeBitmapString(void *font, char *string)
{
   char *c;
   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}
