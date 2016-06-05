 /*
  * Header for main.cpp
  * Includes other Headers Globals and Function declearatios
  */

#ifndef MAIN_HPP
#define MAIN_HPP 1

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>

using namespace std;

void display();
void checkeredSphere(float, int);
void init();
void axis();
void animate();
extern void keyboard(unsigned char key, int a, int b);
extern void instructions();

extern int c1;
extern int c2;

extern double rx;
extern double ry;
extern double rz;
extern int degrees;

extern bool doAnimate;
extern int sections;
extern int colormode;
extern int drawmode;

// Colors
const GLfloat color[][3] = {
  {0.0, 0.0, 0.0},
  {0.0, 1.0, 0.0},
  {1.0, 1.0, 0.0},
  {1.0, 0.0, 0.0},
  {0.0, 0.0, 1.0},
  {0.0, 1.0, 1.0},
  {1.0, 1.0, 1.0},
  {1.0, 0.0, 1.0}
  };

#endif
