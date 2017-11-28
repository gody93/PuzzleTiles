#ifndef _DRAWMGR_H
#define _DRAWMGR_H

#include "include/SDL.h"
#include <iostream>
#include <fstream>
#include "Board.h"
#include "Tile.h"


class DrawMgr
{
public:
	static DrawMgr* getMgr();
	~DrawMgr();
	bool CreateWindow();
	bool LoadMedia();
	void DrawScreenBackground();
	void DrawBoard();
	void DrawTile(Tile*,SDL_Surface*);
	void UpdateScreen();
	void LoadTileResources();
	void DrawEndSplash();
	std::string GetTileResource(int);

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
	SDL_Surface* endSplash;

	std::vector<std::string>resources;

};

#endif
