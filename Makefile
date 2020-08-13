WERROR?=-Werror
PKGS=sdl2
# TODO(#118): try to enable -Weverything and disable things that don't make sense
CFLAGS=-Wall -Wextra $(WERROR) -pedantic -I.
CXXFLAGS=$(CFLAGS) -std=c++17 -fno-exceptions -Wno-missing-braces -Wswitch-enum `pkg-config --cflags $(PKGS)`
CXXFLAGS_DEBUG=$(CXXFLAGS) -O0 -fno-builtin -ggdb
LIBS=`pkg-config --libs $(PKGS) ` -lm

.PHONY: all
all: temp.debug 

temp.debug: $(wildcard src/temp*.cpp) $(wildcard src/temp*.hpp) stb_image.o 
	$(CXX) $(CXXFLAGS_DEBUG) -o temp.debug src/temp.cpp stb_image.o $(LIBS)

stb_image.o: src/stb_image.h
	$(CC) $(CFLAGS) -x c -ggdb -DSTBI_ONLY_PNG -DSTB_IMAGE_IMPLEMENTATION -c -o stb_image.o src/stb_image.h

