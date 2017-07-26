#include "Cube.h"

Cube::Cube() : m_nCubeWidth(45), m_nCubeHeight(45), offset(5)
{

	isInside = false;
	isSelected = false;

	this->tilePos = Board::getBoard()->getBoardPos();
//	this->tilePos.y = 127;

	mousePos.x = tilePos.x;
	mousePos.y = tilePos.y;
}

Cube::~Cube()
{
	delete Cube::cube;
	Cube::cube = NULL;
}

Cube* Cube::getTile()
{
	if(!cube)
	{
		cube = new Cube();
	}
	return cube;
}

SDL_Surface* Cube::getTileSurface()
{
	/* Creating the surface. */
	this->tile = SDL_CreateRGBSurface(0, m_nCubeHeight, m_nCubeWidth, 32, 0, 0, 0, 0);

	/* Filling the surface with red color. */
	SDL_FillRect(this->tile, NULL, SDL_MapRGB(this->tile->format, 255, 0, 0));

	return this->tile;
}

void Cube::handleEvent(SDL_Event &e)
{
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0)
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
	else if( e.type == SDL_MOUSEBUTTONUP)
	{
		int x,y;
		SDL_GetMouseState(&x, &y);
		//Mouse is right of the button
		if( isInsideTile(x,y) )
		{
			isSelected = true;
			std::cout << "Yay\n\n";
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

SDL_Rect Cube::getTilePos()
{
	return this->tilePos;
}

bool Cube::checkCollision()
{
	// if( ( tilePos.y + m_nCubeHeight) >= (boardPos.y + m_nBoardHeight) )
	// {
	// 	return false;
	// }
	// return true;
}

bool Cube::isInsideTile(int x, int y)
{
	isInside = false;

	if( ( x > mousePos.x && x < (mousePos.x + m_nCubeWidth) )  &&
		( y > mousePos.y  && y < ( mousePos.y + m_nCubeHeight) ) )
	{
		isInside = true;
	}

	return isInside;
}

Cube* Cube::cube = NULL;
