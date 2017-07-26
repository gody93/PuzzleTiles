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

SDL_Rect Board::getBoardPos()
{
	return boardPos;
}

SDL_Surface* Board::getBoardSurface()
{
	this->boardBackground = SDL_CreateRGBSurface(0, m_nBoardHeight, m_nBoardWidth, 32, 0, 0, 0, 0);

	SDL_FillRect(boardBackground , NULL, SDL_MapRGB(boardBackground->format, 255, 255, 0));

	SDL_BlitSurface(Cube::getTile()->getTileSurface(), NULL, boardBackground, NULL);

	return this->boardBackground;
}

void Board::fillBoard()
{
	Cube::getTile()->getTileSurface();
}

Board* Board::board = NULL;
