#ifndef _DRAWMGR_H
#define _DRAWMGR_H

#include <SDL2/SDL.h>
#include <iostream>
#include "Cube.h"

class DrawMgr
{
public:
	static DrawMgr* getMgr();
	~DrawMgr();
	bool CreateWindow();
	bool loadMedia();


	void DrawBackground();
	void DrawBoard(SDL_Surface*);
	void DrawTile(SDL_Surface*);
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

};

#endif
