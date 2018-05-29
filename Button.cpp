#ifndef BUTTON_H
#define BUTTON_H
#include "Button.h"

Button::Button() : background(NULL)
                 , m_nButtonWidth(25)
                 , m_nButtonHeight(50)
{

}

Button::~Button()
{

}

SDL_Surface* Button::getSurface()
{
    this->background = SDL_CreateRGBSurface( 0, m_nButtonWidth, m_nButtonHeight, 32, 0, 0, 0, 0);

    SDL_FillRect(background, NULL, SDL_MapRGB(background->format, 230, 50, 10));

    return this->background;
}

#endif
