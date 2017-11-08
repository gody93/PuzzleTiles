#include "Tile.h"

Tile::Tile() : m_nTileWidth(60), m_nTileHeight(60), offset(5), m_tile(NULL)
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

int Tile::getInitialPos() const
{
	return this->initialPos;
}

int Tile::getCurrPos() const
{
	return currPos;
}

bool Tile::isInCorrectPlace()
{
	return this->initialPos == this->currPos ? true : false;
}

void Tile::setCurrPos( int pos )
{
	this->currPos = pos;
}

void Tile::setColour( int red, int green, int blue )
{
	r = red;
	g = green;
	b = blue;
}

void Tile::setSurface( std::string path)
{
	std::string fullPath = "img/" + path;
	this->m_tile = SDL_LoadBMP( fullPath.c_str() );
	if( this->m_tile == NULL)
	{
		printf( "Unable to load image Tile - %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
}
