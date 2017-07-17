#ifndef _DRAWMGR_H
#define _DRAWMGR_H

#include <SDL2/SDL.h>

class DrawMgr
{
public:
	static DrawMgr* getMgr();
	~DrawMgr();
	bool CreateWindow();


// void DrawBackground();
	// void DrawCube();
	// void ClearScreen();
	// void UpdateScreen();
	// void Quit();


private:
	DrawMgr();
	static DrawMgr* mgr;

	int nScreenWidth;
	int nScreenHeight;

	SDL_Window* window;
	SDL_Renderer* renderer;

	// SDL_Surface* screenBackground;
	// SDL_Texture* backgroundTexture;
};

#endif
