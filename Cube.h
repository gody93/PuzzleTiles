#ifndef CUBE_H
#define CUBE_H
#include "SDL2/SDL.h"
#include <iostream>

class Cube
{
public:
	Cube();
	~Cube();
	void Move();
	void OnTouch();
	void Draw( SDL_Renderer& );
	void Quit();
	int GetWidth() { return width; };
	int GetHeight() { return height; };

private:

	SDL_Texture* sdlTexture;
	SDL_Surface* cube;
	int width;
	int height;
};

extern Cube gCube;

#endif
