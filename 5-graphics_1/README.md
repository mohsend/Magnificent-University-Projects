# Computer Graphics I


## Compiling

### Install OpenGL

Follow [this comperhensive guide](http://www.prinmath.com/csci5229/misc/install.html) on how to install and use OpenGL on all major platforms (Linux, OS X, Windows) by Willem A. (Vlakkies) Schreüder from University of Colorado at Boulder.

#### Quick use guide

##### FreeGLUT install

Since these codes use 'freeglut3' libraries you should first install them. We also use `gcc` to compile so we should install it too.

###### Linux

APT (Ubuntu and Debian based Distros):  

```bash
$ sudo apt-get install freeglut3 freeglut3-dev gcc
```

YUM (RedHat based Distros):  

```bash
$ sudo yum install freeglut-devel gcc
```

DNF (Fedora):

```bash
$ sudo dnf install freeglut-devel gcc
```

###### OS X

Congratulations! It comes pre-installed on OS X.

##### Compile and link to FreeGLUT

Then we should instruct `gcc` to link our code to the libraries:  

###### Linux

```bash
$ gcc "code_file.cpp" -lGL -lGLU -lglut -Wall
```

###### OS X

```bash
$ gcc "code_file.cpp" -framework GLUT -framework OpenGL
```
###### Windows

Follow [this guide](https://www3.ntu.edu.sg/home/ehchua/programming/opengl/HowTo_OpenGL_C.html) to install and use `gcc` and 'freeglut' on `Cygwin` or `MinGW` on windows or compile using 'Visual C++'. 

### Microsoft Visual Studio .net

First of all [install freeGLUT3 libraries](http://freeglut.sourceforge.net/) for VS.net

Add this line on top of the code if you want to compile in Visual Studio.net:

```c++
#include "stdafx.h"
```
