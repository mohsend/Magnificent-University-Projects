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
    GLfloat properties[4];
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
			position[i] = 0.0;
			properties[i] = 0.5;
		}
		
		glLightfv(num, model, properties); // set properties
		glEnable(num); // enable this light
	}
	// distruct
    ~light()
    {
		glDisable(number);
	}
	// Set properties
	void setProperties(GLfloat p1, GLfloat p2, GLfloat p3, GLfloat p4)
	{
		properties[0] = p1;
		properties[1] = p2;
		properties[2] = p3;
		properties[3] = p4;
	}

	// Use the lighting (affect the scene)
	void affect(bool show = true)
	{
		glPushMatrix();
		glLightfv(number, GL_POSITION, position);
		if (show)
		{
			glTranslatef(position[0], position[1], position[2]);
			glColor3f(0.0, 1.0, 0.0); 
			glutWireSphere(0.05, 8, 8);
		}
		glPopMatrix();
	}
};
  
#endif
