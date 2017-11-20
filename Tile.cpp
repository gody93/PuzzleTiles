#include "Tile.h"

Tile::Tile() : m_nTileWidth(60), m_nTileHeight(60), offset(5), m_tile(NULL), x(0), y(0)
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
	this->currPos += offset;
}

void Tile::moveUp()
{
	this->currPos -= offset;
}

void Tile::moveRight()
{
	this->currPos++;
}

void Tile::moveLeft()
{
	this->currPos--;
}

SDL_Rect& Tile::getPos()
{
	switch(currPos)
	{
	case 0:
		tilePos.x = 0;
		tilePos.y = 0;
		break;
	case 1:
		tilePos.x = 65;
		tilePos.y = 0;
		break;
	case 2:
		tilePos.x = 130;
		tilePos.y = 0;
		break;
	case 3:
		tilePos.x = 195;
		tilePos.y = 0;
		break;
	case 4:
		tilePos.x = 260;
		tilePos.y = 0;
		break;
	case 5:
		tilePos.x = 0;
		tilePos.y = m_nTileHeight + offset;
		break;
	case 6:
		tilePos.x = 65;
		tilePos.y = 65;
		break;
	case 7:
		tilePos.x = 130;
		tilePos.y = 65;
		break;
	case 8:
		tilePos.x = 195;
		tilePos.y = 65;
		break;
	case 9:
		tilePos.x = 260;
		tilePos.y = 65;
		break;
	case 10:
		tilePos.x = 0;
		tilePos.y = 130;
		break;
	case 11:
		tilePos.x = 65;
		tilePos.y = 130;
		break;
	case 12:
		tilePos.x = 130;
		tilePos.y = 130;
		break;
	case 13:
		tilePos.x = 195;
		tilePos.y = 130;
		break;
	case 14:
		tilePos.x = 260;
		tilePos.y = 130;
		break;
	default:break;
	}
	return tilePos;
}

void Tile::setPos(int , int)
{
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

void Tile::setInitialPos(int pos)
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
