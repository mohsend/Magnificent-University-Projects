/*
 * 
 */

#ifndef COMMON_HPP
#define COMMON_HPP 1

#include "object.hpp"
#include "light.hpp"
#include "ball.hpp"
#include "floor.hpp"
#include "camera.hpp"

#include <iostream>
using namespace std;

// main
void drawScene();
void animate();
enum color_t {Red = 0, Green = 1, Blue = 2, Alpha = 3};

extern object* current;

extern camera cam;
extern light light01;
extern light light02;
extern ball ball01;

// io
void printInteraction(char what);
void specialKeyInput(int key, int x, int y);
void keyInput(unsigned char key, int x, int y);
void floatToString(char * destStr, int precision, float val);
void createMenu();
void menu (int sel);

// setup
void setup();
void resize (int w, int h);

#endif
