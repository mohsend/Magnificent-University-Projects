/*
 * Common header to extern variables
 * and define functions
 */

#ifndef COMMON_HPP
#define COMMON_HPP 1

#include "object.hpp"
#include "light.hpp"
#include "ball.hpp"
#include "camera.hpp"

#include <iostream>
#include <cmath>
using namespace std;

enum color_t {Red = 0, Green = 1, Blue = 2, Alpha = 3};

// main.cpp
void drawScene();
void animate();

extern object* current;
extern camera cam;
extern light light01;
extern light light02;
extern ball ball01;
extern bool doAnimate;

// io.cpp
void printInteraction(char what);
void specialKeyInput(int key, int x, int y);
void keyInput(unsigned char key, int x, int y);
void floatToString(char * destStr, int precision, float val);
void createMenu();
void menu (int sel);

// setup.cpp
void setup();
void resize (int w, int h);

#endif
