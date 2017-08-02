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

	// delete tile;
	// tile = NULL;
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
	return boardPos;
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

	SDL_Rect blitDest;// = getPos();
	blitDest.x = boardPos.x + 30;
	blitDest.y = boardPos.y + 30;

	tile->setPos(blitDest.x, blitDest.y);
	SDL_BlitSurface(tile->getSurface(), NULL, boardBackground, &blitDest);


	// for( int i = 0; i <= bRows; i++)
	// {
	// 	for( int j = 0; j <= bCols; j++)
	// 	{
	// 		SDL_BlitSurface(playBoard[i][j].getSurface(), NULL, boardBackground, &blitDest);
	// 		blitDest.x += tile.getWidth();
	// 	}
	// 	blitDest.y += tile.getHeight() + 5;
	// }
}

int Board::getWidth() const
{
	return m_nBoardWidth;
}

int Board::getHeight() const
{
	return m_nBoardHeight;
}

Tile* Board::getTile()
{
	return tile;
}

Board* Board::board = NULL;
