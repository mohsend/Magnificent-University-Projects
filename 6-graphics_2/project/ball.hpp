/*
 * 
 */

#ifndef FLOOR_HPP
#define FLOOR_HPP 1

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#include "object.hpp"

class ball: public object
{
  private:
    GLdouble radius;
    GLfloat color[4];
  public:
    ball(GLdouble r = 1.0)
    {
		for (int i = 0; i < 4; i++)
		{
			position[i] = 0.0;
			color[i] = 1.0;
		}
		radius = r;
	}
    ~ball() {}
    void draw()
    {
		// Sphere.
		glColor4fv(color);
		glTranslatef(position[0], position[1], position[2]); // Move the sphere.
		glutSolidSphere(radius, 30, 30);
	}
};

#endif
