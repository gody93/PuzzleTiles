#ifndef _DRAWMGR_H
#define _DRAWMGR_H

#include <SDL2/SDL.h>
#include <iostream>
#include "Board.h"


class DrawMgr
{
public:
	static DrawMgr* getMgr();
	~DrawMgr();
	bool CreateWindow();
	bool loadMedia();

	SDL_Surface* getMarker();

	void DrawScreenBackground();
	void DrawBoard();
	void UpdateScreen();

	int getScreenWidth() { return nScreenWidth; }
	int getScreenHeight() { return nScreenHeight; }

private:
	DrawMgr();
	static DrawMgr* mgr;

	int nScreenWidth;
	int nScreenHeight;

	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Surface* screenBackground;
	SDL_Surface* boardBackground;
	SDL_Surface* tileMarker;

};

#endif
