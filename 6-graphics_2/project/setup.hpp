/*
 * 
 */

#ifndef MAINHEADER_HPP
#define MAINHEADER_HPP 1

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

// Initialization routine.
void setup(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST); // Enable depth testing.

   // Turn on OpenGL lighting.
   glEnable(GL_LIGHTING);
   
   GLfloat globAmb[] = { 0.2, 0.2, 0.2, 1.0 };
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint

   // Cull back faces.
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);
}

// OpenGL window reshape routine.
void resize (int w, int h)
{
   glViewport (0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (float)w/(float)h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
}
#endif
