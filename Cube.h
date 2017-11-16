#ifndef CUBE_H
#define CUBE_H

#include "include/SDL.h"

class Cube
{
public:
	Cube();
	~Cube();

	virtual SDL_Surface* getSurface() = 0;
	virtual SDL_Rect& getPos() = 0;
	virtual void setPos(int, int) = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;

private:


};

#endif
