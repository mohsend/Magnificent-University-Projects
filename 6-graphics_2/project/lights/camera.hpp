/*
 * A camera class
 * Inherits from object
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
    // Constructor
    camera(GLdouble a)
    {
    	position[0] = 0.0;
    	position[1] = 3.0;
    	position[2] = 5.0;
    	color[0] = 0.0;
    	color[1] = 0.0;
    	color[2] = 0.0;
    	angle = a;
    }

    // Destructor
    ~camera() { }

    void look()
    {
    	// Pan and Tumble
    	gluLookAt(position[0], position[1], position[2], // Eye coordinates (Tumble)
    	          color[0], color[1], color[2], // Center coordinates (Pan)
    	          0.0, 1.0, 0.0); // Up vector
    }
};

#endif
