#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <SDL2/SDL.h>

#ifdef SOMETHING_RELEASE
#define STB_IMAGE_IMPLEMENTATION
#endif
#define STBI_ONLY_PNG
#include "./stb_image.h"


// READ THIS FIRST ---> https://en.wikipedia.org/wiki/Single_Compilation_Unit
#include "temp_game.cpp"
#include "temp_main.cpp"
