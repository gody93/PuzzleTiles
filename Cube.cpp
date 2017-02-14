#include "Cube.h"

Cube::Cube() : width(20), height(20), cube(NULL)
{
	cube = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
}

Cube::~Cube()
{
}

void Cube::Move()
{

}

SDL_Surface* Cube::DrawBackground()
{
	SDL_FillRect(cube, NULL,SDL_MapRGB( cube->format, 0, 0, 0 ) );
}

void Cube::Draw( SDL_Surface destination& )
{
	SDL_Rect offset;
	offset.x = 20;
	offset.y = 20;

	SDL_FillRect(cube, NULL, SDL_MapRGB( cube->format, 0, 0, 0 ) );

	SDL_BlitSurface( cube, NULL, destination, &offset);
}


Cube gCube;
