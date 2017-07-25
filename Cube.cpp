#include "Cube.h"

Cube::Cube() : m_nCubeWidth(45), m_nCubeHeight(45), m_nBoardWidth(245), m_nBoardHeight(245), offset(5)
{
	boardPos.x = (DrawMgr::getMgr()->getScreenWidth() - m_nBoardWidth ) / 2;
	boardPos.y = (DrawMgr::getMgr()->getScreenHeight() - m_nBoardHeight) / 2;

	this->tilePos.x = this->boardPos.x;
	this->tilePos.y = this->boardPos.y;
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

void Cube::handleEvent(SDL_Event &e)
{
	if( e.type == SDL_KEYDOWN && e.key.repeat ==0)
	{
		switch( e.key.keysym.sym)
		{
		case SDLK_UP:
			moveDown();
			break;
		default:
			break;
		}
	}
}

void Cube::moveDown()
{
	//tilePos.x += m_nCubeHeight;

	if(checkCollision())
	{

		tilePos.y += m_nCubeWidth + offset;

		std::cout << "Moves Down \n\n";
	}
	else
	{
		std::cout << "In Collision \n\n";
	}
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

SDL_Rect Cube::getTilePos()
{
	return this->tilePos;
}

bool Cube::checkCollision()
{
	if( ( tilePos.y + m_nCubeHeight) >= (boardPos.y + m_nBoardHeight) )
	{
		return false;
	}
	return true;
}

Cube* Cube::cube = NULL;
