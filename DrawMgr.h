#ifndef _DRAWMGR_H
#define _DRAWMGR_H

#include <SDL2/SDL.h>
#include <iostream>

class DrawMgr
{
public:
	static DrawMgr* getMgr();
	~DrawMgr();
	bool CreateWindow();
	bool loadMedia();


	void DrawBackground();
	void DrawCube();
	// void ClearScreen();
	void UpdateScreen();
	// void Quit();


private:
	DrawMgr();
	static DrawMgr* mgr;

	int nScreenWidth;
	int nScreenHeight;

	SDL_Window* window = NULL;
	SDL_Surface* screenBackground = NULL;
	//The image we will load and show on the screen
	SDL_Surface* background = NULL;


//SDL_Renderer* renderer;


	// SDL_Texture* backgroundTexture;
};

#endif
