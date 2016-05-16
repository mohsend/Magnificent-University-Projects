/*
 * 
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP 1

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#include "object.hpp"

class camera: public object
{
  private:
    GLdouble angle;
  public:
    camera(GLdouble a)
    {
		for (int i = 0; i < 4; i++)
		{
			position[i] = 0.0;
		}
		angle = a;
	}
    ~camera()
    {
		
	}
    void look()
    {
		gluLookAt(0.0, 3.0, 5.0, 
		          position[0], position[1], position[2], 
		          0.0, 1.0, 0.0);
	}
};

#endif
