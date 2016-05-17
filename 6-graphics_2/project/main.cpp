/*
 * Project design:
 * A dark background.
 * One or two movable light sources.
 * One movable camera.
 * One checkered plane (the floor).
 * One sphere (a ball preferably bouncing on the floor).
 */
 
 #include "common.hpp"
 
object* current;

camera cam(1.0);
light light01(GL_LIGHT1, GL_DIFFUSE);
light light02(GL_LIGHT2, GL_AMBIENT);
ball ball01(1.0);

// Main routine.
int main(int argc, char **argv) 
{
   printInteraction('r');
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
   //glutIdleFunc(animate);
   glutMainLoop();
   
   return 0;
}

void drawScene()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	cam.look();

	light01.affect();
	light02.setPosition(1.0, 1.0, 1.0, 1.0);
	light02.affect();
	ball01.draw();

	glutSwapBuffers();
}

void animate()
{
	light01.moveY(0.001);
	light01.moveX(-0.002);
	light01.changeColor(Green, 0.001);
	glutPostRedisplay();
}
