#include "Tile.h"

Tile::Tile() : m_nTileWidth(45), m_nTileHeight(45), offset(5)
{
	isInside = false;
}

Tile::~Tile()
{
	SDL_FreeSurface(m_tile);
	m_tile = NULL;
}

SDL_Surface* Tile::getSurface()
{
	/* Creating the surface. */
	this->m_tile = SDL_CreateRGBSurface(0, m_nTileHeight, m_nTileWidth, 32, 0, 0, 0, 0);
	/* Filling the surface with red color. */
	SDL_FillRect(this->m_tile, NULL, SDL_MapRGB(this->m_tile->format, 31, 40, 7));

	return this->m_tile;
}


void Tile::moveDown()
{
	this->tilePos.y += m_nTileHeight + offset;
}

void Tile::moveUp()
{
	this->tilePos.y -= m_nTileHeight + offset;
}

void Tile::moveRight()
{
	this->tilePos.x += m_nTileWidth + offset;
}

void Tile::moveLeft()
{
	this->tilePos.x -= m_nTileWidth + offset;
}

SDL_Rect& Tile::getPos()
{
	return tilePos;
}

void Tile::setPos(int x, int y)
{

	tilePos.x = x;
	tilePos.y = y;

}

void Tile::setMousePos(int x, int y)
{
	mousePos.x = x;
	mousePos.y = y;
}

bool Tile::checkCollision()
{
	// if( ( tilePos.y + m_nTileHeight) >= (Board::getBoard()->getPos().y + Board::getBoard()->getHeight()) )
	// {
	// 	return false;
	// }
	// return true;
}

bool Tile::isInsideTile(int x, int y)
{
	isInside = false;

	if( ( x > this->mousePos.x && x < (this->mousePos.x + m_nTileWidth) )  &&
		( y > this->mousePos.y  && y < ( this->mousePos.y + m_nTileHeight) ) )
	{
		isInside = true;
	}

	return isInside;
}

int Tile::getWidth() const
{
	return m_nTileWidth;
}

int Tile::getHeight() const
{
	return m_nTileHeight;
}

void Tile::setInitalPos(int pos)
{
	this->initialPos = pos;
	this->currPos = this->initialPos;
}

int Tile::getCurrPos()
{
	return currPos;
}

void Tile::setCurrPos( int pos )
{
	currPos = pos;
}
