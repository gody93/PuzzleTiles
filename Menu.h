#ifndef MENU_H
#define MENU_H

#include "SDL2/SDL.h"
#include <vector>
#include "DrawMgr.h"

class Menu
{

public:
    static Menu* getMenu();
	~Menu();

    SDL_Surface* getSurface();
    void showButtons();

private:
	Menu();
    static Menu* menu;
    SDL_Surface* menuBackground;

    std::vector<Button*> buttons;
};

#endif
