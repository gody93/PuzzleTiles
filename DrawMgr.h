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

	void DrawBackground();
	void DrawBoard();
	void UpdateScreen();

	int getScreenWidth() { return nScreenWidth; }
	int getScreenHeight() { return nScreenHeight; }

private:
	DrawMgr();
	static DrawMgr* mgr;

	int nScreenWidth;
	int nScreenHeight;

	SDL_Window* window = NULL;
	SDL_Surface* screenBackground = NULL;
	SDL_Surface* background = NULL;
	SDL_Surface* tileMarker = NULL;

};

#endif
