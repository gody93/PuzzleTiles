#include "Cube.h"

Cube::Cube() : m_nCubeWidth(20), m_nCubeHeight(20)
{

}

Cube::~Cube()
{
	delete Cube::cube;
	Cube::cube = NULL;
}

Cube* Cube::getCube()
{
	if(!cube)
	{
		cube = new Cube();
	}
	return cube;
}

void Cube::DrawCube()
{
	SDL_Surface* cube;

	/* Creating the surface. */
	cube = SDL_CreateRGBSurface(0, 50, 50, 32, 0, 0, 0, 0);

	/* Filling the surface with red color. */
	SDL_FillRect(cube, NULL, SDL_MapRGB(cube->format, 255, 0, 0));

	SDL_BlitSurface( cube, NULL, screenBackground, NULL);

}


Cube* Cube::cube = NULL;
