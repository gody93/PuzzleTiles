#ifndef CUBE_H
#define CUBE_H
#include "SDL/SDL.h"
#include <iostream>

class Cube
{
public:
	Cube();
	~Cube();
	void Move();
	void OnTouch();
	void Draw( SDL_Surface& );
	SDL_Surface* DrawBackground();
	int GetWidth() { return width; };
	int GetHeight() { return height; };

private:

	SDL_Surface* cube;
	int width;
	int height;
};

extern Cube gCube;

#endif
