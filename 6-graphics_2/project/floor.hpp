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
    
  public:
    floor();
    ~floor();
};

#endif
