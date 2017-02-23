#ifndef _DRAWMGR_H
#define _DRAWMGR_H

#include <SDL2/SDL.h>
#include "Cube.h"

class DrawMgr
{
public:
	DrawMgr();
	~DrawMgr();
	bool CreateWindow();
	void DrawBackground();
	void DrawCube();
	void ClearScreen();
	void UpdateScreen();
	void Quit();


private:
	int nScreenWidth;
	int nScreenHeight;

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* screenBackground;
	SDL_Texture* backgroundTexture;
};

/*The global object */
extern DrawMgr gDrawMgr;

#endif
