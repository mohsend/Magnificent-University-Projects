/*
 * Project design:
 * A dark background.
 * One movable diffuse light source.
 * One ambient light source.
 * One sphere (ball) to reflect lights.
 * One movable camera.
 */

 #include "common.hpp"

// Pointer to the object currently being modified.
object* current;

// Objects used in the scene
camera cam(0.0);
light light01(GL_LIGHT1, GL_DIFFUSE);
light light02(GL_LIGHT2, GL_AMBIENT);
ball ball01(1.0);
// If true, animate scene
bool doAnimate = false;


// Main
int main(int argc, char **argv)
{
   printInteraction(0x80);
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (50, 50);
   glutCreateWindow ("Graphics II Project");
   glutCreateMenu(menu);
   createMenu();
   setup();
   glutDisplayFunc(drawScene);
   glutReshapeFunc(resize);
   glutKeyboardFunc(keyInput);
   glutSpecialFunc(specialKeyInput);
   glutIdleFunc(animate);
   glutMainLoop();

   return 0;
}

// Draws the scene
void drawScene()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

  // Camera
	cam.look();
	// Lights
	light01.draw();
	light02.draw(false);
  // Object
  ball01.draw();
	glutSwapBuffers();
}

// Gets called on idle. Used for animation.
void animate()
{
  if (doAnimate)
  {
    // Action! :)
    static float degree = 0.0;
    degree += 0.01;
  	light01.setPosition(3.0 * sin(degree), 3.0 * cos(degree), 1.0 * cos (degree), 0.0);
  	glutPostRedisplay();
  }
}
