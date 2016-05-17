/*
 * 
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP 1

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#include "object.hpp"

class light: public object
{
  private:
    GLenum number, model;
  public:
	// construct
    light(GLenum num, GLenum mod)
    {
		// initialize 
		number = num;
		model = mod;
		for (int i = 0; i < 4; i++)
		{
			position[i] = 2.0;
			color[i] = 0.0;
		}
	}
	// distruct
    ~light()
    {
		glDisable(number);
	}

	// Use the lighting (affect the scene)
	void affect(bool show = true)
	{
		glPushMatrix();
		if (show)
		{
			glTranslatef(position[0], position[1], position[2]);
			glColor4f(1.0, 1.0, 1.0, 1.0); 
			glutWireSphere(0.05, 8, 8);
		}
		glPopMatrix();
		glLightfv(number, GL_POSITION, position);
		glLightfv(number, model, color); // set properties
		glEnable(number); // enable this light
	}
};
  
#endif
