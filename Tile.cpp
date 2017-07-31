#include "Tile.h"

Tile::Tile() : m_nTileWidth(45), m_nTileHeight(45), offset(5)
{

	isInside = false;
	isSelected = false;

	//this->tilePos = Board::getBoard()->getPos();

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

SDL_Surface* Tile::getSurface()
{
	/* Creating the surface. */
	this->m_tile = SDL_CreateRGBSurface(0, m_nTileHeight, m_nTileWidth, 32, 0, 0, 0, 0);
	/* Filling the surface with red color. */
	SDL_FillRect(this->m_tile, NULL, SDL_MapRGB(this->m_tile->format, 31, 40, 7));

	if(isSelected)
	{
		SDL_BlitScaled(DrawMgr::getMgr()->getMarker(), NULL, m_tile, NULL);
	}

	return this->m_tile;
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

SDL_Rect* Tile::getPos()
{
	return &tilePos;
}

void Tile::setPos(int x, int y)
{
	tilePos.x = x;
	tilePos.y = y;
}

bool Tile::checkCollision()
{
	if( ( tilePos.y + m_nTileHeight) >= (Board::getBoard()->getPos()->y + Board::getBoard()->getHeight()) )
	{
		return false;
	}
	return true;
}

bool Tile::isInsideTile(int x, int y)
{
	isInside = false;
	isSelected = false;

	if( ( x > mousePos.x && x < (mousePos.x + m_nTileWidth) )  &&
		( y > mousePos.y  && y < ( mousePos.y + m_nTileHeight) ) )
	{
		isInside = true;
		isSelected = true;
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

Tile* Tile::tile = NULL;
