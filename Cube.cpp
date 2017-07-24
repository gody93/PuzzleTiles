#include "Cube.h"

Cube::Cube() : m_nCubeWidth(20), m_nCubeHeight(20), m_nBoardWidth(100), m_nBoardHeight(100)
{
	boardPos.x = 200;
	boardPos.y = 200;
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

SDL_Surface* Cube::DrawCube()
{
	/* Creating the surface. */
	this->tile = SDL_CreateRGBSurface(0, m_nCubeHeight, m_nCubeWidth, 32, 0, 0, 0, 0);

	/* Filling the surface with red color. */
	SDL_FillRect(tile, NULL, SDL_MapRGB(tile->format, 255, 0, 0));

	return this->tile;
}

SDL_Surface* Cube::DrawBoard()
{
	this->boardBackground = SDL_CreateRGBSurface(0, m_nBoardHeight, m_nBoardWidth, 32, 0, 0, 0, 0);

	SDL_FillRect(boardBackground , NULL, SDL_MapRGB(boardBackground->format, 255, 255, 0));

	return this->boardBackground;
}


SDL_Rect Cube::getBoardPos()
{
	return boardPos;
}

void Cube::setBoardPos(int x, int y)
{
	boardPos.x += x;
	boardPos.y += y;
}
Cube* Cube::cube = NULL;
