#ifndef _DRAWMGR_H
#define _DRAWMGR_H

#include <SDL2/SDL.h>

class DrawMgr
{
public:
	void CreateWindow();
	void DrawBackground(int,int);
	void Quit();


private:

	SDL_Window* window;
	SDL_Surface* screenSurface;
};

/*The global object */
extern DrawMgr gDrawMgr;

#endif
