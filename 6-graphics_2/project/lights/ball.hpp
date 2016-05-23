/*
 * A class repesenting a sphere (ball) object.
 * Inherits from object
 */

#ifndef BALL_HPP
#define BALL_HPP 1

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
  public:
    ball(GLdouble r = 1.0)
    {
		for (int i = 0; i < 4; i++)
		{
			position[i] = 0.0;
			color[i] = 0.6;
		}
		radius = r;
    }
    
    ~ball() {}
    
    void draw()
    {
    	static float a = 1.0; // Blue ambient reflectance.
    	static float d = 1.0; // Blue diffuse reflectance.
    	static float h = 10.0; // Shininess.
    	static float e = 0.1; // Red emittance.
    	static float t = 0.0; // Quadratic attenuation factor.
    	float matAmb[] = {0.0, 0.0, a, 1.0};
    	float matDif[] = {0.0, 0.0, d, 1.0};
    	float matShine[] = { h };
    	float matEmission[] = {e, 0.0, e, 1.0};

    	// Material properties of sphere.
    	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
    	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
    	glMaterialfv(GL_FRONT, GL_SHININESS, matShine);
    	glMaterialfv(GL_FRONT, GL_EMISSION, matEmission);
    	
    	// Sphere
    	glTranslatef(position[0], position[1], position[2]); // Move the sphere.
    	glutSolidSphere(radius, 30, 30);
    	glLoadIdentity();
    }
};

#endif
