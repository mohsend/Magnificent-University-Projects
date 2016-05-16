/*
 * 
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP 1

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

class object
{
  protected:
    GLfloat position[4];
  public:
    object();
    ~object();
    // Set position
	void setPosition(GLfloat p1, GLfloat p2, GLfloat p3, GLfloat p4)
	{
		position[0] = p1;
		position[1] = p2;
		position[2] = p3;
		position[3] = p4;
	}
	// Moving
	void moveX(GLfloat by) { position[0] += by;	}
	void moveY(GLfloat by) { position[1] += by;	}
	void moveZ(GLfloat by) { position[2] += by;	}
};

#endif
