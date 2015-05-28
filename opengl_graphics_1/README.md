## Compiling
### GNU Compiler Collection
I tested every file using [GCC](https://github.com/mohsend/cpp-examples/wiki/GNU-Compiler-Collection) on Ubuntu. any compiler should be fine.

To [compile in *nix](https://github.com/mohsend/cpp-examples/wiki/Compiling-using-GCC) (Linux, OS X, freeBSD,...) using GCC run this command in terminal:
```bash
g++ -Wall -o "executable_file" "code_file.cpp" -lGL -lGLU -lglut
```

### Microsoft Visual Studio .net
First of all install GLUT libraries for VS.net

Add this line on top of the code if you want to compile in Visual Studio .net:
```c++
#include "stdafx.h"
```
