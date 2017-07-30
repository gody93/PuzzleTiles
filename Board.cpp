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

SDL_Rect Board::getPos()
{
	return this->boardPos;
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

	SDL_BlitSurface(Tile::getTile()->getSurface(), NULL, boardBackground, NULL);

	return this->boardBackground;
}

// void Board::fillBoard()
// {
// //	Tile::getTile()->getTileSurface();
// }

int Board::getBoardWidth() const
{
	return m_nBoardWidth;
}

int Board::getBoardHeight() const
{
	return m_nBoardHeight;
}


Board* Board::board = NULL;
