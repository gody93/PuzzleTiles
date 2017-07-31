#include "Board.h"

Board::Board() : m_nBoardWidth(245), m_nBoardHeight(245)
{
	boardPos.x = (DrawMgr::getMgr()->getScreenWidth() - m_nBoardWidth ) / 2;
	boardPos.y = (DrawMgr::getMgr()->getScreenHeight() - m_nBoardHeight) / 2;
}

Board::~Board()
{
	delete Board::board;
	Board::board = NULL;
}

Board* Board::getBoard()
{
	if(!board)
	{
		board = new Board();
	}

	return board;
}

SDL_Rect* Board::getPos()
{
	return &boardPos;
}

void Board::setPos(int x, int y)
{
	boardPos.x = x;
	boardPos.y = y;
}

SDL_Surface* Board::getSurface()
{
	this->boardBackground = SDL_CreateRGBSurface(0, m_nBoardHeight, m_nBoardWidth, 32, 0, 0, 0, 0);

	SDL_FillRect(boardBackground , NULL, SDL_MapRGB(boardBackground->format, 216, 120, 41));

	fillBoard();

	return this->boardBackground;
}

void Board::fillBoard()
{
	SDL_Rect* blitDest = getPos();

	for( int i = 0; i <= bRows; i++)
	{
		for( int j = 0; j <= bCols; j++)
		{
			SDL_BlitSurface(Tile::getTile()->getSurface(), NULL, boardBackground, blitDest);
			blitDest->x += Tile::getTile()->getWidth();
		}
		blitDest->y += Tile::getTile()->getHeight() + 5;
	}
}

int Board::getWidth() const
{
	return m_nBoardWidth;
}

int Board::getHeight() const
{
	return m_nBoardHeight;
}


Board* Board::board = NULL;
