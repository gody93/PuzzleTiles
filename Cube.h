#ifndef CUBE_H
#define CUBE_H

#include <SDL2/SDL.h>

class Cube
{
public:
	Cube();
	~Cube();

	virtual SDL_Surface* getSurface() { return 0; }


private:


};

#endif
