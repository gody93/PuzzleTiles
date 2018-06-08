#include "Menu.h"

Menu::Menu() : menuBackground(NULL)
             , buttons(2)
{
    for( auto button : buttons)
    {
        button = new Button();
    }
}

Menu::~Menu()
{
    delete Menu::menu;
    Menu::menu = NULL;

    SDL_FreeSurface(menuBackground);
}

Menu* Menu::getMenu()
{
    if(!menu)
    {
        menu = new Menu();
    }

    return menu;
}

SDL_Surface* Menu::getSurface()
{
    //menuBackground = SDL_LoadBMP( "img/menuBackground.bmp");

    menuBackground = SDL_CreateRGBSurface(0, DrawMgr::getMgr()->getScreenWidth(), DrawMgr::getMgr()->getScreenHeight(), 32, 0, 0, 0, 0);
    showButtons();
    SDL_FillRect(menuBackground, NULL, SDL_MapRGB(menuBackground->format, 250, 1, 30));
    return menuBackground;
}

void Menu::showButtons()
{
    for( auto button : buttons)
    {
        button->setPos(50, 50);
        DrawMgr::getMgr()->DrawButtons(button, menuBackground);
        std::cout << "Draw button";
    }
}

Menu* Menu::menu = NULL;
