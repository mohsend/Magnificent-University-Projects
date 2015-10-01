## Compiling
### Install OpenGL
Follow [this comperhensive guide](http://www.prinmath.com/csci5229/misc/install.html) on how to install and use OpenGL on all major platforms (Linux, OS X, Windows) by Willem A. (Vlakkies) Schreüder from University of Colorado at Boulder.
#### Quick use guide
##### FreeGLUT install
Since these codes use `freeglut3` libraries you should first install them. 
###### Linux 
APT (Ubuntu and Debian based Distros):  

```bash
$ sudo apt-get install freeglut3 freeglut3-dev
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

##### FreeGLUT link
Then we should inform GCC to link our code to the libraries:  
###### Linux

```bash
$ gcc "code_file.cpp" -lGL -lGLU -lglut -Wall
```

###### OS X

```bash
$ gcc "code_file.cpp" -framework GLUT -framework OpenGL
```

### GNU Compiler Collection
I tested every file using [GCC](https://github.com/mohsend/Magnificent-University-Projects/wiki/GNU-Compiler-Collection) on Ubuntu. any compiler should be fine.

### Microsoft Visual Studio .net
First of all install GLUT libraries for VS.net

Add this line on top of the code if you want to compile in Visual Studio .net:

```c++
#include "stdafx.h"
```
