/*
 * Setup OpenGL and window resize routine
 */

#include "common.hpp"

// Initialization routine.
void setup()
{
   current = &light01;
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST); // Enable depth testing.
   glEnable(GL_LIGHTING); // Turn on OpenGL lighting.

   GLfloat globAmb[] = { 0.2, 0.2, 0.2, 1.0 };
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint

   glEnable(GL_CULL_FACE); // Cull back faces.
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
