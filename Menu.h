#ifndef MENU_H
#define MENU_H

#include "SDL2/SDL.h"
#include "DrawMgr.h"

class Menu
{

public:
    static Menu* getMenu();
	~Menu();

    SDL_Surface* getSurface();

private:
	Menu();
    static Menu* menu;
    SDL_Surface* menuBackground;
};

#endif
