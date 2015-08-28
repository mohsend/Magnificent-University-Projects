## Compiling
### GNU Compiler Collection
I tested every file using [GCC](https://github.com/mohsend/Magnificent-University-Projects/wiki/GNU-Compiler-Collection) on Ubuntu. any compiler should be fine.
Since these codes use `freeglut3` libraries you should first install them.  
On a Debian-based distro:  
```bash
$ sudo apt-get install freeglut3 freeglut3-dev
```
Then we should inform GCC to link our code to the libraries:  
```bash
$ g++ "code_file.cpp" -lGL -lGLU -lglut -Wall
```

### Microsoft Visual Studio .net
First of all install GLUT libraries for VS.net

Add this line on top of the code if you want to compile in Visual Studio .net:
```c++
#include "stdafx.h"
```
