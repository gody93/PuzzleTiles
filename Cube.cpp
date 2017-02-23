#include "Cube.h"

Cube::Cube() : width(20), height(20), cube(NULL)
{
}

Cube::~Cube()
{

}

void Cube::Move()
{

}
void Cube::Draw(SDL_Renderer& renderer )
{

	cube = SDL_CreateRGBSurface(0, 20, 20, 32, 0, 0, 0, 0);

	SDL_FillRect(cube, NULL, SDL_MapRGB(cube->format, 0, 0, 0) );

	if(cube == NULL)
	{
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
	}

	sdlTexture = SDL_CreateTextureFromSurface(&renderer, cube);

	SDL_UpdateTexture(sdlTexture, NULL, 0, 0);

	SDL_FreeSurface(cube);

	SDL_RenderCopy(&renderer,sdlTexture, NULL, NULL);
}

void Cube::Quit()
{

}

Cube gCube;
