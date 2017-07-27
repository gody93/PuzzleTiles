#include "Tile.h"

Tile::Tile() : m_nTileWidth(45), m_nTileHeight(45), offset(5)
{

	isInside = false;
	isSelected = false;

	this->tilePos = Board::getBoard()->getBoardPos();
//	this->tilePos.y = 127;

	mousePos.x = tilePos.x;
	mousePos.y = tilePos.y;
}

Tile::~Tile()
{
	delete Tile::tile;
	Tile::tile = NULL;
}

Tile* Tile::getTile()
{
	if(!tile)
	{
		tile = new Tile();
	}
	return tile;
}

SDL_Surface* Tile::getTileSurface()
{
	/* Creating the surface. */
	this->tile = SDL_CreateRGBSurface(0, m_nTileHeight, m_nTileWidth, 32, 0, 0, 0, 0);

	/* Filling the surface with red color. */
	SDL_FillRect(this->tile, NULL, SDL_MapRGB(this->tile->format, 255, 0, 0));

	return this->tile;
}

void Tile::handleEvent(SDL_Event &e)
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

void Tile::moveDown()
{
	//tilePos.x += m_nTileHeight;

	if(checkCollision())
	{

		tilePos.y += m_nTileWidth + offset;

		std::cout << "Moves Down \n\n";
	}
	else
	{
		std::cout << "In Collision \n\n";
	}
}

SDL_Rect Tile::getTilePos()
{
	return this->tilePos;
}

bool Tile::checkCollision()
{
	// if( ( tilePos.y + m_nTileHeight) >= (boardPos.y + m_nBoardHeight) )
	// {
	// 	return false;
	// }
	// return true;
}

bool Tile::isInsideTile(int x, int y)
{
	isInside = false;

	if( ( x > mousePos.x && x < (mousePos.x + m_nTileWidth) )  &&
		( y > mousePos.y  && y < ( mousePos.y + m_nTileHeight) ) )
	{
		isInside = true;
	}

	return isInside;
}

Tile* Tile::tile = NULL;
