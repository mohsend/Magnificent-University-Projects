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
    GLfloat color[4];
  public:
    // Set position
	void setPosition(GLfloat p1, GLfloat p2, GLfloat p3, GLfloat p4)
	{
		position[0] = p1;
		position[1] = p2;
		position[2] = p3;
		position[3] = p4;
	}
	// Set color
	void setColor(GLfloat p1, GLfloat p2, GLfloat p3, GLfloat p4)
	{
		color[0] = p1;
		color[1] = p2;
		color[2] = p3;
		color[3] = p4;
	}
	//Change color
	void changeColor(int c, GLfloat by) { color[c] += by; }
	// Move
	void moveX(GLfloat by) { position[0] += by;	}
	void moveY(GLfloat by) { position[1] += by;	}
	void moveZ(GLfloat by) { position[2] += by;	}
};

#endif
