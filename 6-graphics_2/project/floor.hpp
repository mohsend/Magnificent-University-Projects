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

class floor: public object
{
  private:
    GLubyte checkImage[8][8][4];
    GLdouble size;
  public:

    floor(GLdouble s)
    {
		// init size
		size = s;
		// init position
		for (int i = 0; i < 4; i++)
		{
			position[i] = 0.0;
			color[i] = 0.6;
		}
		position[0] = -2.0;
		// Construct checkered pattern
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
			 int static c = ((((i&0x8)==0)^((j&0x8))==0))*255;
			 checkImage[i][j][0] = (GLubyte) c;
			 checkImage[i][j][1] = (GLubyte) c;
			 checkImage[i][j][2] = (GLubyte) c;
			 checkImage[i][j][3] = (GLubyte) 255;
			}
		}
	}

    ~floor()
    {

	}

    void draw()
    {
		glColor4fv(color);
		glBegin(GL_POLYGON);
			glVertex3d(position[0] - size, position[1] - size, position[2]);
			glVertex3d(position[0] + size, position[1] - size, position[2]);
			glVertex3d(position[0] + size, position[1] + size, position[2]);
			glVertex3d(position[0] - size, position[1] + size, position[2]);
		glEnd();
    glLoadIdentity();
	}
};

#endif
